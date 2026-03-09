#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
#include"0_clsScreen.h"
#include"clsUser.h"
#include"8_clsLogInRegisterScreen.h"

class clsLogInRegisterScreen:protected clsScreen
{
private:
	static void printLogInRegisterRecord(clsUser::stLogInRegisterRecord logInRegisterRecord){
		cout << "\t\t\t|" << left << setw(20) << logInRegisterRecord.dateTime << "|" << setw(15) << logInRegisterRecord.userName
			<< "|" << setw(15) << logInRegisterRecord.password << "|" << setw(15) << logInRegisterRecord.permesion;
			
	}

public:
	static void showLogInRegisterScreen() {
		if (!checkAccessRights(clsUser::enMangeuserPermission::pLogInRegister)) {
			return ;
		}
		vector<clsUser::stLogInRegisterRecord> vlogInRegisterRecords;
		vlogInRegisterRecords = clsUser::getLogInRegisterList();

		string title = "login register list screen";
		string subTilte = "\t\t\t\tregister list (" + to_string(vlogInRegisterRecords.size()) +
			")recodes";

		_drawScreenHeader(title, subTilte);

		cout << "\t\t\t______________________________________________________________________\n";
		cout << "\t\t\t|" <<left<< setw(20) << "Date/time" << "|" << setw(15) << "user name"
			 << "|" << setw(15) << "password " << "|" << setw(15) << "permission"
			 << "|\n";
		cout << "\t\t\t______________________________________________________________________\n";

		if (vlogInRegisterRecords.empty()) {
			cout << "there is no records\n";
			
		}
		else {
			for (clsUser::stLogInRegisterRecord record : vlogInRegisterRecords) {
				 printLogInRegisterRecord(record);
				cout << endl;
			}
			cout << "\t\t\t______________________________________________________________________\n";
		}
	}
};

