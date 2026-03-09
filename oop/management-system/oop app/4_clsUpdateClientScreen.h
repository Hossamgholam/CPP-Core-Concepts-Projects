#pragma once
#include"0_clsScreen.h"
#include"clsBankClient.h"
#include"clsIputValiDate.h"
class clsUpdateClientScreen:protected clsScreen
{
private:
    static void _readClientInfo(clsBankClient& client) {
        cout << "\nenter frist name:";
        client.fristName = clsIputValiDate::readString();

        cout << "\nenter last name:";
        client.lastName = clsIputValiDate::readString();

        cout << "\nenter email:";
        client.email = clsIputValiDate::readString();

        cout << "\nenter phone:";
        client.phone = clsIputValiDate::readString();

        cout << "\nenter pincode:";
        client.pinCode = clsIputValiDate::readString();

        cout << "\nenter account Balance:";
        client.accountBalance = clsIputValiDate::readDouble("inter float number");
    }
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
    static void showUpdateClientScreen() {
        if (!checkAccessRights(clsUser::enMangeuserPermission::pUpdateClient)) {
            return; //this return for finshi call statck
        }
        _drawScreenHeader("update client screen");

        cout << "pleas inter accounNumber:";
        string accountNumber = clsIputValiDate::readString();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "client not exsit:pleas inter another account number:";
            accountNumber = clsIputValiDate::readString();
        }
        clsBankClient client = clsBankClient::find(accountNumber);

        _print(client);

        cout << "\nupdate client\n";
        cout << "_______________________";
        _readClientInfo(client);

        clsBankClient::enSaveResult saveResult;

        saveResult = client.save();
        switch (saveResult)
        {
        case clsBankClient::enSaveResult::svScusseded:
            cout << "\n account updated successfully:-)\n";
            _print(client);
            break;
        case clsBankClient::enSaveResult::svFaildEmptyObject:
            cout << "\nerror account was not saved because it is empty:";
            break;
        default:
            break;
        }


    }

};

