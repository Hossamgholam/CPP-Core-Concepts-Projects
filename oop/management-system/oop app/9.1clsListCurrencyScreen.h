#pragma once
#include<iostream>
#include"vector"
#include"iomanip"
using namespace std;
#include"0_clsScreen.h"
#include"clsCurrency.h"

class clsListCurrencyScreen:protected clsScreen
{
private:
	static void printCurrencyRecord(clsCurrency currency) {
		cout << "\t\t\t|" << left << setw(30) << currency.getCountry() << "|" << setw(15) << currency.getCurrencyCode()
			<< "|" << setw(35) << currency.getCurrencyName() << "|" << setw(15) << currency.getRate();

	}
public:
	static void showListCurrencyScreen() {
		vector<clsCurrency>vCurrency = clsCurrency::GetCurrencyList();
		string title = "currencies list Screen";
		string subtitle = "\t\t\t\t\t(" + to_string(vCurrency.size()) + ") currency.";
		_drawScreenHeader(title, subtitle);

		cout << "\t\t\t_____________________________________________________________________________________________\n";
		cout << "\t\t\t|" << left << setw(30) << "country" << "|" << setw(15) << "code"
			<< "|" << setw(35) << "name " << "|" << setw(15) << "rate(1$)"
			<< "|";
		cout << "\n\t\t\t_____________________________________________________________________________________________\n";
		if (vCurrency.empty()) {
			cout << "\nther is no currecy info in database:\n";
		}
		else {
			for (clsCurrency record : vCurrency) {
				printCurrencyRecord(record);
				cout << "\n";
				
			}
			cout << "\t\t\t__________________________________________________________________________________________\n";
		}
	}
};

