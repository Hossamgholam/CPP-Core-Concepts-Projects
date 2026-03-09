#pragma once
#include<iostream>
using namespace std;
#include"clsIputValiDate.h"
#include"0_clsScreen.h"
#include"clsUser.h"
class clsAddNewUserScreen:protected clsScreen
{
private:
    static  int readPermissionToSet() {
        char answer = 'y';
        int permission = 0;

        cout << "\ndo you want to give full acess:"; cin >> answer;
        if (toupper(answer) == 'Y') {
            permission = -1;
            return permission;
        }
        else {
            cout << "\ndo you want to give acess to:\n";

            cout << "\nshow client list y/n:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pShowClientList;
            }

            cout << "\nadd client screen:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pAddClient;

            }

            cout << "\ndelete client screen:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pDeleteClient;

            }

            cout << "\nupdate client screen:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission +clsUser::enMangeuserPermission::pUpdateClient;

            }
            cout << "\nfind client screen:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pFindClient;

            }
            cout << "\ntransaction client screen:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pTransactionMenue;

            }
            cout << "\nmange user screen:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pMangeUser;

            }
            //extintion 5
            cout << "\nlog in register:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pLogInRegister;
            }
            return permission;
        }
    }
    static void _readUserInfo(clsUser& User) {
        cout << "\nenter frist name:";
        User.fristName = clsIputValiDate::readString();

        cout << "\nenter last name:";
        User.lastName = clsIputValiDate::readString();

        cout << "\nenter email:";
        User.email = clsIputValiDate::readString();

        cout << "\nenter phone:";
        User.phone = clsIputValiDate::readString();

        cout << "\nenter password:";
        User.password = clsIputValiDate::readString();

        cout << "\nenter permission:";
        User.permission = readPermissionToSet();
    }

    static void _print(clsUser& user) {
        cout << "\n client carde\n";
        cout << "------------------------------\n";
        cout << "\nfristName   :" << user.fristName;
        cout << "\nlastName    :" << user.lastName;
        cout << "\nfullName    :" << user.fullName();
        cout << "\nemail       :" << user.email;
        cout << "\nphone       :" << user.phone;
        cout << "\nuser name   :" << user.userName;
        cout << "\npassword    :" << user.password;
        cout << "\npermision    :" << user.permission;
    }
public:
    static void showAddNewUserScreen() {
      
        _drawScreenHeader("add new user screen");
        cout << "pleas inter user name:";
        string userName = clsIputValiDate::readString();
        //level one securtiy
        while (clsUser::isUserExist(userName)) {
            cout << "client  exsit:pleas inter another user naem:";
            userName = clsIputValiDate::readString();
        }
        clsUser newUser = clsUser::getAddNewUserObject(userName);
        _readUserInfo(newUser);

        clsUser::enSaveResult saveResult;
        saveResult = newUser.save();

        switch (saveResult)
        {
        case clsUser::enSaveResult::svScusseded:
            cout << "\n account add successfully:-)\n";
            _print(newUser);
            break;
        case clsUser::enSaveResult::svFaildEmptyObject:
            cout << "\nerror account was not saved because it is empty:";
            break;
        case clsUser::enSaveResult::svFaildAccounNumberExsit:
            cout << "\nerror account was not saved because it exsit:";
            break;

        }

    }
};
