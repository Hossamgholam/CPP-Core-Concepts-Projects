#pragma once
#include<iostream>
#include"clsIputValiDate.h"
using namespace std;
#include"0_clsScreen.h"
#include"7_1clsUserListScreen.h"
#include"7_2clsAddNewUserScreen.h"
#include"7_3clsDeleteUserScreen.h"
#include"7_4clsUpdateUserScreen.h"
#include"7_5clsFindUserScreen.h"
class clsMangeUserScrean:protected clsScreen
{
private:
     enum enMangeUserMenueOption{
        eListUser=1,eAddUser=2,eDeletUser=3,
        eUpdateuser=4,efindUser=5,mainMenue=6
    };
    static short _readMangeUserMenueOption() {
        short number;
        cout << "\t\t\t\t\tchoose what do you want to do?[1 to 6]:";
        number = clsIputValiDate::readShortNumberBetween(1, 6, "please inter number between 1:6?");

        return number;
    }

    static void _showListUserScreen() {
        /*cout << "thire is show list of user\n";*/
        clsUserListScreen::showUserList();
        
    }
    static void _showAddNewUserScreen() {
       /* cout << "this is add new user:\n";*/
        clsAddNewUserScreen::showAddNewUserScreen();
    }
    static void _showDeletUserScreen() {
       /* cout << "there will be delete user screen\n";*/
        clsDeleteUserScreen::showdeleteUserScreen();
       
    }
    static void _showUpdateUserScreen() {
        /*cout << "this is update user screen\n";*/
        clsUpdateUserScreen::showUpdateUSerScreen();
    }
    static void _showFindUserScreen() {
        /*cout << "thie si find user\n";*/
        clsFindUserScreen::showFindUserScreen();
    }
    static void _goBackMangeUserMenue() {
        cout << "\nto back mange user menue inter any key ......";
        system("pause>0");
        showMangeUserMenue();
    }

    static void _performMangeUserMenueOPtion(enMangeUserMenueOption MangeUserMenueOption) {
        switch (MangeUserMenueOption) {
        case enMangeUserMenueOption::eListUser:
            system("cls");
            _showListUserScreen();
            _goBackMangeUserMenue();
            break;
        case enMangeUserMenueOption::eAddUser:
            system("cls");
            _showAddNewUserScreen();
            _goBackMangeUserMenue();
            break;
        case enMangeUserMenueOption::eDeletUser:
            system("cls");
            _showDeletUserScreen();
            _goBackMangeUserMenue();
            break;
        case enMangeUserMenueOption::eUpdateuser:
            system("cls");
            _showUpdateUserScreen();
            _goBackMangeUserMenue();
            break;
        case enMangeUserMenueOption::efindUser:
            system("cls");
            _showFindUserScreen();
            _goBackMangeUserMenue();
            break;
        case enMangeUserMenueOption::mainMenue: {

        }

        }
    }
public:
	static void showMangeUserMenue() {
        system("cls");
        if (!checkAccessRights(clsUser::enMangeuserPermission::pMangeUser)) {
            return; //this return for finshi call statck
        }
		_drawScreenHeader("mange user screen");
        cout << "\t\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t\t              mange user menue            \n ";
        cout << "\t\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t\t__________________________________________\n";
        cout << "\t\t\t\t\tlist users  [1]\n";
        cout << "\t\t\t\t\tadd user    [2]\n";
        cout << "\t\t\t\t\tdelet user  [3]\n";
        cout << "\t\t\t\t\tupdate user [4]\n";
        cout << "\t\t\t\t\tfind user   [5]\n";
        cout << "\t\t\t\t\tmain menu   [6]\n";

        cout << "\t\t\t\t\t______________________________________\n";
        _performMangeUserMenueOPtion(enMangeUserMenueOption(_readMangeUserMenueOption()));
	}
};

