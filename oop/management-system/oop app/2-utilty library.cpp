#include <iostream>
#include"clsUtil.h"
#include"clsIputValiDate.h"
using namespace std;

int main(){
    cout << clsIputValiDate::isNumberBeteen(4, 1, 10)<<endl;
    cout << clsIputValiDate::isNumberBeteen(2.2, 1.1, 10.3) << endl;

    cout << clsIputValiDate::isDatebetween(clsDate(), clsDate(20, 5, 2225), clsDate(1, 5, 2025)) << endl;

    cout << "please inter number:";
    int n = clsIputValiDate::readInt("invalid number:inter number");
    cout << n << endl;

    cout << "please inter number between(1,5):";
    int w = clsIputValiDate::readIntNumberBetween(1, 5, "number not in range:inter number in range:");
    cout << w;

    cout << endl << endl;


    cout << "please inter number:";
    double p = clsIputValiDate::readDouble("invalid number:inter number");
    cout << p << endl;

    cout << "please inter number between(1,5):";
    int y = clsIputValiDate::readDoubleNumberBetween(1, 5, "number not in range:inter number in range:");
    cout << y;

}

