#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
#include"0_clsScreen.h"
#include"clsBankClient.h"
class clsTransferLogScreen:protected clsScreen
{
private:
	static void printTransferLogRecord(clsBankClient::stTransferLogRecord transferLogRecord) {
		cout << "\t\t\t|" << left << setw(20) << transferLogRecord.dateTime << "|" << setw(8) << transferLogRecord.sourceAccount
			<< "|" << setw(8) << transferLogRecord.distinationAccount << "|" << setw(10) << transferLogRecord.amount
			<< "|" << setw(10) << transferLogRecord.sourceAcounntBalance << "|" << setw(10) << transferLogRecord.distinationAccountBalance
			<< "|" << setw(8) << transferLogRecord.userName<<"|";

	}
public:
	static void showTransferLogScreen() {
		vector<clsBankClient::stTransferLogRecord>vTransferLogRecord;
		vTransferLogRecord = clsBankClient::getTransferLogList();
		
		string title = "transfer log list screen";
		string subTilte = "\t\t\t\t\t(" + to_string(vTransferLogRecord.size()) + ") records";
		_drawScreenHeader(title, subTilte);

		cout << "\t\t\t_________________________________________________________________________________\n";
		cout << "\t\t\t|" << left << setw(20) << "Date/time" << "|" << setw(8) << "s.acc"
			<< "|" << setw(8) << "d.acc " << "|" << setw(10) << "amount"
			<<"|"<<setw(10)<<"s.ballance"<<"|"<<setw(10)<<"d.balance"
			<<"|"<<setw(8)<<"userName"
			<< "|\n";
		cout << "\t\t\t_________________________________________________________________________________\n";

		if (vTransferLogRecord.empty()) {
			cout << "there is no records\n";

		}
		else {
			for (clsBankClient::stTransferLogRecord record : vTransferLogRecord) {
				printTransferLogRecord(record);
				cout << endl;
			}
			cout << "\t\t\t________________________________________________________________________________\n";
		}
	}
};

