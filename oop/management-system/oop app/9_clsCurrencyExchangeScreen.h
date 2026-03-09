#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"9.1clsListCurrencyScreen.h"
#include"9.2clsFincCurrencyScreen.h"
#include"9.3clsUpdateCurrencyRateScreen.h"
#include"9.4clsCurrencyCalculaterScreen.h"

class clsCurrencyExchangeScreen:protected clsScreen
{
private:
	enum enCurrencyExchangeMenueOptioin {
		eListCurrency=1,eFindCurrency=2,
		eUpdateRate=3,eCalcuatorCurrency=4,
		eMainMenue=5
	};
	static enCurrencyExchangeMenueOptioin _readCurrencyExchangeOption() {
		short number;
		cout << "\t\t\t\t\tpleaser inter number of operation between[1:5]:";
		number = clsIputValiDate::readShortNumberBetween(1, 5, "\npleaser inter number between 1 and 5:\n");
		return enCurrencyExchangeMenueOptioin(number);
	}
	static void _showlistCurrencyScreen() {
		clsListCurrencyScreen::showListCurrencyScreen();
	}

	static void _showFindCurrencyScreen() {
		clsFincCurrencyScreen::showFindCurrencyScreen();
	}
	static void _showUpdateCurrencyRateScreen() {
		clsUpdateCurrencyRateScreen::showUpdateCurrencyRateScreen();
	}
	static void _showCalculatCurrencyScreen() {
		clsCurrencyCalculaterScreen::showCurrecnyCalculaterScreen();
	}
	static void _gobackCurrencyExchangeMenue() {
		cout << "\n\npress any key to back to main menue.............";
		system("pause>0");
		showCurrencyExchangeMenue();
	}
	static void _performCurrencyExchangeOption(enCurrencyExchangeMenueOptioin option) {
		switch (option)
		{
		case enCurrencyExchangeMenueOptioin::eListCurrency:
			system("cls");
			_showlistCurrencyScreen();
			_gobackCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptioin::eFindCurrency:
			system("cls");
			_showFindCurrencyScreen();
			_gobackCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptioin::eUpdateRate:
			system("cls");
			_showUpdateCurrencyRateScreen();
			_gobackCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptioin::eCalcuatorCurrency:
			system("cls");
			_showCalculatCurrencyScreen();
			_gobackCurrencyExchangeMenue();
			break;
		case enCurrencyExchangeMenueOptioin::eMainMenue: {

			break;
		}
		default:
			break;
		}
	}
public:
	static void showCurrencyExchangeMenue() {
		system("cls");
		_drawScreenHeader("currency Exchange main screen");
		cout << "\t\t\t\t\t_______________________________________________\n";
		cout << "\t\t\t\t\t_______________________________________________\n";
		cout << "\t\t\t\t\t  currency exchange menue                      \n";
		cout << "\t\t\t\t\t_______________________________________________\n";
		cout << "\t\t\t\t\t_______________________________________________\n";
		cout << "\t\t\t\t\tlist currencies          [1]\n";
		cout << "\t\t\t\t\tfinc currency            [2]\n";
		cout << "\t\t\t\t\tupdate rate              [3]\n";
		cout << "\t\t\t\t\tcurrency calculator      [4]\n";
		cout << "\t\t\t\t\tmain menue               [5]\n";
		cout << "\t\t\t\t\t_______________________________________________\n";
		_performCurrencyExchangeOption(_readCurrencyExchangeOption());
	}
};

