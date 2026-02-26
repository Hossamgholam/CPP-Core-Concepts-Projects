#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsString.h"
#include"clsUtil.h"
using namespace std;
/*
	Class: clsInputValidate

	Description:
	A utility class responsible for handling safe user input
	and validating numeric and date values.

	This class centralizes all input validation logic to:
	- Prevent invalid numeric entries
	- Ensure numbers fall within specific ranges
	- Validate date objects using clsDate
	- Check if a date falls within a specific period

	Features:
	- Safe integer and double reading
	- Range validation using templates
	- Date validation through clsDate integration
	- Date range checking

	Design Notes:
	- Implemented using static methods for global accessibility.
	- Uses templates to support generic numeric range validation.
	- Works as a bridge between user input and business logic.
	- Depends on clsDate and clsString libraries.

	This class represents the Validation Layer
	in the C++ Core Concepts learning path.
*/

class clsInputValiDate
{
public:
	template<typename T>
	static bool isNumberBeteen(T number, T from, T to) {
		return (number >= from and number <= to) ? true : false;
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
		int number = readInt("invalid number:inter number");
		while (!isNumberBeteen(number, from, to)) {
			cout << errorMassage;
			number = readInt("invalid number:inter number");
		}
		return number;

	}

	static double readDouble(string errorMassge) {
		double number;
		cout << "inter number:"; cin >> number;
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


	// why you make copy you can call her only
	static bool isValideDate(clsDate yourDate) {
		return clsDate::ValideDate(yourDate);
	}
	//there are many condition take it in cary
	static bool isDatebetween(clsDate date, clsDate from, clsDate to) {
		if (clsDate::Date1AfterDate2(from, to)) {
			clsDate::swapDates(from, to);
		}
		if ((clsDate::Date1AfterDate2(date, from) || clsDate::isDate1EquelDate2(date, from))
			&& (clsDate::isDate1BeforeDate2(date, to) || clsDate::isDate1EquelDate2(date, to))) {
			return true;
		}
		return false;

	}




};

