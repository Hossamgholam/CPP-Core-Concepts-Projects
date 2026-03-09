#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"clsUser.h"
#include"clsIputValiDate.h"
class clsUpdateUserScreen:protected clsScreen
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
                permission = permission + clsUser::enMangeuserPermission::pUpdateClient;

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
            cout << "\nlog in register:"; cin >> answer;
            if (toupper(answer) == 'Y') {
                permission = permission + clsUser::enMangeuserPermission::pLogInRegister;
            }
            return permission;
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
        cout << "\nUser name   :" << user.userName;
        cout << "\nPassword    :" << user.password;
        cout << "\npermission  :" << user.permission;
    }
public:
    static void showUpdateUSerScreen() {
        _drawScreenHeader("update User screen");

        cout << "pleas inter User Name:";
        string userName = clsIputValiDate::readString();
        while (!clsUser::isUserExist(userName)) {
            cout << "client not exsit:pleas inter another user name:";
            userName = clsIputValiDate::readString();
        }
        clsUser User = clsUser::find(userName);

        _print(User);

        cout << "\nupdate user\n";
        cout << "_______________________";
        _readUserInfo(User);

        clsUser::enSaveResult saveResult;

        saveResult = User.save();
        switch (saveResult)
        {
        case clsUser::enSaveResult::svScusseded:
            cout << "\n account updated successfully:-)\n";
            _print(User);
            break;
        case clsUser::enSaveResult::svFaildEmptyObject:
            cout << "\nerror account was not saved because it is empty:";
            break;
        
        }


    }

};

