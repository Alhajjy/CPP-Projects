#include <fstream>   // For file stream operations (ifstream, ofstream)
#include <iomanip>   // For output formatting (setw, setprecision, etc.)
#include <iostream>  // For standard input/output (cin, cout)
#include <string>    // For string class and string operations
#include <vector>    // For dynamic array implementation (vector container)

using namespace std;

/* GLOBAL VARIBALES */
const string FileName = "file.txt";
const string Seperator = "__||__";
void PauseProgram() {
  cout << "\nPress Enter to go back...";
  cin.ignore();
  cin.get();
}
/* MOST USED */
struct stClient {
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  int AccountBalance;
};
bool VerifyDecision(string Message) {
  bool bl = false;
  cout << "Are You Sure To " << Message << " (0, 1):" << endl;
  cin >> bl;
  return bl;
}
vector<string> SplitString(string Text) {
  vector<string> vWords;
  int pos = 0;
  string sWord;
  while ((pos = Text.find(Seperator)) != std::string::npos) {
    sWord = Text.substr(0, pos);
    if (sWord != "") vWords.push_back(sWord);
    Text.erase(0, pos + Seperator.length());
  }
  if (Text != "") vWords.push_back(Text);
  return vWords;
}
stClient ConvertLineToRecord(string Line) {
  stClient item;
  vector<string> vitem;
  vitem = SplitString(Line);
  item.AccountNumber = vitem[0] != "" ? vitem[0] : " ";
  item.PinCode = vitem[1] != "" ? vitem[1] : " ";
  item.Name = vitem[2] != "" ? vitem[2] : " ";
  item.Phone = vitem[3] != "" ? vitem[3] : " ";
  item.AccountBalance = stoi(vitem[4]);
  return item;
}
vector<stClient> LoaditemsDataFromFile(string FileName) {
  vector<stClient> vcClient;
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
string PrintRecordInLine(stClient item) {
  string itemRecord;
  itemRecord += item.AccountNumber + Seperator;
  itemRecord += item.PinCode + Seperator;
  itemRecord += item.Name + Seperator;
  itemRecord += item.Phone + Seperator;
  itemRecord += to_string(item.AccountBalance);
  return itemRecord;
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
void SaveVectorDataToFile(vector<stClient> vcClient) {
  fstream MyFile;
  MyFile.open(FileName, ios::out);
  if (MyFile.is_open()) {
    string DataLine;
    for (short i = 0; i < vcClient.size(); i++) {
      DataLine = PrintRecordInLine(vcClient[i]);
      MyFile << DataLine;
      if (i != vcClient.size() - 1) MyFile << endl;
    }
  }
  MyFile.close();
  cout << "___________________________________________________________\n";
}
bool FindClientByNumber(vector<stClient> vcClient, string EnteredNumber) {
  for (stClient C : vcClient) {
    if (EnteredNumber == C.AccountNumber) {
      return 1;
    }
  }
  return 0;
}
stClient ReadClientData(vector<stClient> vcClient, string AccountNumber = "",
                        bool SkipAccountNumber = 0) {
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
  } else {
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
};
string AskClientNumber(string Message) {
  string EnteredNumber;
  cout << Message;
  cin >> EnteredNumber;
  return EnteredNumber;
}
void PrintHeader(string Header) {
  cout << "--------------------------------------" << endl;
  cout << "\t   " << Header << endl;
  cout << "--------------------------------------" << endl;
}
short ChooseOperation(short min, short max) {
  short num = 0;
  do {
    cout << "\nChoose What do you want to do?" << endl;
    cin >> num;
  } while (num < min || num > max);
  return num;
}
/* OPERATOINS */
// show all 1
void HandleTableHeader() {
  cout << setw(30) << "Clients:\n";
  cout << "===================================================================="
          "===================\n";
  cout << setw(15) << "Account Number" << " | ";
  cout << setw(10) << "Pin Code" << " | ";
  cout << setw(20) << "Name" << " | ";
  cout << setw(13) << "Phone" << " | ";
  cout << setw(5) << "Account Balance" << endl;
  cout << "===================================================================="
          "===================\n";
}
void HandleLineContent(string Line) {
  vector<string> vWords = SplitString(Line);
  cout << setw(15) << vWords[0] << " | ";
  cout << setw(10) << vWords[1] << " | ";
  cout << setw(20) << vWords[2] << " | ";
  cout << setw(13) << vWords[3] << " | ";
  cout << setw(5) << vWords[4] << endl;
}
void HandleTableContent(vector<stClient> vcClient) {
  for (stClient C : vcClient) {
    HandleLineContent(PrintRecordInLine(C));
  }
  cout << "===================================================================="
          "===================\n";
}
void ShowAllClients(vector<stClient> vcClient) {
  HandleTableHeader();
  HandleTableContent(vcClient);
}
// create 2
void AddClient(string Payload) {
  fstream MyFile;
  vector<stClient> vcTempClient = LoaditemsDataFromFile(FileName);
  MyFile.open(FileName, ios::out | ios::app);

  if (MyFile.is_open()) {
    if (vcTempClient.size() != 0) {
      MyFile << "\n";
    }
    MyFile << Payload;
  }
  MyFile.close();
}
void AddClients(vector<stClient> vcClient) {
  PrintHeader("Add New Client");
  bool again = 1;
  while (again) {
    system("cls");
    AddClient(PrintRecordInLine(ReadClientData(vcClient)));
    cout << "Client Record Saved Successfully\n";
    cout << "Do you want to add another Client? (1, 0): ";
    cin >> again;
  }
  cout << "=========================================\n";
}
/*
    delete 3
*/
void DeleteClient(vector<stClient> vcClient) {
  PrintHeader("Delete Client");
  vector<stClient> CopyvcClient;
  string EnteredNumber =
      AskClientNumber("Enter the Client Accout Number to Delete..  ");
  // search
  if (FindClientByNumber(vcClient, EnteredNumber)) {
    // delete
    for (stClient C : vcClient) {
      if (C.AccountNumber != EnteredNumber) {
        CopyvcClient.push_back(C);
      }
    }
    // save to file
    SaveVectorDataToFile(CopyvcClient);
    cout << "Deleted Successfully!\n";
  } else {
    cout << "Client Not Found!" << endl;
  }
}
/*
    update 4
*/
void UpdateClient(vector<stClient> vcClient) {
  PrintHeader("Update Client");
  vector<stClient> CopyvcClient;
  bool again = true;
  do {
    string EnteredNumber =
        AskClientNumber("Enter a client number to update..  ");
    // search
    if (FindClientByNumber(vcClient, EnteredNumber)) {
      // update
      for (stClient C : vcClient) {
        if (EnteredNumber == C.AccountNumber) {
          PrintRecord(C);
          if (VerifyDecision("Update This Client?")) {
            CopyvcClient.push_back(ReadClientData(vcClient, EnteredNumber, 1));
            cout << "Updated Successfully!" << endl;
          } else {
            CopyvcClient.push_back(C);
            cout << "Ok man:)" << endl;
          }
          again = false;
        } else {
          CopyvcClient.push_back(C);
        }
      }
      SaveVectorDataToFile(CopyvcClient);
    } else {
      cout << "Client Not Found, Try to write Number it again!" << endl;
    }
  } while (again);
}
/*
    search 5
*/
bool SearchPlaylist(vector<stClient> vcClient) {
  PrintHeader("Search Client");
  bool again = true;
  while (again) {
    string EnteredNumber =
        AskClientNumber("Enter a Client number to search..  ");
    for (stClient C : vcClient) {
      if (EnteredNumber == C.AccountNumber) {
        cout << "Client is Exist:" << endl;
        PrintRecord(C);
        cout << endl;
        return 0;
      }
    }
    cout << "Client with " << EnteredNumber
         << " doesn`t exist! Want to Try again? (0, 1)" << endl;
    cin >> again;
  }
  return 1;
}
/*
    transactions 6
*/
enum TransactionOptions {
  enDeposite = 1,
  enWithdraw = 2,
  enTotalBalance = 3,
  enBack = 4,
};
void DipositeOrWithdraw(vector<stClient> &vcClient,
                        bool DipositeOrWithdraw = 1) {
  PrintHeader(DipositeOrWithdraw == 1 ? "Diposite" : "Withdraw");
  string EnteredNumber;
  int Amount = 0;
  string Message;
  do {
    Message = DipositeOrWithdraw == 1
                  ? "Enter an Account Number to Deposite.. "
                  : "Enter an Account Number to Withdraw.. ";
    EnteredNumber = AskClientNumber(Message);
  } while (!FindClientByNumber(vcClient, EnteredNumber));

  for (stClient &C : vcClient) {
    if (C.AccountNumber == EnteredNumber) {
      PrintRecord(C);
      cout << "Enter Amount: ";
      cin >> Amount;
      DipositeOrWithdraw == 1
          ? VerifyDecision("Diposite " + to_string(C.AccountBalance) + " to " +
                           to_string(C.AccountBalance + Amount))
          : VerifyDecision("Withdraw " + to_string(C.AccountBalance) + " to " +
                           to_string(C.AccountBalance - Amount));
      if (DipositeOrWithdraw == 1)
        C.AccountBalance += Amount;
      else
        C.AccountBalance -= Amount;
      cout << "\n\nDone Successfully.." << endl;
      PrintRecord(C);
    }
    break;
  }
  SaveVectorDataToFile(vcClient);
}
void TotalBalance(vector<stClient> vcClient) {
  int Total = 0;
  for (stClient C : vcClient) {
    Total += C.AccountBalance;
  }
  PrintHeader("Total Balance");
  cout << "The Total Balance is: " << Total << endl;
}
void TransationsMenu() {
  PrintHeader("Transactioins");
  cout << "[1] Diposite" << endl;
  cout << "[2] Withdraw" << endl;
  cout << "[3] Total Balance" << endl;
  cout << "[4] Back.." << endl;
  cout << "--------------------------------------" << endl;
}
void HandleTransaction(vector<stClient> &vcClient, short variable,
                       bool &BackFlag) {
  system("cls");
  switch (variable) {
    case TransactionOptions::enDeposite:
      DipositeOrWithdraw(vcClient, 1);
      break;
    case TransactionOptions::enWithdraw:
      DipositeOrWithdraw(vcClient, 0);
      break;
    case TransactionOptions::enTotalBalance:
      TotalBalance(vcClient);
      break;
    case TransactionOptions::enBack:
      BackFlag = true;
      return;
    default:
      cout << "Invalid option!" << endl;
  }
}
void Transactions(vector<stClient> &vcClient) {
  bool Back = false;
  TransationsMenu();
  HandleTransaction(vcClient, ChooseOperation(1, 4), Back);
}
/* MAIN */
enum MenuOptions {
  enShowClientList = 1,
  enAddNewClient = 2,
  enDeleteClient = 3,
  enUpdateClient = 4,
  enFindClient = 5,
  enTransactions = 6,
  enExit = 7
};
void MainMenuScreen(vector<stClient> vcClient) {
  system("cls");
  cout << "======================================" << endl;
  cout << "           Main Menu Screen           " << endl;
  cout << "======================================" << endl;
  cout << "[1] Show Client List" << endl;
  cout << "[2] Add New Client" << endl;
  cout << "[3] Delete Client" << endl;
  cout << "[4] Update Client" << endl;
  cout << "[5] Find Client" << endl;
  cout << "[6] Transactions" << endl;
  cout << "[7] Exit" << endl;
  cout << "======================================" << endl;
}
void HandleOperation(vector<stClient> &vcClient, short variable,
                     bool &ExitFlag) {
  system("cls");
  switch (variable) {
    case MenuOptions::enShowClientList:
      ShowAllClients(vcClient);
      break;
    case MenuOptions::enAddNewClient:
      AddClients(vcClient);
      break;
    case MenuOptions::enDeleteClient:
      DeleteClient(vcClient);
      break;
    case MenuOptions::enUpdateClient:
      UpdateClient(vcClient);
      break;
    case MenuOptions::enFindClient:
      SearchPlaylist(vcClient);
      break;
    case MenuOptions::enTransactions:
      Transactions(vcClient);
      break;
    case MenuOptions::enExit:
      ExitFlag = true;
      return;
    default:
      cout << "Invalid option!" << endl;
  }
  PauseProgram();
}
// APP
void App() {
  vector<stClient> vcClient = LoaditemsDataFromFile(FileName);
  bool ExitProgram = false;
  do {
    MainMenuScreen(vcClient);
    HandleOperation(vcClient, ChooseOperation(1, 7), ExitProgram);
  } while (!ExitProgram);
}
int main() {
  App();
  return 0;
}