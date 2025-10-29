#pragma once
#include <iostream>
using namespace std;


namespace GlobalVars {
    const string CFile = "clients.txt";
    const string Seperator = "__||__";
    struct stClient {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        int AccountBalance;
    };
    stClient CurrentClient;
}