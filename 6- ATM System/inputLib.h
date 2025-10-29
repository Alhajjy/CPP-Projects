#pragma once
#include <iostream>
using namespace std;

namespace Inputs {
    int ReadNumber(string Message) {
        int num = 0;
        cout << Message << endl;
        cin >> num;
        return num;
    }
    int ReadPozitifNumber(string Message) {
        float Number = 0;
        do {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }
    int RandomNumber(int From, int To) {
        return rand() % (To - From + 1) + From;
    }
    string  ReadString(string Message) {
        string Text;
        cout << Message << endl;
        getline(cin, Text);
        return Text;
    }
    char  ReadChar() {
        cout << "Write a Letter" << endl;
        char Letter;
        cin >> Letter;
        return Letter;
    }
}