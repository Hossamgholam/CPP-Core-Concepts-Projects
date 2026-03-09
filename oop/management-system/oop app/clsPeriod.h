#pragma once
#include<iostream>
#include"clsString.h"
#include"clsDate.h"
using namespace std;
class clsPeriod
{
private:
	clsDate _startDate;
	clsDate _endDate;
public:
	clsPeriod() {

	}
	clsPeriod(clsDate startDate, clsDate endDate) {
		_startDate = startDate;
		_endDate = endDate;
	}
	clsPeriod(string startDate, string endDate) {
		_startDate = clsDate(startDate);
		_endDate = clsDate(endDate);
	}
	clsPeriod(short date1Day, short date1Monthe, short date1Year,
		short date2Day, short date2Monthe, short date2Year) {
		_startDate = clsDate(date1Day, date1Monthe, date1Year);
		_endDate = clsDate(date2Day, date2Monthe, date2Year);
	}
	clsPeriod(short numberOfDayDate1, short yearDate1,
		short numberOfDayDate2, short yearDate2) {
		_startDate = clsDate(numberOfDayDate1, yearDate1);
		_endDate = clsDate(numberOfDayDate2, yearDate2);
	}
	// you can make it by refrence to make it fast but 
	//when you settartdate withou declarition it make earro beacaus
	//by refernc point to object exsite in memory

	void setStartDate(clsDate yourStartDate) {
		_startDate = yourStartDate;
	}
	clsDate getStartDate() {
		return _startDate;
	}

	void setEndDate(clsDate yourEndDate) {
		_endDate = yourEndDate;
	}
	clsDate getEndDate() {
		return _endDate;
	}

	__declspec(property(get = getStartDate, put = setStartDate))clsDate startDate;
	__declspec(property(get = getEndDate, put = setEndDate))clsDate endDate;

	static bool isOverlapPeriods(clsPeriod period1, clsPeriod period2) {
		if (clsDate::comparDate(period1.endDate, period2.startDate) == clsDate::Encompar::before || clsDate::comparDate(period1.startDate, period2.endDate) ==
			clsDate::Encompar::after) {
			return false;
		}
		else {
			return true;
		}
	}
	bool isOverlapPeriods(clsPeriod period2) {
		return isOverlapPeriods(*this, period2);
	}

	static short PeriodLenghtINDay(clsPeriod period1, bool includelastday = false) {
		return clsDate::getDifferenceInDays(period1.startDate, period1.endDate, includelastday);
	}
	short PeriodLenghtINDay() {
		return PeriodLenghtINDay(*this, true);
	}

	static bool IsDateWithinPeriod(clsPeriod period1, clsDate date) {

		return !(clsDate::comparDate(date, period1.startDate) == clsDate::Encompar::before || clsDate::comparDate(date, period1.endDate) == clsDate::Encompar::after);

	}
	bool IsDateWithinPeriod(clsDate date) {
		return IsDateWithinPeriod(*this, date);
	}
	//static short CountOverlap(clsPeriod& period1, clsPeriod& period2) {
	//	short counter = 0;
	//	short lengthperiod1 = PeriodLenghtINDay(period1, true);
	//	short lengthperiod2 = PeriodLenghtINDay(period2, true);

	//	if (!isOverlapPeriods(period1, period2)) {
	//		return 0;
	//	}
	//	if (lengthperiod1 < lengthperiod2) {
	//		while (clsDate::isDate1BeforeDate2(period1.startDate, period1.endDate)) {
	//			if (IsDateWithinPeriod(period2, period1.startDate)) {
	//				counter++;
	//			}
	//			clsDate d = period1.startDate;//this line beacuse 
	//			clsDate::addOneDay(d);
	//		}

	//	}
	//	else {
	//		while (date1_lessthane_date2(period2.start, period2.end)) {
	//			if (IsDateWithinPeriod(period1, period2.start)) {
	//				counter++;
	//			}
	//			add_day_to_date(period2.start);
	//		}
	//	}
	//	return counter;
	//}
	void print() {
		cout << "the startDate is:"; _startDate.print();
		cout << endl;
		cout << "the endDate is :"; _endDate.print();
	}
};


