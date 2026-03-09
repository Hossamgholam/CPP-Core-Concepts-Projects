#pragma once
#include"iostream"
using namespace std;
#include"clsIputValiDate.h"
#include"0_clsScreen.h"

class clsShowTransferScreen:protected clsScreen
{
private:
	static string _readAccountNumber() {
		cout << "pleas inter Account Number To Transfer From:";
		string accuntNumberTransferFrom = clsIputValiDate::readString();
		while (!clsBankClient::isClientExist(accuntNumberTransferFrom)) {
			cout << "client not exsit:pleas inter another account number:";
			accuntNumberTransferFrom = clsIputValiDate::readString();
		}
		return accuntNumberTransferFrom;
	}
	static void _printClientCard(clsBankClient& client) {
		cout << "\n client carde\n";
		cout << "------------------------------\n";
		cout << "\nfullName    :" << client.fullName();
		cout << "\nacc. number :" << client.accountNumber;
		cout << "\naccounfBalan:" << client.accountBalance;
		cout << "\n------------------------------\n";
	}
	static double _readAmount(clsBankClient& sourceClient) {
		double amount;
		cout << "enter transfer amount:";
		amount = clsIputValiDate::readDouble("pleas inter floating number;\n");

		while (amount > sourceClient.accountBalance) {
			cout << "amount exceeds the balance you can withdraw up to  :" << sourceClient.accountBalance << endl;
			cout << "\nplease inter another amount:";
			amount = clsIputValiDate::readDouble("pleas inter floating number;\n");
		}
		return amount;
	}
public:
	static void showTransferScreen(){
		_drawScreenHeader("transfer screen");
		

		clsBankClient sourceClient = clsBankClient::find(_readAccountNumber());
		_printClientCard(sourceClient);

		clsBankClient destinationClient = clsBankClient::find(_readAccountNumber());
		_printClientCard(destinationClient);


		double amount=_readAmount(sourceClient);
		
		char answer = 'y';
		cout << "\nare you sure you want to deposit account:";
		cin >> answer;

		if (toupper(answer) == 'Y') {
			if (sourceClient.transfer(amount, destinationClient,currentUser.userName)) {

			cout << "transfer don scussfully\n";
			_printClientCard(sourceClient);
			_printClientCard(destinationClient);
			}
			else {
				cout << "some thing wrong in transfer\n";
			}
			
		}
		else {
			cout << "operation was cancelled\n";
		}

		
	}
};

