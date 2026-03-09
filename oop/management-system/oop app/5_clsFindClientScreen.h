#pragma once
#include"0_clsScreen.h"
#include"clsBankClient.h"
#include"clsIputValiDate.h"
class clsFindClientScreen:protected clsScreen
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
    static void showFindClientScreen(){
        if (!checkAccessRights(clsUser::enMangeuserPermission::pFindClient)) {
            return; //this return for finshi call statck
        }
        _drawScreenHeader("delete client screen:");
        cout << "pleas inter accounNumber:";
        string accountNumber = clsIputValiDate::readString();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "client not exsit:pleas inter another account number:";
            accountNumber = clsIputValiDate::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        if (client.isEmpty()) {
            cout << "client is not founc(-:\n";
        }
        else {
            cout << "client is found-):\n";
        }
        _print(client);

    }
    


};

