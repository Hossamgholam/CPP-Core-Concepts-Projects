
#include <iostream>
#include"10_clsShowLoginScreen.h"


using namespace std;
/*
Your project is a Console-Based Bank Management System implemented in C++ using OOP principles and a modular architecture.
It provides features for:
*/
//1. Core Business Classes
/*
    clsPerson:
          Base class for common properties like FirstName, LastName, Email, Phone.

          clsBankClient (Inherits clsPerson):

          Holds AccountNumber, PinCode, AccountBalance.

          Implements Encapsulation using __declspec(property) and private members.

          Includes:

          find() → Search for client in file.

          save() → Add or update client info.

          Delete() → Mark and remove client.

          deposit() / withdraw() → Transaction logic.

          Modes (enptymode, updateMode, addNewMode) for object state management.

          clsUser (similar to clsBankClient):
          Manages system users for authentication.

    clsCurrency:

          Represents a currency (code, country, rate).

          Handles:

          Finding currency.

          Updating exchange rates.

          Converting between currencies.
          */



//==============================================================================================================



//2. Screens (UI Layer)
/*

All UI screens inherit from clsScreen for a common header design:

Login Screen → clsShowLoginScreen

Main Menu → clsMainScreen

Client Management Screens:

clsClientListScreen → List all clients.

clsAddNewClientScreen → Add new client.

clsDeleteClientScreen → Delete client.

clsUpdateClientScreen → Update client info.

clsFindClientScreen → Search client.

Transaction Screens:

clsTransactionScreen → Transaction menu.

clsDepositScreen → Deposit money.

clsWithdrawScreen → Withdraw money.

clsTotalBalancesScreen → Show total balances.

Currency Screens:

clsCurrencyListScreen → List currencies.

clsFindCurrencyScreen → Find currency by code.

clsUpdateRateScreen → Update exchange rate.

clsCurrencyCalculatorScreen → Convert between currencies.

User Management Screens:

clsManageUserScreen → Manage system users.

clsUserListScreen → List users.

clsAddNewUserScreen, clsDeleteUserScreen, etc.
*/


//3. Helper Classes
/*
clsString → String splitting and manipulation.

clsInputValidate → Validate numeric and string input.

clsUtil → Convert numbers to text, utility methods.
*/


//4. Persistence Layer
/*
Data stored in text files:

myfill.txt for clients.

Another file for users.

Possibly a file for currencies.

CRUD operations rely on:

_loadClientsDateFromFile()

_saveClientsDateToFile()

_convertClientObjectToLine()

_convertLineToClientObject()
*/

int main()
{
    while (true) {
        //if it make 3 trials and fail in 3 it return false 
        //not fals is true so it lock
        bool lock = !clsShowLoginScreen::showLogInScreen();
        if (lock) {
            break;
        }

    
    }
   
   
    


}