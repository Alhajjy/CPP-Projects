#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "global.h"
#include "inputLib.h"
#include "most_used.h"
#include "operations.h"
using namespace Inputs;
using namespace std;
using namespace MostUsed;
using namespace Operations;

/* MAIN */
enum MenuOptions {
  enQuickWithdraw = 1,
  enWithdraw = 2,
  enDiposite = 3,
  enCheckBalance = 4,
  enLogout = 5,
};
void MainMenuScreen() {
  system("cls");
  cout << "======================================" << endl;
  cout << "           Main Menu Screen           " << endl;
  cout << "======================================" << endl;
  cout << "[1] Quick Withdraw" << endl;
  cout << "[2] Withdraw" << endl;
  cout << "[3] Diposite" << endl;
  cout << "[4] Check Balance" << endl;
  cout << "[5] Log out" << endl;
  cout << "======================================" << endl;
}
void HandleOperation(vector<stClient>& vcClient, short variable,
                     bool& ExitFlag) {
  system("cls");
  switch (variable) {
    case MenuOptions::enQuickWithdraw:
      QuickWithdraw();
      break;
    case MenuOptions::enWithdraw:
      Withdraw();
      break;
    case MenuOptions::enDiposite:
      Deposite();
      break;
    case MenuOptions::enCheckBalance:
      CheckBalance();
      break;
    case MenuOptions::enLogout:
      ExitFlag = true;
      return;
    default:
      cout << "Invalid option!" << endl;
  }
}
// APP
void App() {
  bool ExitProgram = false;
  do {
    MainMenuScreen();
    HandleOperation(vcClients, ChooseOperation(1, 5), ExitProgram);
  } while (!ExitProgram);
}
// Login
bool Is_Name_Password_True(stClient& Client) {
  for (stClient C : vcClients) {
    if (Client.AccountNumber == C.AccountNumber &&
        Client.PinCode == C.PinCode) {
      Client = C;
      CurrentClient = Client;
      return true;
    }
  }
  return false;
}
void Login() {
  bool log = false;
  stClient Client;
  do {
    Client.AccountNumber = ReadString("Enter Your Account Number!");
    Client.PinCode = ReadString("Enter Password!");
    if (Is_Name_Password_True(Client)) {
      App();
      log = true;
    } else {
      cout << "Username/ password wrong, try again..\n";
    }
  } while (!log);
}
int main() {
  Login();
  return 0;
}