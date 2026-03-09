
#pragma once
#include<iostream>
#include<iomanip>
#include"clsIputValiDate.h"
#include"0_clsScreen.h"
#include"1_clsClientListScreen.h"
#include"2_clsAddNewClientScreen.h"
#include"3_clsDeleteClientScreen.h"
#include"4_clsUpdateClientScreen.h"
#include"5_clsFindClientScreen.h"
//call it hire make funtioin of client call in it
#include"6_clsTransactionScreen.h"
#include"7_clsMangeUserScrean.h"
#include"8_clsLogInRegisterScreen.h"
#include"9_clsCurrencyExchangeScreen.h"
//this is here for log out function//aftar log out but current user empty
#include"global.h"


using namespace std;
class clsMainScreen:protected clsScreen
{
private:
    enum enMainMenueOpetion {
        eShowClient = 1,
        eAddClient = 2,eDeleteClient = 3, eUpdateClient = 4,
        eFiendClient = 5, 
        eTransaction = 6, eMangeUser = 7,
        eLoginRegister = 8,eCurrencyExchange=9, eLogout=10

    };

    //read mani menue opetion with validation
    static short _readMainMenueOpetioin() {
    short number;
    cout << "\t\t\t\t\tchoose what do you want to do?[1 to 10]:";
    number = clsIputValiDate::readShortNumberBetween(1, 10, "please inter number between 1:8?");
    return number;
    }


    //show alll client in fill by call clsclientlistscreen class 
    static void _showAllClientScreen() {
        clsClientListScreen::showClientList();
    }

    //add new client in fill by call clsAddNewClientsScreen
    static void _showAddNewClientsScreen() {
        clsAddNewClientScreen::showAddNewClientScreen();
    }

    //delet client from fill by call clsDeleteclientScreen
    static void _showDeleteClientScreen() {
        clsDeleteClientScreen::showdeletClientScreen();
    }

    //update client in fill by call clsUpdateClientScreen
    static void _showUpdateClientScreen() {
        clsUpdateClientScreen::showUpdateClientScreen();
    }

    //search about client in fill by call clsfindeclientscreen
    static void _showFindClientScreen() {
        clsFindClientScreen::showFindClientScreen();
        
    }

    //this fuctioin show another menue for trancaction content
    //deposit ,withedraw , totalbalance in fill and we can go back main menue
    static void _showTransactionMenue() {
        clsTransactionScreen::showTransactionMenue();
        
    }

    //this fuctioin show menue for mange user content 
    //content showListOfUser , add ,update,delete , find user and go back main menue
    static void _showMangeUserMenue() {
        clsMangeUserScrean::showMangeUserMenue();
    }

    //this function to show login register that save in  fill "loginRegister "
    //the main idea is make struct in sid user class to git info from fill aftar split and convert
    static void _showLogInRegisterScreen() {
        clsLogInRegisterScreen::showLogInRegisterScreen();
    }

    static void _showCurrencyExchangeMenue() {
        clsCurrencyExchangeScreen::showCurrencyExchangeMenue();
    }
    //last choices is delete current login 
    // after choic logOut it endfrom this class and
    // go back login again without call showloginscreen
    //becuse it lead to circular referens (call stack)
    static void _logOut() {
        /*cout << "show gobacklogin   screen will be hir\n";*/
        currentUser = clsUser::find("", "");
        
    }

    static void _goBackMainMenue() {
        cout << "\n\n\t\t\t\t\tpress any key to back to main menue.............";
         system("pause>0");
        showMainMneue();
    }
    static void _performMainMenueOption(enMainMenueOpetion MainMenueOption) {
        switch (MainMenueOption) {
        case enMainMenueOpetion::eShowClient:
            system("cls");
            _showAllClientScreen();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eAddClient:
            system("cls");
            _showAddNewClientsScreen();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eDeleteClient:
            system("cls");
            _showDeleteClientScreen();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eUpdateClient:
            system("cls");
            _showUpdateClientScreen();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eFiendClient:
            system("cls");
            _showFindClientScreen();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eTransaction:
            system("cls");
            _showTransactionMenue();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eMangeUser:
            system("cls");
            _showMangeUserMenue();
            _goBackMainMenue();
            break;
        case enMainMenueOpetion::eLoginRegister:
            system("cls");
            _showLogInRegisterScreen();
            _goBackMainMenue();
        case enMainMenueOpetion::eCurrencyExchange:
            system("cls");
            _showCurrencyExchangeMenue();
            _goBackMainMenue();
        default:
            system("cls");
            _logOut();
            break;
        }
    }
public:
    static void showMainMneue() {
        system("cls");
        _drawScreenHeader("main screen");
        cout << "\t\t\t\t\t___________________________________________\n";
        cout << "\t\t\t\t\t___________________________________________\n";
        cout << "\t\t\t\t\t              main menue screen            \n";
        cout << "\t\t\t\t\t___________________________________________\n";
        cout << "\t\t\t\t\t___________________________________________\n";
        cout << "\t\t\t\t\tshow client                 [1]\n";
        cout << "\t\t\t\t\tadd client                  [2]\n";
        cout << "\t\t\t\t\tdelet client                [3]\n";
        cout << "\t\t\t\t\tupdate client               [4]\n";
        cout << "\t\t\t\t\tfind client                 [5]\n";
        cout << "\t\t\t\t\ttransaction                 [6]\n";
        cout << "\t\t\t\t\tmange user                  [7]\n";
        cout << "\t\t\t\t\tlogin Register              [8]\n";
        cout << "\t\t\t\t\tcurrency Exchange           [9]\n";
        cout << "\t\t\t\t\tlog out                     [10]\n";
        cout << "\t\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t\t___________________________________________\n";
        _performMainMenueOption(enMainMenueOpetion(_readMainMenueOpetioin()));
    }
};

