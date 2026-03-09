#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include"clsString.h"
#include<string>
#include<vector>
#include<ctime>
using namespace std;
class clsDate
{
private:
	short _day;
	short _monthe;
	short _year;
public:
	clsDate() {
        time_t t = time(NULL);
        tm* now;
        now = localtime(&t);

        _year = now->tm_year + 1900;
        _monthe = now->tm_mon + 1;
        _day = now->tm_mday;
	}
    clsDate(string date) {
        vector<string>storge;
        storge = clsString::split(date, "/");
        _day = stoi(storge.at(0));
        _monthe = stoi(storge.at(1));
        _year = stoi(storge.at(2));
    }
    clsDate(short day, short monthe, short year) {
        _day = day;
        _monthe = monthe;
        _year = year;
    }
    clsDate(short numberOfDay, short year) {
        clsDate date = getDateFromOrderInYear(numberOfDay, year);
        _day = date.day;
        _monthe = date.monthe;
        _year = date.year;
    }
    void setDay(short day) {
        _day = day;
    }
    short getDay() {
        return _day;
    }

    void setMonthe(short monthe) {
        _monthe = monthe;
    }
    short getMonthe() {
        return _monthe;
    }
    
    void setYear(short year) {
        _year = year;
    }
    short getYear() {
        return _year;
    }
    
    __declspec(property(get = getDay, put = setDay))short day;
    __declspec(property(get = getMonthe, put = setMonthe))short monthe;
    __declspec(property(get = getYear, put = setYear))short year;
    void print() {
        cout << to_string(_day) + "/" +to_string( _monthe) + "/" +to_string( _year);
    }

    static clsDate system_date() {
        clsDate date;
        time_t t = time(NULL);
        tm* now;
        now = localtime(&t);

        date.year = now->tm_year + 1900;
        date.monthe = now->tm_mon + 1;
        date.day = now->tm_mday;
        return date;
    }

    //function return date and time in string formate
    static string getSystemDateTimeString() {
       
        time_t t = time(NULL);
        tm* now;
        now = localtime(&t);

        short year = now->tm_year + 1900;
        short monthe = now->tm_mon + 1;
        short day = now->tm_mday;
        short houre = now->tm_hour;
        short munite = now->tm_min;
        short second = now->tm_sec;

        return (to_string(day) + "/" + to_string(monthe) + "/"
            + to_string(year) + " - "
            + to_string(houre) + ":"
            + to_string(munite) + ":"
            + to_string(second));

    }
    
    static bool isLeapYear(short your_year) {
        return  (your_year % 400 == 0 || (your_year % 4 == 0 && (your_year % 100 != 0))) ? true : false;
    }
    bool isLeapYear() {
        return isLeapYear(_year);
    }
    
    
    
    static clsDate getDateFromOrderInYear(short your_number, short your_year) {

        clsDate your_date;
        short number_day_inmonthe = 0;
        your_date.monthe = 1;
        while (true) {
            number_day_inmonthe = numberOfDaysInMonthe(your_year, your_date.monthe);
            if (your_number > number_day_inmonthe) {
                your_number -= number_day_inmonthe;
                your_date.monthe++;
            }
            else {
                your_date.day = your_number;
                break;
            }

        }
        your_date.year = your_year;
        return your_date;
    }
    //we dont make nonstatic because constractor apply same function


    /*number of day hour miinutes second in year*/
    static short numberOfDayInYear(short yourYear) {
        return isLeapYear(yourYear) ? 366 : 365;
    }
    short numberOfDayInYear() {
        return numberOfDayInYear(_year);
    }

    static int numberOfHourInYear(short yourYear) {
        return numberOfDayInYear(yourYear) * 24;
    }
    int numberOfHourInYear() {
        return numberOfHourInYear(_year);
    }

    static int numberOfMinutesInYear(short yourYear) {
        return numberOfHourInYear(yourYear) * 60;
    }
    int numberOfMinutesInYear() {
        return numberOfMinutesInYear(_year);
    }

