#pragma once
#include<iostream>
//#include<ctime>
//#include<cstdlib>
#include"clsDate.h"
#include "clsString.h"
using namespace std;
class clsUtil
{
public:

	static void Srand() {
		srand(time(NULL));
	}
    static enum enChartype { small_letter = 1, capital_leatter = 2, special_character = 3, digit = 4,mixChar=5 };

	static int randomNumber(int your_from, int your_to) {
		int random = rand() % (your_to - your_from + 1) + your_from;
		return random;
	}

    static char getNumberChar(enChartype your_type) {
        if (your_type == enChartype::mixChar) {
            your_type = enChartype(randomNumber(1, 4));
        }
      char random;
        if (your_type == enChartype::small_letter) {
            random = randomNumber(97, 122);
        }
        else if (your_type == enChartype::capital_leatter) {
            random = randomNumber(65, 90);
        }
        else if (your_type == enChartype::special_character) {
            random = randomNumber(32, 47);
        }
        else {
            random = randomNumber(48, 57);
        }
        return char(random);
    }

    static string genarateWord(enChartype your_type, int your_length) {
        string worde = "";
        for (int i = 0; i < your_length; i++) {
            worde = worde + getNumberChar(your_type);
        }
        return worde;
    }

    

    static string genarateKey(enChartype your_type) {
        string key = "";
        key = key + genarateWord(your_type, 4) + "-";
        key = key + genarateWord(your_type, 4) + "-";
        key = key + genarateWord(your_type, 4) + "-";
        key = key + genarateWord(your_type, 4);

        return key;
    }

    static void genarateKeys(int your_number,enChartype your_type) {
        for (int i = 0; i < your_number; i++) {
            cout << "key[" << i + 1 << "]:" << genarateKey(your_type) << "\n";
        }
    }

    static void fullArryWitheRandomKeys(string your_arry[100], int& your_size,enChartype your_type) {
        cout << "please inter your size:"; cin >> your_size;

        for (int i = 0; i < your_size; i++) {
            your_arry[i] = genarateKey(your_type);
        }
    }
    static void fullArryWitheRandomNumbers(int your_arry[100], int& your_size, int from,int to) {
        cout << "please inter your size:"; cin >> your_size;

        for (int i = 0; i < your_size; i++) {
            your_arry[i] = randomNumber(from,to);
        }
    }
    static void fullArryWitheRandomWords(string your_arry[100], int& your_size, enChartype your_type,int word_lenght) {
        cout << "please inter your size:"; cin >> your_size;

        for (int i = 0; i < your_size; i++) {
            your_arry[i] = genarateWord(your_type, word_lenght);
        }
    }

    static void swap(int& number3, int& number4) {
        int temp = number3;
        number3 = number4;
        number4 = temp;

    }
    static void swap(double& number3, double& number4) {
        double temp = number3;
        number3 = number4;
        number4 = temp;

    }
    static void swap(bool& number3, bool& number4) {
        bool temp = number3;
        number3 = number4;
        number4 = temp;

    }
    static void swap(char& number3, char& number4) {
        char temp = number3;
        number3 = number4;
        number4 = temp;

    }
    static void swap(string& number3, string& number4) {
        string temp = number3;
        number3 = number4;
        number4 = temp;

    }

    static void shuffleArray(int your_arry[], int your_size) {

        for (int i = 0; i < your_size; i++) {

            swap(your_arry[randomNumber(0, your_size - 1)], your_arry[randomNumber(0, your_size - 1)]);

        }
    }
    static void shuffleArray(string your_arry[], int your_size) {

        for (int i = 0; i < your_size; i++) {

            swap(your_arry[randomNumber(0, your_size - 1)], your_arry[randomNumber(0, your_size - 1)]);

        }
    }


    static string encription(string your_name, int your_encriptionkey=3) {
        for (int i = 1; i <= your_name.length(); i++) {
            your_name[i] = char((int)your_name[i] + your_encriptionkey);
        }
        return your_name;
    }
   static  string decription(string your_name, int your_encriptionkey=3) {
        for (int i = 1; i <= your_name.length(); i++) {
            your_name[i] = char((int)your_name[i] - your_encriptionkey);
        }
        return your_name;
    }

   static string NumberToText(int Number) {
       if (Number == 0) {
           return"";
       }

       if (Number >= 1 && Number <= 19) {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
               "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen",
               "Seventeen","Eighteen","Nineteen" };
           return  arr[Number] + " ";
       }

       if (Number >= 20 && Number <= 99) {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199) {
           return"One Hundred " + NumberToText(Number % 100);
       }
       if (Number >= 200 && Number <= 999) {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }
       if (Number >= 1000 && Number <= 1999) {
           return"One Thousand " + NumberToText(Number % 1000);
       }
       if (Number >= 2000 && Number <= 999999) {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }
       if (Number >= 1000000 && Number <= 1999999) {
           return"One Million " + NumberToText(Number % 1000000);
       } if (Number >= 2000000 && Number <= 999999999) {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }
       if (Number >= 1000000000 && Number <= 1999999999) {
           return"One Billion " + NumberToText(Number % 1000000000);
       }
       else {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }
   }





};



