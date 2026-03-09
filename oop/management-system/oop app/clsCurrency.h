#pragma once
#include"iostream"
#include"vector"
#include"fstream"
#include"clsString.h"
#include"string"
using namespace std;
//what class can do
/*
summery:
this class about couins of country it is separt from bank system
has currency class work withe date 
has 4 screen  and 4 property

properity:
   is (country of couins,cod,cod name,rate acording to doller)

method(
    list       of couins date that storage in fill name currencis.txt
    find        search about specific couins by country  or cod
	updat       update only  rate of couins
	calcualtor  change for couins to couins
)
this method is classScreen take number form 9.1 to 9.4
*/


class clsCurrency
{
private:
	enum mode{emptyMode=1,updateMode};
	mode _mode;
	string _country;
	string _currencyCod;
	string _currencyName;
	float _rate;
	//when retrive date from fill as string lin 
	// it convert date to object clscurrrency
	static clsCurrency _convertLineToCurrencyObject(string line) {
		vector<string> currencyRecord = clsString::split(line, "#//#");
		return clsCurrency(mode::updateMode, currencyRecord[0],
			currencyRecord[1], currencyRecord[2],stof( currencyRecord[3]));
	}

	// it return infromation of couins from fill on aftar another
	// and convert it to object (clscurrency) 
	//then storge all in vector 
	static vector<clsCurrency> _loadCurrencysDateFromFill() {
		vector<clsCurrency> vCurrency;
		fstream ptFill;
		ptFill.open("Currencies.txt", ios::in);
		if (ptFill.is_open()) {
			string line = "";
			while (getline(ptFill, line)) {

				clsCurrency currency = _convertLineToCurrencyObject(line);
				vCurrency.push_back(currency);
			}
			ptFill.close();
		}
		return vCurrency;

	}

	
	static string _convertCurrencyObjectToLine(clsCurrency& currency,string delemter="#//#") {
		string line = "";
		line = line + currency.getCountry() + delemter
			+ currency.getCurrencyCode() + delemter
			+ currency.getCurrencyName() + delemter
			+to_string( currency.getRate());
		return line;
	}
	static void _saveCurrencysDateToFill(vector<clsCurrency>& vCurrency) {
		fstream ptFill;
		string line = "";
		ptFill.open("Currencies.txt", ios::out);
		if (ptFill.is_open()) {
			for (clsCurrency i : vCurrency) {
				

					line = _convertCurrencyObjectToLine(i);
					ptFill << line << endl;
				

			}
			ptFill.close();
		}
	}

	void _update() {
		vector<clsCurrency>vCurrency = _loadCurrencysDateFromFill();
		for (clsCurrency& var : vCurrency) {
			if (var.getCurrencyCode() == getCurrencyCode()) {
				var = *this;
				break;
			}
		}
		_saveCurrencysDateToFill(vCurrency);
	}

	static clsCurrency _getEmptyCurrencyObject() {
		return clsCurrency(mode::emptyMode, "e", "e", "e", 0);
	}

public:
	clsCurrency(mode yourMode, string country,
		string currencyCode, string currencyName, float rate) {
		_mode = yourMode;
		_country = country;
		_currencyCod = currencyCode;
		_currencyName = currencyName;
		_rate = rate;
	}

	// we make get only becuse we do not add or update 
	string getCountry() {
		return _country;
	}
	string getCurrencyCode() {
		return _currencyCod;
	}
	string getCurrencyName() {
		return _currencyName;
	}
	float getRate() {
		return _rate;
	}
	/*
	//this fucntion for update rate only 
	take new value assint to currentRate 
	then update date in fill
	*/
	void updateRate(float newRate) {
		_rate = newRate;
		_update();
	}
	// create empty object of class
	//usfull if we search and did not found in this case return empty object
	bool isEmpty() {
		return _mode == mode::emptyMode;
	}

	//search about currency by currencyCode and 
	// return object date if it found  
	// return empty object if it not found
	static clsCurrency findByCurrencyCode(string code) {
		code = clsString::upperAllString(code);

		vector<clsCurrency> vCurrency;
		fstream ptFill;
		ptFill.open("Currencies.txt", ios::in);
		if (ptFill.is_open()) {
			string line = "";
			while (getline(ptFill, line)) {

				clsCurrency currency = _convertLineToCurrencyObject(line);
				if (currency.getCurrencyCode() == code) {
					ptFill.close();
					return currency;
				}
				vCurrency.push_back(currency);
			}

		}
		return _getEmptyCurrencyObject();
	}
	static clsCurrency findByCountry(string country) {
		country = clsString::uperFristLitterOfEachWord(country);

		vector<clsCurrency> vCurrency;
		fstream ptFill;
		ptFill.open("Currencies.txt", ios::in);
		if (ptFill.is_open()) {
			string line = "";
			while (getline(ptFill, line)) {

				clsCurrency currency = _convertLineToCurrencyObject(line);
				if (currency.getCountry() == country) {
					ptFill.close();
					return currency;
				}
				vCurrency.push_back(currency);
			}
			
		}
		return _getEmptyCurrencyObject();
	}

	static bool isCurrencyExsit(string currencyCode) {
		clsCurrency currency = findByCurrencyCode(currencyCode);
		return (!currency.isEmpty());
	}

	static vector<clsCurrency> GetCurrencyList() {
		return _loadCurrencysDateFromFill();
	}

	float convertToUSD(float amount) {
		return amount / getRate();
	}
	float convertFromUSDToAnoterCurrecny(clsCurrency currencyExchangeTo, float amount) {
		float amountByDoller = convertToUSD(amount);
		if (currencyExchangeTo.getCurrencyCode() == "USD") {
			return amountByDoller;
		}
		return amountByDoller * currencyExchangeTo.getRate();
	}

};