    static int numberOfSecondInYear(short yourYear) {
        return numberOfMinutesInYear(yourYear) * 60;
    }
    int numberOfSecondInYear() {
        return numberOfSecondInYear(_year);
    }


    /*number of day hour minutes in monthe*/
    static short numberOfDaysInMonthe(short your_year, short your_monthe) {
        if (your_monthe < 1 || your_monthe>12) {
            return 0;
        }
        short arrydaymonthe[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        short number_day = (your_monthe == 2) ? (isLeapYear(your_year) ? 29 : 28) : arrydaymonthe[your_monthe - 1];
        return number_day;
    }
    short numberOfDaysInMonthe() {
        return numberOfDaysInMonthe(_year, _monthe);
    }
    
    static int numberOfHourInMonthe(short your_year, short your_monthe) {
        return numberOfDaysInMonthe(your_year, your_monthe) * 24;
    }
    int numberOfHourInMonthe() {
        return numberOfHourInMonthe(_year, _monthe);
    }

    static int numberOfMinutesInMonthe(short your_year, short your_monthe) {
        return numberOfHourInMonthe(your_year, your_monthe) * 60;
    }
    int numberOfMinutesInMonthe() {
        return numberOfMinutesInMonthe(_year, _monthe);
    }

    static int numberOfSecondInMonthe(short your_year, short your_monthe) {
        return numberOfMinutesInMonthe(your_year, your_monthe) * 60;
    }
    int numberOfSecondInMonthe() {
        return numberOfSecondInMonthe(_year, _monthe);
    }

    /*day order in weak and short name*/
    static short dayOfWeakOrder(short year, short monthe, short day=1) {
        short a = (14 - monthe) / 12;
        short y = year - a;
        short m = monthe + (12 * a) - 2;
        return(day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


    }
    short dayOfWeakOrder() {
        return dayOfWeakOrder(_year, _monthe, _day);
    }

    static string dayShortName(short dayOfWeakOrder) {
        string arraday[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arraday[dayOfWeakOrder];
    }
    //donot make static becaus objet donnot have properoty of dayofweakorder

    // the defrint in thes it call dayofweakorder in side it so we can do fuction for object
    static string dayShortName(short year, short monthe, short day) {
        string arraday[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arraday[dayOfWeakOrder(year, monthe, day)];

    }
    string dayShortName() {

        return dayShortName(_year, _monthe, _day);
    }

    //calande of monthe and year
    static string montheShortName(short monthe_number) {
        string arraday[12] = { "January", "February", "March", "April", "May", "June", "July", "August"," September", "October", "November", "December" };
        return arraday[monthe_number - 1];
    }
    string montheShortName() {
        return montheShortName(_monthe);
    }

    static void printMontheCalender(short your_monthe, short your_year) {
        short number_day = numberOfDaysInMonthe(your_year, your_monthe);
        short start_day = dayOfWeakOrder(your_year, your_monthe);
        printf("_________________________%s______________________\n", montheShortName(your_monthe).c_str());

        printf("  sun  mon  tue  wed  thu  fri  sat\n");
        int i;
        for (i = 0; i < start_day; i++)
            printf("     ");

        for (short y = 1; y <= number_day; y++) {
            printf("%5d", y);

            if (++i == 7) {
                i = 0;
                cout << endl;
            }

        }
    }
    void printMontheCalender() {
        return printMontheCalender(_monthe, _year);
    }

    static void printYearCalendar(short your_year) {
        cout << "_____________________________________________________________\n";
        cout << "                 calander_" << your_year << "                    \n";
        cout << "_____________________________________________________________\n\n";
        for (int i = 1; i < 12; i++) {

            printMontheCalender(i, your_year);
            cout << "\n______________________________________________________\n\n";

        }

    }
    void printYearCalendar() {
        return printYearCalendar(_year);
    }


    static short daysFrombeginingOfYear(short your_year, short your_monthe, short your_day) {
        short total_day = 0;
        for (short i = 1; i <= your_monthe - 1; i++) {
            total_day += numberOfDaysInMonthe(your_year, i);
        }
        total_day += your_day;
        return total_day;
    }
    //number_day_biging_year
    short daysFrombeginingOfYear() {
        return daysFrombeginingOfYear(_year, _monthe, _day);
    }
    //add_day_todate
    //incressXday
    void addDays(short your_number ) {


        short number_day_inmonthe = 0;
        short number_of_day = your_number + daysFrombeginingOfYear(_year, _monthe, _day);
        _monthe = 1;
        while (true) {
            number_day_inmonthe = numberOfDaysInMonthe(_year, _monthe);
            if (number_of_day > number_day_inmonthe) {
                number_of_day -= number_day_inmonthe;
                _monthe++;
                if (_monthe > 12) {
                    _year++;
                    _monthe = 1;
                }
            }
            else {
                _day = number_of_day;
                break;
            }

        }

        
    }
    

    // is current date object is equal or befor date two
    //and use *this pointer
    static bool isDate1BeforeDate2(clsDate date1, clsDate date2) {
      
        return (date1.year < date2.year ? true : (date1.year == date2.year ? (date1.monthe < date2.monthe ? true : (date1.monthe == date2.monthe ? date1.day < date2.day : false)) : false));
    }
     bool isDate1BeforeDate2(clsDate date2) {
         return isDate1BeforeDate2(*this, date2);
    }

    static bool isDate1EquelDate2(clsDate date1, clsDate date2) {
         
         return (date1._year == date2._year ? (date1._monthe == date2._monthe ? (date1._day == date2._day ? true : false) : false) : false);
     }
    bool isDate1EquelDate2(clsDate date2) {
        return isDate1EquelDate2(*this, date2);
    }

    //if is last day in monthe or year
    //consept of this pointer
    //non static is lastmonthe add from me
    static bool isLastDayInMonthe(clsDate your_date) {
        return (numberOfDaysInMonthe(your_date.year, your_date.monthe) == your_date.day);
    }
    bool isLastDayInMonthe() {
        return isLastDayInMonthe(*this);
    }
    static bool isLastMontheInYear(short your_monthe) {
        return (your_monthe == 12);
    }
    bool isLastMontheInYear() {
        return isLastMontheInYear(_monthe);
    }
    
    //add_day_to_date
    static clsDate addOneDay(clsDate& your_date) {
        if (isLastDayInMonthe(your_date)) {
            if (isLastMontheInYear(your_date.monthe)) {
                your_date.year++;
                your_date.monthe = 1; your_date.day = 1;
            }
            else {
                your_date.day = 1;
                your_date.monthe++;
            }
        }
        else {
            your_date.day++;
        }
        return your_date;
    }
    clsDate addOneDay() {
        return addOneDay(*this);
    }

    static void swapDates(clsDate& your_data1, clsDate& your_data2) {
        clsDate tempdate;

        tempdate = your_data1;
        your_data1 = your_data2;
        your_data2 = tempdate;
    }
    static int  getDifferenceInDays(clsDate your_date1, clsDate your_date2, bool include_end_day = false) {
    

        int differ=0;
        short swapflagevalue = 1;
        if (!isDate1BeforeDate2(your_date1, your_date2)) {
            swapDates(your_date1, your_date2);
            swapflagevalue = -1;
        }
        while (isDate1BeforeDate2(your_date1, your_date2)) {
            differ++;
            your_date1=addOneDay(your_date1);
        }

        return include_end_day ? ++differ * swapflagevalue : differ * swapflagevalue;

    }
    int  getDifferenceInDays(clsDate date2,bool encludeEndDay=false) {
        return getDifferenceInDays(*this, date2, encludeEndDay);
    }

    static int  calculateMyAgeInDays(clsDate myBirtheDay) {
       return getDifferenceInDays(myBirtheDay, clsDate::system_date(), true);
    }

    //increase date
    // i make it return if i need to save new value to make some process and
    // keep reference to make change direct and not need to assin it in nonstatic function

    //it like to addDays but different code
    static clsDate increaseDateByXDay(short number_day, clsDate& your_date) {
        for (int i = 0; i < number_day; i++) {
           your_date= addOneDay(your_date);//we can make it addoneDay(your_date) only for all fuction byx
        }
        return your_date;
    }
    void increaseDateByXDay(short numberOfDay) {
        increaseDateByXDay(numberOfDay, *this);
    }

    static clsDate increaseDateByOneWeak(clsDate& your_date) {
        for (int i = 0; i < 7; i++) {
            your_date=addOneDay(your_date);
        }
        return your_date;
        
    }
    void increaseDateByOneWeak() {
        increaseDateByOneWeak(*this);// donot need to declaration it because referenc
    }

    static clsDate increaseDateByXWeak(short number_weak, clsDate& your_date) {
        for (int i = 0; i < number_weak; i++) {
            your_date=increaseDateByOneWeak(your_date);
        }
        return your_date;
    }
    void increaseDateByXWeak(short numberOfWeek) {
        increaseDateByXWeak(numberOfWeek, *this);
    }

    static clsDate increaseDateByOneMonthe(clsDate& your_date) {
        if (your_date.monthe == 12) {
            your_date.year++;
            your_date.monthe = 1;
        }
        else {
            your_date.monthe++;
        }
        short day_next_monthe = numberOfDaysInMonthe(your_date.year, your_date.monthe);
        if (your_date.day > day_next_monthe) {
            your_date.day = day_next_monthe;
        }
        return your_date;
    }
    void increaseDateByOneMonthe() {
        increaseDateByOneMonthe(*this);
    }

    static clsDate increaseDateByXMonthe(short number_monthe, clsDate& your_date) {
        for (short i = 0; i < number_monthe; i++) {
            increaseDateByOneMonthe(your_date);
        }
        return your_date;
    }
    void increaseDateByXMonthe(short nubmerOfMonthe){
        increaseDateByXMonthe(nubmerOfMonthe, *this);
    }

    static clsDate increaseDateByOneYear(clsDate& your_date) {
        short day_monthe = numberOfDaysInMonthe(your_date.year, your_date.monthe);
        your_date.year++;
        if (your_date.monthe == 2 && your_date.day == day_monthe) {/*check if it monthe 2 and is last day in month neithe 28 or29 in year befor increse*/
            your_date.day = numberOfDaysInMonthe(your_date.year, your_date.monthe);/*it correct day if year aftar incres is leap year it reterun 29 not lepp year return 28*/
            /* befor incress  if it leap year 28
               after incress if it leap year it reread it 28 also

               befor incress if it leap year 28
               after incress if it not leap year it read it 29
               */
        }
        return your_date;
    }
    void increaseDateByOneYear() {
        increaseDateByOneYear(*this);
    }


    static clsDate increaseDateByXYear(short YourNumber, clsDate& YourDate) {
        YourDate.year += YourNumber;
        return YourDate;
    }
    void increaseDateByXYear(short yourNumber) {
        increaseDateByXYear(yourNumber, *this);
    }

    

    static clsDate increaseDateByOneDecade(clsDate& YourDate) {
        YourDate.year += 10;
        return YourDate;
    }
    void increaseDateByOneDecade() {
        increaseDateByOneDecade(*this);
    }

    static clsDate increaseDateByXDecade(short YourNumber, clsDate& YourDate) {
        YourDate.year += (YourNumber * 10);
        return YourDate;
    }
    void increaseDateByXDecade(short yourNumber) {
        increaseDateByXDecade(yourNumber, *this);
    }
    

    static clsDate increaseDateByCentury(clsDate& YourDate) {
        YourDate.year += 100;
        return YourDate;
    }
    void increaseDateByCentury() {
        increaseDateByCentury(*this);
    }

    static clsDate increaseDateBymillennium(clsDate& YourDate) {
        YourDate.year += 1000;
        return YourDate;
    }
    void increaseDateBymillennium() {
        increaseDateBymillennium(*this);
    }

    //decreasedate
    
    static clsDate DecreaseOneDay(clsDate& your_date) {
        if (your_date.day == 1) {
            if (your_date.monthe == 1) {
                your_date.year--;
                your_date.monthe = 12;
                your_date.day = 31;
            }
            else {
                your_date.monthe--;
                your_date.day = numberOfDaysInMonthe(your_date.year, your_date.monthe);
            }
        }
        else {
            your_date.day--;
        }
        return your_date;
    }
    void  DecreaseOneDay() {
        DecreaseOneDay(*this);
    }

    static clsDate DecreaseXDay(short YourNumber, clsDate& your_date) {
        for (int i = 0; i < YourNumber; i++) {
            DecreaseOneDay(your_date);
        }
        return your_date;
    }
    void DecreaseXDay(short yourNumber) {
        DecreaseXDay(yourNumber,*this);
    }
   
    static clsDate DecreaseOneWeake(clsDate& your_date) {
        for (int i = 0; i < 7; i++) {
            DecreaseOneDay(your_date);
        }
        return your_date;
    }
    void DecreaseOneWeake() {
        DecreaseOneWeake( *this);
    }

    static clsDate DecreaseXWeake(short number_weak, clsDate& your_date) {
        for (int i = 0; i < number_weak; i++) {
            DecreaseOneWeake(your_date);
        }
        return your_date;
    }
    void DecreaseXWeake(short yourNumber) {
        DecreaseXWeake(yourNumber, *this);
    }

    static clsDate DecreaseOneMonthe(clsDate& your_date) {
        if (your_date.monthe == 1) {
            your_date.year--;
            your_date.monthe = 12;
        }
        else {
            your_date.monthe--;
        }
        short day_previous_monthe = numberOfDaysInMonthe(your_date.year, your_date.monthe);
        if (your_date.day > day_previous_monthe) {
            your_date.day = day_previous_monthe;
        }
        return your_date;
    }
    void DecreaseOneMonthe() {
        DecreaseOneMonthe(*this);
    }

    static clsDate DecreaseXMonthe(short number_monthe, clsDate& your_date) {
        for (short i = 0; i < number_monthe; i++) {
            DecreaseOneMonthe(your_date);
        }
        return your_date;
    }
    void DecreaseXMonthe(short yourNumber) {
        DecreaseXMonthe(yourNumber, *this);
    }

    static clsDate DecreaseOneYear(clsDate& YourDate) {
        YourDate.year--;
        return YourDate;
    }
    void DecreaseOneYear() {
        DecreaseOneYear(*this);
    }
   
    static clsDate DecreaseXYear(short YourNumber, clsDate& YourDate) {
        YourDate.year -= YourNumber;
        return YourDate;
    }
    void DecreaseXYear(short yourNumber) {
        DecreaseXYear(yourNumber, *this);
    }

    static clsDate DecreaseOneDecade(clsDate& YourDate) {
        YourDate.year -= 10;
        return YourDate;
    }
    void DecreaseOneDecade() {
        DecreaseOneDecade(*this);
    }

    static clsDate DecreaseXDecade(short YourNumber, clsDate& YourDate) {
        YourDate.year -= (YourNumber * 10);
        return YourDate;
    }
    void DecreaseXDecade(short yourNumber) {
        DecreaseXDecade(yourNumber, *this);
    }

    static clsDate DecreaseCentury(clsDate& YourDate) {
        YourDate.year -= 100;
        return YourDate;
    }
    void DecreaseCentury() {
        DecreaseCentury(*this);
    }

   static clsDate Decreasemillennium(clsDate& YourDate) {
        YourDate.year -= 1000;
        return YourDate;
    }
   void Decreasemillennium() {
       Decreasemillennium(*this);
   }


   static short DaysUntilTheEndOfMonthe(clsDate YourDate) {
       clsDate date2;
       date2.day = numberOfDaysInMonthe(YourDate.year, YourDate.monthe);
       date2.monthe = YourDate.monthe;
       date2.year = YourDate.year;

       return getDifferenceInDays(YourDate, date2, true);
   }
   short DaysUntilTheEndOfMonthe() {
       return DaysUntilTheEndOfMonthe(*this);
   }

   static short DaysUntilTheEndOfYear(clsDate YourDate) {
       clsDate date2;
       date2.day = 31;
       date2.monthe = 12;
       date2.year = YourDate.year;
       short dif = getDifferenceInDays(YourDate, date2, true);
       return dif;
   }
   short DaysUntilTheEndOfYear() {
       return DaysUntilTheEndOfYear(*this);
   }
   
   static bool isEndOfWeek(clsDate YourDate) {
       short DayOrder = dayOfWeakOrder(YourDate.year, YourDate.monthe, YourDate.day);
       return  DayOrder == 6;
   }
   bool isEndOfWeek() {
       return isEndOfWeek(*this);
   }

   static bool IsWeakEnd(clsDate YourDate) {
       short DayOrder = dayOfWeakOrder(YourDate.year,YourDate.monthe,YourDate.day);
       return DayOrder == 5 || DayOrder == 6;
   }
   bool IsWeakEnd() {
       return IsWeakEnd(*this);
   }


   static bool IsBusinessDay(clsDate YourDate) {
   
       return !IsWeakEnd(YourDate);
   }
   bool IsBusinessDay() {
       return IsBusinessDay(*this);
   }

   //take to date andd claclualt actual work day withou week end
   static short calculateBusinessDays(clsDate YourDate1, clsDate YourDate2) {
       short AcutalDays = 0;
       while (!isDate1EquelDate2(YourDate1, YourDate2)) {
           if (IsBusinessDay(YourDate1)) {
               AcutalDays++;
           }
           addOneDay(YourDate1);
       }
       return AcutalDays;
   }
   // if he want to take vaction calculat bussinessday
   static short ActualVactionDays(clsDate YourDate1, clsDate YourDate2) {
       return calculateBusinessDays(YourDate1, YourDate2);
   }
   //take statr date to vaction and number of actual vaction without week end
   // and add it to date and return date your retrun to worke
   static clsDate VactionReturnDate(clsDate YourDate1, short VactionDays) {
       short weakendcounter = 0;
       while (IsWeakEnd(YourDate1)) {
           addOneDay(YourDate1);
       }
       for (short i = 0; i < VactionDays + weakendcounter; i++) {
           if (IsWeakEnd(YourDate1)) {
               weakendcounter++;
           }
           addOneDay(YourDate1);
       }
       while (IsWeakEnd(YourDate1)) {
           addOneDay(YourDate1);
       }
       return YourDate1;
   }

   static bool Date1AfterDate2(clsDate date1, clsDate date2) {
       return (!isDate1BeforeDate2(date1, date2) && !isDate1EquelDate2(date1, date2));
   }



   enum Encompar { before = -1, equal = 0, after = 1 };
   static Encompar comparDate(clsDate date1, clsDate date2) {
       if (isDate1EquelDate2(date1, date2)) {
           return Encompar::equal;
       }
       else if (isDate1BeforeDate2(date1, date2)) {
           return Encompar::before;
       }
       return Encompar::after;
   }
   Encompar compareDate(clsDate date2) {
       return comparDate(*this, date2);
   }


   static bool ValidDays(clsDate YourDate) {
       short NumberDaysMonthe = numberOfDaysInMonthe(YourDate.year, YourDate.monthe);
       return NumberDaysMonthe == YourDate.day ? true : false;
   }
   bool ValidDays() {
       return ValidDays(*this);
   }
   static bool ValidMonthe(clsDate YourDate) {
       return (YourDate.monthe < 1 || YourDate.monthe>12 ? false : true);
   }
   bool ValidMonthe() {
       return ValidMonthe(*this);
   }
   static bool ValideDate(clsDate YourDate) {
       return (ValidDays(YourDate) && ValidMonthe(YourDate) && YourDate.year > 0) ? true : false;
   }
   bool ValideDate() {
       return ValideDate(*this);
   }

   static string dateToString(clsDate yourDate) {
       return to_string(yourDate.day) + "/" + to_string(yourDate.monthe) + "/" + to_string(yourDate.year) ;
   }

};



