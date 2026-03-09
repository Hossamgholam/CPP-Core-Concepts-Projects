#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsString.h"
#include"clsUtil.h"
#include"clsPeriod.h"

class clsIputValiDate
{
public:
	static bool isNumberBeteen(int number, int from, int to) {
		return (number >= from  && number <= to) ? true : false;
	}
	static bool isNumberBeteen(double number, double from, double to) {
		return (number >= from && number <= to) ? true : false;
	}
	static bool isNumberBeteen(short number, short from, short to) {
		return (number >= from && number <= to) ? true : false;
	}
	static bool isNumberBeteen(float number, float from, float to) {
		return (number >= from &&	 number <= to) ? true : false;
	}

	//there are many condition take it in cary
	static bool isDatebetween( clsDate date,clsDate from,clsDate to) {
		if (clsDate::Date1AfterDate2(from, to)) {
			clsDate::swapDates(from, to);
		}
		if((clsDate::Date1AfterDate2(date,from)||clsDate::isDate1EquelDate2(date,from))
			&& (clsDate::isDate1BeforeDate2(date, to) || clsDate::isDate1EquelDate2(date, to))) {
			return true;
		}
		return false;
		
	}

	static char readChar(string errorMassge) {
		char number;
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << errorMassge; cin >> number;
		}
		return number;
	}


	static short readShort(string errorMassge) {
		short number;
		cin >> number;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << errorMassge; cin >> number;
		}
		return number;
	}
	static short readShortNumberBetween(short from, short to, string errorMassage) {
		short number = readShort("invalid number:inter number");
		while (!isNumberBeteen(number, from, to)) {
			cout << errorMassage;
			number = readShort("invalid number:inter number");
		}
		return number;

	}

	static int readInt(string errorMassge) {
		int number;
		 cin >> number;
		
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << errorMassge; cin >> number;
		}
		return number;
	}
	static int readIntNumberBetween(int from, int to, string errorMassage) {
		int number =readInt("invalid number:inter number");
		while (!isNumberBeteen(number, from, to)) {
			cout << errorMassage;
			number = readInt("invalid number:inter number");
		}
		return number;
		
	}

	static double readDouble(string errorMassge) {
		double number;
		cin >> number;
		//cin.fail cin.clear cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << errorMassge; cin >> number;
		}
		return number;
	}
	static double readDoubleNumberBetween(double from, double to, string errorMassage) {
		double number = readDouble("invalid number:inter number");
		while (!isNumberBeteen(number, from, to)) {
			cout << errorMassage;
			number = readDouble("invalid number:inter number");
		}
		return number;

	}

	static float readFloat(string errorMassge) {
		float number;
		cin >> number;
		//cin.fail cin.clear cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << errorMassge; cin >> number;
		}
		return number;
	}

	static string readString() {
		string s = "";
		getline(cin>> ws, s);
		return s;
	}
	
	// why you make copy you can call her only
	static bool isValideDate(clsDate yourDate) {
		return clsDate::ValideDate(yourDate);
	}
	
	
};



