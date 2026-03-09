#pragma once
#include"0_clsScreen.h";
#include"clsBankClient.h"
#include"clsIputValiDate.h"

class clsAddNewClientScreen:protected clsScreen
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
    static void _print( clsBankClient& client) {
        cout << "\n client carde\n";
        cout << "------------------------------\n";
        cout << "\nfristName   :" <<client.fristName;
        cout << "\nlastName    :" <<client.lastName;
        cout << "\nfullName    :" <<client.fullName();
        cout << "\nemail       :" <<client.email;
        cout << "\nphone       :" <<client.phone;
        cout << "\nacc. number :" <<client.accountNumber;
        cout << "\npin code    :" <<client.pinCode;
        cout << "\naccounfBalan:" <<client.accountBalance;
    }
public:
    static void showAddNewClientScreen() {

        //check permission
        if (!checkAccessRights(clsUser::enMangeuserPermission::pShowClientList)) {
            return; //this return for finshi call statck
        }


        _drawScreenHeader("add new client screen");
        cout << "pleas inter accounNumber:";

        //it read accountNumber untill is true
        string accountNumber = clsIputValiDate::readString();
        //level one securtiy
        while (clsBankClient::isClientExist(accountNumber)) {
            cout << "client  exsit:pleas inter another account number:";
            accountNumber = clsIputValiDate::readString();
        }

        //make new object empty but with update mode to recive 
        //info
        clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);
        _readClientInfo(newClient);

        //save object in fill and return enum for three condtion
        clsBankClient::enSaveResult saveResult;
        saveResult = newClient.save();

        switch (saveResult)
        {
        case clsBankClient::enSaveResult::svScusseded:
            cout << "\n account add successfully:-)\n";
            _print(newClient);
            break;
        case clsBankClient::enSaveResult::svFaildEmptyObject:
            cout << "\nerror account was not saved because it is empty:";
            break;
        case clsBankClient::enSaveResult::svFaildAccounNumberExsit:
            cout << "\nerror account was not saved because it exsit:";
            break;
       
        }

    }
};

