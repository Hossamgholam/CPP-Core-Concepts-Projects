#pragma once
#include"iostream"
#include"iomanip"
using namespace std;
#include"0_clsScreen.h"
#include"clsUser.h"

class clsUserListScreen:protected clsScreen
{
private:
	static void _printUserRecordLine(clsUser& user) {
		cout
			<< "|" << setw(15) << user.fristName
			<< "|" << setw(10) << user.lastName
			<< "|" << setw(40) << user.email
			<< "|" << setw(12) << user.phone
			<< "|" << setw(15) << user.userName
			<< "|" << setw(10) << user.password
			<< "|" << setw(10) << user.permission;
		
	}

public:
	static void showUserList() {
		vector<clsUser>vUser = clsUser::getUsersList();
		string title = "user list screen";
		string subtitle = "                               list of (" + to_string(vUser.size()) + ") users";
		_drawScreenHeader(title, subtitle);

		cout << "_________________________________________________________________________________________________________________________________\n";
		cout << 
			"|" << setw(15) << "frist Name" <<
			"|" << setw(10) << "last name" <<
			"|" << setw(40) << "email " <<
			"|" << setw(12) << "phone" <<
			"|" << setw(15) << "name" << 
			"|" << setw(10) << "password"<<
			"|" << setw(10) << "permsion" << endl;
		cout << "__________________________________________________________________________________________________________________________________\n";
		if (vUser.empty()) {
			cout << "number of user is 0\nthere is not user in date base\n";
		}
		else {
			for ( clsUser& user : vUser) {
				_printUserRecordLine(user);
				cout << endl;
			}
		}
		cout << "_________________________________________________________________________________________________________________________________\n";
	}
};

