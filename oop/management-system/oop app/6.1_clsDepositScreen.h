#pragma once
#include"0_clsScreen.h"
#include"clsBankClient.h"
#include"clsIputValiDate.h"
#include"clsString.h"
class clsDepositScreen:protected clsScreen
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
	static void showDepositScreen() {
		_drawScreenHeader("deposit screen");

        
        string accountNumber = _readAcounntNumber();
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "client wass account number[" << accountNumber << "]is not exsit\n";
            accountNumber = _readAcounntNumber();
        }
        
        clsBankClient client = clsBankClient::find(accountNumber);
        _print(client);

        double amount;
        cout <<  "\nplease inter amount you want to deposit:";
        amount = clsIputValiDate::readDouble("pleas inter floating number;\n");
        
        char answer = 'y';
        cout << "\nare you sure you want to deposit account:";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            client.deposit(amount);
            cout << "amount deposit sucessfull\n";
            cout << "new acount balance is :"<< client.accountBalance;
        }
        else {
            cout << "operation was cancelled\n";
        }

    }
};

