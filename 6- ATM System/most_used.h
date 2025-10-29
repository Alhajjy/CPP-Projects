#pragma once
#include <iostream>
#include <vector>
#include "global.h"
using namespace std;
using namespace GlobalVars;

namespace MostUsed {
    void PauseProgram() {
        cout << "\nPress Enter to go back...";
        cin.ignore();
        cin.get();
    }
    bool VerifyDecision(string Message) {
        bool bl = false;
        cout << "Are You Sure To " << Message << " (0, 1):" << endl;
        cin >> bl;
        return bl;
    }
    short ChooseOperation(short min, short max) {
        short num = 0;
        do {
            cout << "\nChoose What do you want to do?" << endl;
            cin >> num;
        } while (num < min || num > max);
        return num;
    }
    void waitForEnter(string message) {
        cout << "\n" << message << endl;
        cin.ignore();
        cin.get();
    }
    string AskClientNumber(string Message) {
        string EnteredNumber;
        cout << Message;
        cin >> EnteredNumber;
        return EnteredNumber;
    }
    vector <string> SplitString(string Text) {
        vector <string> vWords;
        int pos = 0;
        string sWord;
        while ((pos = Text.find(Seperator)) != std::string::npos) {
            sWord = Text.substr(0, pos);
            if (sWord != "")
                vWords.push_back(sWord);
            Text.erase(0, pos + Seperator.length());
        }
        if (Text != "")
            vWords.push_back(Text);
        return vWords;
    }

    string PrintRecordInLine(stClient item) {
        string itemRecord;
        itemRecord += item.AccountNumber + Seperator;
        itemRecord += item.PinCode + Seperator;
        itemRecord += item.Name + Seperator;
        itemRecord += item.Phone + Seperator;
        itemRecord += to_string(item.AccountBalance);
        return itemRecord;
    }

    bool FindClientByNumber(vector <stClient> vcClient, string EnteredNumber) {
        for (stClient C : vcClient) {
            if (EnteredNumber == C.AccountNumber) {
                return 1;
            }
        }
        return 0;
    }
    void PrintHeader(string Header) {
        cout << "--------------------------------------" << endl;
        cout << "\t   " << Header << endl;
        cout << "--------------------------------------" << endl;
    }
    void PrintRecord(stClient item) {
        cout << "\nClient:\n";
        cout << "\nClient Number:  " << item.AccountNumber;
        cout << "\nPinCode:  " << item.PinCode;
        cout << "\nName:  " << item.Name;
        cout << "\nPhone:  " << item.Phone;
        cout << "\nAccount Balance:  " << item.AccountBalance;
        cout << "\n--------------------------------" << endl;
    }

    stClient ReadClientData(vector <stClient> vcClient, string AccountNumber = "", bool SkipAccountNumber = 0) {
        stClient Client;
        string EnteredNumber;
        if (SkipAccountNumber == 0) {
            cout << "Client UNIQE Number? ";
            getline(cin >> ws, EnteredNumber);
            while (FindClientByNumber(vcClient, EnteredNumber)) {
                cout << "This Number is Exist! Try Another one.." << endl;
                getline(cin >> ws, EnteredNumber);
            };
            Client.AccountNumber = EnteredNumber;
        }
        else {
            Client.AccountNumber = AccountNumber;
        }
        cout << "Pin Code?  ";
        getline(cin >> ws, Client.PinCode);
        cout << "Name?  ";
        getline(cin, Client.Name);
        cout << "phone?  ";
        getline(cin, Client.Phone);
        cout << "Client Balance?  ";
        cin >> Client.AccountBalance;
        cout << "---------\n";
        return Client;
    }



    stClient ConvertLineToRecord(string Line) {
        stClient item;
        vector <string> vitem;
        vitem = SplitString(Line);
        item.AccountNumber = vitem[0] != "" ? vitem[0] : " ";
        item.PinCode = vitem[1] != "" ? vitem[1] : " ";
        item.Name = vitem[2] != "" ? vitem[2] : " ";
        item.Phone = vitem[3] != "" ? vitem[3] : " ";
        item.AccountBalance = stoi(vitem[4]);
        return item;
    }
    vector <stClient> LoaditemsDataFromFile(string FileName) {
        vector <stClient> vcClient;
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        if (MyFile.is_open()) {
            string line;
            stClient item;
            while (getline(MyFile, line)) {
                item = ConvertLineToRecord(line);
                vcClient.push_back(item);
            }
            MyFile.close();
        }
        return vcClient;
    }
    void SaveVectorDataToFile(vector <stClient> vcClient) {
        fstream MyFile;
        MyFile.open(CFile, ios::out);
        if (MyFile.is_open()) {
            string DataLine;
            for (short i = 0; i < vcClient.size(); i++) {
                DataLine = PrintRecordInLine(vcClient[i]);
                MyFile << DataLine;
                if (i != vcClient.size() - 1)
                    MyFile << endl;
            }
        }
        MyFile.close();
        cout << "___________________________________________________________\n";
    }
}