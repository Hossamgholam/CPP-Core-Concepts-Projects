#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"clsUser.h"
#include"clsIputValiDate.h"
class clsFindUserScreen:protected clsScreen
{
private:
    static void _print(clsUser& user) {
        cout << "\n client carde\n";
        cout << "------------------------------\n";
        cout << "\nfristName   :" << user.fristName;
        cout << "\nlastName    :" << user.lastName;
        cout << "\nfullName    :" << user.fullName();
        cout << "\nemail       :" << user.email;
        cout << "\nphone       :" << user.phone;
        cout << "\nUser name   :" << user.userName;
        cout << "\nPassword    :" << user.password;
        cout << "\npermission  :" << user.permission;
    }
public:
    static void showFindUserScreen() {
        _drawScreenHeader("delete User screen:");
        cout << "pleas inter user name:";
        string userName = clsIputValiDate::readString();
        while (!clsUser::isUserExist(userName)) {
            cout << "user not exsit:pleas inter another user name:";
            userName = clsIputValiDate::readString();
        }

        clsUser user = clsUser::find(userName);
        if (user.isEmpty()) {
            cout << "user is not founc(-:\n";
        }
        else {
            cout << "user is found-):\n";
        }
        _print(user);

    }
};

