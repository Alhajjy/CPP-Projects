#pragma once
#include <iostream>
#include "inputLib.h"
#include "most_used.h"
using namespace std;
using namespace Inputs;
using namespace MostUsed;

namespace Operations {
	enum eQuickWithdraw {
		w_5 = 1, w_10, w_50, w_100, w_200, w_500, w_800, w_1000
	};
	vector <stClient> vcClients = LoaditemsDataFromFile(CFile);
	void QuickWithdrawScreen() {
		PrintHeader("Quick Withdraw");
		cout << "[1] 5  \t [2] 10" << endl;
		cout << "[3] 50 \t [4] 100" << endl;
		cout << "[5] 200\t [6] 500" << endl;
		cout << "[7] 800\t [8] 1000" << endl;
		cout << "--------------------------------------" << endl;
	}
	void DipositeOrWithdraw(int Amount, bool DipositeOrWithdraw = 1) {
		for (stClient& C : vcClients) {
			if (C.AccountNumber == CurrentClient.AccountNumber) {
				PrintRecord(C);
				DipositeOrWithdraw == 1
					? VerifyDecision("Diposite " + to_string(C.AccountBalance) + " to " + to_string(C.AccountBalance + Amount))
					: VerifyDecision("Withdraw " + to_string(C.AccountBalance) + " to " + to_string(C.AccountBalance - Amount));
				if (DipositeOrWithdraw == 1)
					C.AccountBalance += Amount;
				else
					C.AccountBalance -= Amount;
				PrintRecord(C);
				CurrentClient = C;
				waitForEnter("Done Successfully");
				break;
			}
		}
		SaveVectorDataToFile(vcClients);
	}
	void HandleTransaction(short variable) {
		system("cls");
		QuickWithdrawScreen();
		switch (variable) {
		case eQuickWithdraw::w_5:
			DipositeOrWithdraw(5);
			break;
		case eQuickWithdraw::w_10:
			DipositeOrWithdraw(10);
			break;
		case eQuickWithdraw::w_50:
			DipositeOrWithdraw(50);
			break;
		case eQuickWithdraw::w_100:
			DipositeOrWithdraw(100);
			break;
		case eQuickWithdraw::w_200:
			DipositeOrWithdraw(200);
			break;
		case eQuickWithdraw::w_500:
			DipositeOrWithdraw(500);
			break;
		case eQuickWithdraw::w_800:
			DipositeOrWithdraw(800);
			break;
		case eQuickWithdraw::w_1000:
			DipositeOrWithdraw(1000);
			break;
		default:
			cout << "Invalid option!" << endl;
		}
	}
	void QuickWithdraw() {
		QuickWithdrawScreen();
		HandleTransaction(ChooseOperation(1, 8));
	}
	void Withdraw() {
		PrintHeader("Withdraw");
		DipositeOrWithdraw(ReadPozitifNumber("Enter amount to withdraw"));
	}
	void Deposite() {
		PrintHeader("Deposite");
		DipositeOrWithdraw(ReadPozitifNumber("Enter amount to Deposite"), 0);
	}
	void CheckBalance() {
		int Total = 0;
		Total = CurrentClient.AccountBalance;
		PrintHeader("Total Balance");
		cout << "The Total Balance is: ";
		waitForEnter(to_string(Total));
	}
}