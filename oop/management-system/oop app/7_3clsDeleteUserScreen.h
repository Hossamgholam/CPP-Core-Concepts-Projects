#pragma once
#include<iostream>
using namespace std;
#include"clsIputValiDate.h"
#include"0_clsScreen.h"
#include"clsUser.h"
class clsDeleteUserScreen:protected clsScreen
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
    static void showdeleteUserScreen() {
        
        _drawScreenHeader("delete USer screen:");
        cout << "pleas inter User name:";
        string username = clsIputValiDate::readString();
        while (!clsUser::isUserExist(username)) {
            cout << "User not exsit:pleas inter another USer name:";
            username = clsIputValiDate::readString();
        }

        clsUser User = clsUser::find(username);

        _print(User);

        char answer = 'y';
        cout << "\nare your sure you what to delete:"; cin >> answer;
        if (toupper(answer) == 'Y') {

            if (User.Delete()) {
                cout << "\nUser delted successful:-):\n";
                _print(User);
            }
            else {
                cout << "\n error client was not deleted\n";
            }
        }
        else {
            cout << "cansel operation\n";
        }

    }
};

