#pragma once
#include<iostream>
#include"clsIputValiDate.h"
#include"0_clsScreen.h"
#include"clsBankClient.h"
using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
private:
    static void _print(clsBankClient& client) {
        cout << "\n client carde\n";
        cout << "------------------------------\n";
        cout << "\nfristName   :" << client.fristName;
        cout << "\nlastName    :" << client.lastName;
        cout << "\nfullName    :" << client.fullName();
        cout << "\nemail       :" << client.email;
        cout << "\nphone       :" << client.phone;
        cout << "\nacc. number :" << client.accountNumber;
        cout << "\npin code    :" << client.pinCode;
        cout << "\naccounfBalan:" << client.accountBalance;
    }
public:

    static void showdeletClientScreen() {

        if (!checkAccessRights(clsUser::enMangeuserPermission::pDeleteClient)) {
            return; //this return for finshi call statck
        }
        _drawScreenHeader("delete client screen:");


        cout << "pleas inter accounNumber:";
        string accountNumber = clsIputValiDate::readString();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "client not exsit:pleas inter another account number:";
            accountNumber = clsIputValiDate::readString();
        }

        //search about client and return withe info 
        clsBankClient client = clsBankClient::find(accountNumber);
        _print(client);

        char answer = 'y';
        cout << "\nare your sure you what to delete:"; cin >> answer;
        if (toupper(answer) == 'Y') {

            if (client.Delete()) {
                cout << "\nclient delted successful:-):\n";
                _print(client);
            }
            else {
                cout << "\n error client was not deleted\n";
            }
        }

    }
};

