#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"clsCurrency.h"
class clsUpdateCurrencyRateScreen: protected clsScreen
{
private:
	static string _readCurrecnyCode() {
		string currencyCode;
		cout << "please inter currency code:"; cin >> currencyCode;
	    return currencyCode;
	}
	static float _readNewRate() {
		float newrate;
		cout << "enter new rate:"; newrate=clsIputValiDate::readDouble("inter float number:");
		return newrate;
	}
	static void _printCurrencyCard(clsCurrency currency) {
		cout << "\n______________________________________________\n";
		cout << "country:" << currency.getCountry();
		cout << "\ncurrency code:" << currency.getCurrencyCode();
		cout << "\ncurrency name:" << currency.getCurrencyName();
		cout << "\nrate:" << currency.getRate();
		cout << "\n______________________________________________\n";
	}
public:
	static void showUpdateCurrencyRateScreen() {
		_drawScreenHeader("update rate screen");

		string currencyCode=_readCurrecnyCode();
		while (!clsCurrency::isCurrencyExsit(currencyCode)) {
			cout << "currency code not exsit inter anoter one:";
			currencyCode = _readCurrecnyCode();
		}
		clsCurrency currency = clsCurrency::findByCurrencyCode(currencyCode);
		_printCurrencyCard(currency);

		char answer = 'y';
		cout << "are you sure you want to update rate[y:n]:"; cin >> answer;

		if (toupper(answer) == 'Y') {
			cout << "Update currency rate\n";
			cout << "_________________________\n";
			
			
			currency.updateRate(_readNewRate());
			cout << "currency update successful-):\n";
			_printCurrencyCard(currency);

		}
		else {
			cout << "operatioin is cansall\n";
			return;
		}
		
	}
};

