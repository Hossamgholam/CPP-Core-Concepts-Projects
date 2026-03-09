#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"1_clsMainScreen.h"
#include"clsUser.h"
#include"global.h"
class clsShowLoginScreen:protected clsScreen
{
private:
	static bool _logIn() {
		bool logInFail = false;
		short failLoginCount =0 ;
		string username, password;
		do {
			if (logInFail) {
				failLoginCount++;
				cout << "\n\n\n\t\t\t\t\tinvalid username/password\n\a";
				cout << "\t\t\t\t\tyou have " <<3-failLoginCount << " trials to log in\n\n";
			}
			if (failLoginCount == 3) {
				cout << "\t\t\t\t\t you are faild aftare 3 trial";
				return false;
			}
			cout << "\t\t\t\t\tpleas inter user name:"; cin >> username;
			cout << "\t\t\t\t\tplease inter password:"; cin >> password;

			 currentUser = clsUser::find(username, password);

			 logInFail = currentUser.isEmpty();

		} while (logInFail);
		//to save user login info in logfille
		currentUser.registerLogIn();

		clsMainScreen::showMainMneue();
		return true;

	}
public:
	static bool showLogInScreen() {
		 system("cls");
		_drawScreenHeader("log in screen");
		return _logIn();
	}
};

