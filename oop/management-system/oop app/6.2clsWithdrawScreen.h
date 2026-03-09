#pragma once
#include"0_clsScreen.h"
#include"clsBankClient.h"
#include"clsIputValiDate.h"
class clsWithdrawScreen:protected clsScreen
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
    static string _readAcounntNumber() {
        cout << "pleas inter accounNumber:";
        string accountNumber = clsIputValiDate::readString();
        return accountNumber;
    }

public:
    static void showWithedrawScreen() {
        _drawScreenHeader("Withedraw  screen");


        string accountNumber = _readAcounntNumber();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "client wass account number[" << accountNumber << "]is not exsit\n";
            accountNumber = _readAcounntNumber();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _print(client);

        short amount = 0;
        cout << "\nplease inter deposit numbmer:";
        amount = clsIputValiDate::readDouble("pleas inter floating number;\n");
        while (amount > client.accountBalance) {
            cout << "amount exceeds the balance you can withdraw up to  :" << client.accountBalance << endl;
            cout << "\nplease inter another deposit numbmer:";
            amount = clsIputValiDate::readDouble("pleas inter floating number;\n");
        }
        

        char answer = 'y';
        cout << "\nare you sure you want to withdraw account:";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            if (client.withdraw(amount)) {

            cout << "amount withdraw sucessfull\n";
            cout << "new acount balance is :" << client.accountBalance;
            }
            else {
                cout << "sorre operation not exsity because;";
                cout << "you want to withdraw :" << amount;
                cout << "and your account balance is :" << client.accountBalance;

            }
            
        }
        else {
            cout << "operation was cancelled\n";
        }

    }
};

