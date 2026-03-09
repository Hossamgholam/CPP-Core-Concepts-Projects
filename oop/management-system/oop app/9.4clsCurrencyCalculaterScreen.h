#pragma once
#include<iostream>
using namespace std;
#include"0_clsScreen.h"
#include"clsCurrency.h"
class clsCurrencyCalculaterScreen:protected clsScreen
{
private:
	static clsCurrency _getCurrency(string massege) {
		string currencyCode;
		cout << massege; currencyCode =clsString::upperAllString( clsIputValiDate::readString());
		while (!clsCurrency::isCurrencyExsit(currencyCode)) {
			cout << "currency code not exsit inter anoter one:";
			currencyCode = clsIputValiDate::readString();
		}
		clsCurrency currency = clsCurrency::findByCurrencyCode(currencyCode);
		return currency;
	}
	static float _readAmount() {
		float amount;
		cout << "pleas inter amount to exchange:"; amount=clsIputValiDate::readFloat("\npleas inter float number:\n");
		return amount;
	}
	static void _printCurrencyCard(clsCurrency currency) {
		cout << "______________________________________________\n";
		cout << "country:" << currency.getCountry();
		cout << "\ncurrency code:" << currency.getCurrencyCode();
		cout << "\ncurrency name:" << currency.getCurrencyName();
		cout << "\nrate:" << currency.getRate();
		cout << "\n______________________________________________\n";
	}

	static void _printCalcuaterResutl(float amount,clsCurrency currencyConvertFrom,clsCurrency currencyConvertTo) {


		cout << "\n\nconvert from " << currencyConvertFrom.getCurrencyCode() << " to " << "USD" << endl;
		_printCurrencyCard(currencyConvertFrom);
		float amountInDoller = currencyConvertFrom.convertToUSD(amount);
		cout << to_string(amount) + " " + currencyConvertFrom.getCurrencyCode() + " = " + to_string(amountInDoller);
		

		if (currencyConvertTo.getCurrencyCode() == "USD") {
			return;
		}

		cout << "\n\nconvert from " << "USD" << " to " << currencyConvertTo.getCurrencyCode() << endl;
		_printCurrencyCard(currencyConvertTo);
		 
		cout << amount <<" " << currencyConvertFrom.getCurrencyCode() << " = "
			<<currencyConvertFrom.convertFromUSDToAnoterCurrecny(currencyConvertTo,amount);
	}
public:
	static void showCurrecnyCalculaterScreen() {
		char answer = 'n';
		do {

		system("cls");
		_drawScreenHeader("currency calculater:");
		
		clsCurrency currencyConvertFrom = _getCurrency("pleaser inter currency code to convert from:");
		clsCurrency currencyConvertTo = _getCurrency("pleaser inter currency code to convert to:");

		float amount=_readAmount();
		
		_printCalcuaterResutl(amount,currencyConvertFrom,currencyConvertTo);

		 cout << "\n\ndo you want to repeat operation:"; cin >> answer;
		} while (toupper(answer) == 'Y');
		


		
		
	}
};

