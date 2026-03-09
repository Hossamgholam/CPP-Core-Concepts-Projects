#pragma once
#include"0_clsScreen.h"
#include"clsBankClient.h"
#include"clsiputValiDate.h"
#include"6.1_clsDepositScreen.h"
#include"6.2clsWithdrawScreen.h"
#include"6.3clsTotalBalancesScreen.h"
#include"6.4clsShowTransferScreen.h"
#include"6.5clsTransferLogScreen.h"
class clsTransactionScreen:protected clsScreen
{
private:
    enum enTransactionMenueOpetion {
        eDeposit = 1, eWithdraw = 2,
        eShowoTalBalance = 3,eTransfer=4, eTransferLog=5, eShowMainMenue= 6
    };

    //this fuction for read opetioin from 1 to 4 
    //check if it correct
    static short _readTransactionMenueOpetioin() {
        short number;
        cout << "choose what do you want to do?[1 to 6]:";
        number=clsIputValiDate::readShortNumberBetween(1, 6, "enter number between 1:4?");
        return number;
    }

    //this fuction to call class deposit screen and show it
    static void _showDepositScreen() {
        clsDepositScreen::showDepositScreen();
    }
    static void _showWithdrawScreen() {
        clsWithdrawScreen::showWithedrawScreen();

    }
    static void _showTransferScreen() {
        clsShowTransferScreen::showTransferScreen();
    }
    static void _showTotalBalanceScreen() {
        clsTotalBalancesScreen::showTotalBalanceScreen();
    }
    static void _goBackTransactionMenue() {
        cout << "\n\npress any key to back to main menue.............";
        system("pause>0");
        showTransactionMenue();
    }
    static void _showTransferLogScreen() {
        clsTransferLogScreen::showTransferLogScreen();
    }
    //go back to main menue is there in performMainMenue
    static void _performTransactionMenueOpetion(enTransactionMenueOpetion TransactionMenueOpetion) {
        switch (TransactionMenueOpetion) {
        case enTransactionMenueOpetion::eDeposit:
            system("cls");
            _showDepositScreen();
            _goBackTransactionMenue();
            break;
        case enTransactionMenueOpetion::eWithdraw:
            system("cls");
            _showWithdrawScreen();
            _goBackTransactionMenue();
            break;
        case enTransactionMenueOpetion::eShowoTalBalance:
            system("cls");
            _showTotalBalanceScreen();
            _goBackTransactionMenue();
            break;
        case enTransactionMenueOpetion::eTransfer:
            system("cls");
            _showTransferScreen();
            _goBackTransactionMenue();
            break;
        case enTransactionMenueOpetion::eTransferLog:
            system("cls");
            _showTransferLogScreen();
            _goBackTransactionMenue();
            break;
        case enTransactionMenueOpetion::eShowMainMenue: {
            //we do not call show main menue becuse circular referenc 
            //call stack 
           /*
           | login screen                  |
           | main menue screen             |
           | transaction screen            |
           | back not call it again        |
           |                               |
           |                               |
           |                               |
           */

        }

        }
    }
public:
	static void showTransactionMenue() {
        system("cls");
        if (!checkAccessRights(clsUser::enMangeuserPermission::pTransactionMenue)) {
            return; //this return for finshi call statck
        }
		_drawScreenHeader("transaction screen");

        cout << "\t\t\t\t\t___________________________________________\n";
        cout << "\t\t\t\t\t              transaction  menue              \n";
        cout << "\t\t\t\t\t____________________________________________\n";
        cout << "\t\t\t\t\tdeposit              [1]\n";
        cout << "\t\t\t\t\twithdraw             [2]\n";
        cout << "\t\t\t\t\ttotal balances       [3]\n";
        cout << "\t\t\t\t\ttransfer             [4]\n";
        cout << "\t\t\t\t\ttransfer log         [5]\n";
        cout << "\t\t\t\t\tmain menue           [6]\n";
        cout << "\t\t\t\t\t_______________________________________\n";

        _performTransactionMenueOpetion(enTransactionMenueOpetion(_readTransactionMenueOpetioin()));
		
	}
};

