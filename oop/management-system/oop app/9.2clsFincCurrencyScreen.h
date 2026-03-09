#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"clsCurrency.h"
class clsFincCurrencyScreen:protected clsScreen
{
private:
	//anotherlogic//anoter logic
	//enum enfindCurrencyBy {
	//	byCountry=1,byCurrencyCode=2
	//};
	//static enfindCurrencyBy _readFindCurrencyByOption() {
	//	short number;
	//	cout << "do you search by country[1] or code[2]:"; cin >> number;
	//	return enfindCurrencyBy(number);
	//}
	//static clsCurrency _performFindCurrencyByOption(enfindCurrencyBy option) {
	//	switch (option)
	//	{
	//	case clsFincCurrencyScreen::byCountry:
	//		cout << "pleaser inter country name:";
	//		return clsCurrency::findByCountry( clsIputValiDate::readString());
	//		break;
	//	case clsFincCurrencyScreen::byCurrencyCode:
	//		cout << "pleas inter currecny code:";
	//		return clsCurrency::findCurrencyCode( clsIputValiDate::readString());
	//		break;
	//	default:
	//		break;
	//	}
	//}

	static void printCurrencyCard(clsCurrency currency) {
        cout << "\n______________________________________________\n";
        cout << "country:" << currency.getCountry();
        cout << "\ncurrency code:" << currency.getCurrencyCode();
        cout << "\ncurrency name:" << currency.getCurrencyName();
        cout << "\nrate:" << currency.getRate();
        cout << "\n______________________________________________\n";
}
	static void showResuilt(clsCurrency& currency) {
		if (!currency.isEmpty()) {
			cout << "currecny found -)\n";
			printCurrencyCard(currency);
		}
		else {
			cout << "curreccny not found\n";
		}
	}
public:
	static void showFindCurrencyScreen() {
		_drawScreenHeader("find curreny screen");
		short number;
		cout << "do you search by country[1] or code[2]:"; cin >> number;

		if (number == 1) {
			string country = "";
			cout << "pleas inter country of currecny:"; cin >> country;
			clsCurrency currency = clsCurrency::findByCountry(country);
			showResuilt(currency);
		}
		else {
			string cod = "";
			cout << "pleaser inter currency cod:"; cin >> cod;
			clsCurrency currency = clsCurrency::findByCurrencyCode(cod);
			showResuilt(currency);
		}
	}
};

