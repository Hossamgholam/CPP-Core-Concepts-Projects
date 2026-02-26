#pragma once
#include<iostream>
#include<ctime>
//#include<cstdlib>
#include"clsDate.h"
#include "clsString.h"
#include<fstream>
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
class clsUtil
{
public:

    static void Srand() {
        srand(time(NULL));
    }
    static enum enChartype { small_letter = 1, capital_leatter = 2, special_character = 3, digit = 4, mixChar = 5 };

    static int randomNumber(int from, int to) {
        int random = rand() % (to - from + 1) + from;
        return random;
    }

    //function to get random small letter, capital letter, special character, digit
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


    //function to generate word of small letter, capital letter, special character, digit
    //withe specified length
    static string genarateWord(enChartype your_type, int your_length) {
        string worde = "";
        for (int i = 0; i < your_length; i++) {
            worde = worde + getNumberChar(your_type);
        }
        return worde;
    }

    //function to generate key like XXXX-XXXX-XXXX-XXXX 
    static string genarateKey(enChartype your_type) {
        string key = "";
        key = key + genarateWord(your_type, 4) + "-";
        key = key + genarateWord(your_type, 4) + "-";
        key = key + genarateWord(your_type, 4) + "-";
        key = key + genarateWord(your_type, 4);

        return key;
    }

    //function to generate n keys
    static void genarateKeys(int your_number, enChartype your_type) {
        for (int i = 0; i < your_number; i++) {
            cout << "key[" << i + 1 << "]:" << genarateKey(your_type) << "\n";
        }
    }

    /// <summary>
    /// Applies a simple character-shift 'encryption' to a copy of the input string by adding the encryption key to each character. Note: the implementation uses 1-based indexing, which skips the first character and may cause out-of-bounds access (undefined behavior).
    /// </summary>
    /// <param name="your_name">The input string to be encrypted. It is passed by value and a modified copy is returned.</param>
    /// <param name="your_encriptionkey">An integer value added to each character's code to produce the shifted (encrypted) character.</param>
    /// <returns>A new string with characters shifted by the provided key. Due to the loop's 1-based indexing, the first character remains unchanged and the code may exhibit undefined behavior from out-of-range access.</returns>
    static string encription(string your_name, int your_encriptionkey) {
        for (int i = 1; i <= your_name.length(); i++) {
            your_name[i] = char((int)your_name[i] + your_encriptionkey);
        }
        return your_name;
    }
    static  string decription(string your_name, int your_encriptionkey) {
        for (int i = 1; i <= your_name.length(); i++) {
            your_name[i] = char((int)your_name[i] - your_encriptionkey);
        }
        return your_name;
    }




    ///###########################################useful function for array#############################################

    static void fullArryWitheRandomKeys(string your_arry[100], int& your_size, enChartype your_type) {
        cout << "please inter your size:"; cin >> your_size;

        for (int i = 0; i < your_size; i++) {
            your_arry[i] = genarateKey(your_type);
        }
    }

    static void fullArryWitheRandomNumbers(int your_arry[100], int& your_size, int from, int to) {
        cout << "please inter your size:"; cin >> your_size;

        for (int i = 0; i < your_size; i++) {
            your_arry[i] = randomNumber(from, to);
        }
    }

    static void fullArryWitheRandomWords(string your_arry[100], int& your_size, enChartype your_type, int word_lenght) {
        cout << "please inter your size:"; cin >> your_size;

        for (int i = 0; i < your_size; i++) {
            your_arry[i] = genarateWord(your_type, word_lenght);
        }
    }

    template <typename T>
    static void shuffleArray(T your_arry[], int your_size) {

        for (int i = 0; i < your_size; i++) {

            swap(your_arry[randomNumber(0, your_size - 1)], your_arry[randomNumber(0, your_size - 1)]);

        }
    }

    template <typename T>
    static void copy_arry(T your_arry[100], T your_new_arry[100], int your_size) {
        for (int i = 0; i < your_size; i++) {
            your_new_arry[i] = your_arry[i];
        }
    }

    static int postion(int your_arry[100], int your_search, int your_size) {
        int found = -1;
        for (int i = 0; i < your_size; i++) {
            if (your_arry[i] == your_search) {
                found = i;
                return found;
            }
        }
        return found;
    }
    static bool is_found(int your_arry[100], int your_search, int your_size) {
        return postion(your_arry, your_search, your_size) != -1;
    }
    static bool is_palindrom(int your_array[100], int your_size) {
        bool palind = true;
        for (int i = 0; i < your_size / 2; i++) {
            if (your_array[i] != your_array[your_size - i - 1]) {
                palind = false;
                return palind;
            }
        }
        return palind;
    }


    //#######################useful function for matrix####################


    static void full_matrix(int your_matrix[3][3], int your_row, int your_colum) {
        for (int i = 0; i < your_row; i++) {
            for (int y = 0; y < your_colum; y++) {
                your_matrix[i][y] = randomNumber(1, 100);
            }
        }
    }


    static int sum_row(int your_matrix[3][3], int number_row, int colum) {
        int sum = 0;
        for (int y = 0; y < colum; y++) {
            sum += your_matrix[number_row][y];
        }
        return sum;
    }
    static void storage_each_row(int your_matrix[3][3], int your_array[3], int row, int colum) {
        for (int i = 0; i < row; i++) {
            your_array[i] = sum_row(your_matrix, i, colum);
        }
    }


    static int sum_colom(int your_matrix[3][3], int row, int number_colum) {
        int sum = 0;
        for (int y = 0; y < row; y++) {
            sum += your_matrix[y][number_colum];
        }
        return sum;
    }
    static void storage_sum_colom(int your_matrix[3][3], int row, int colum, int your_array[3]) {
        for (int i = 0; i < colum; i++) {
            your_array[i] = sum_colom(your_matrix, row, i);
        }
    }

    static int sum_matrix(int your_matrix[3][3], int row, int colum) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                sum += your_matrix[i][y];
            }
        }
        return sum;
    }
    static bool is_equal_matrixs(int your_matrix1[3][3], int your_matrix2[3][3], int row, int colum) {
        return (sum_matrix(your_matrix1, row, colum) == sum_matrix(your_matrix2, row, colum));


    }

    static bool typical_matrix(int your_matrix[3][3], int my_matrix[3][3], int row, int colum) {

        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (your_matrix[i][y] != my_matrix[i][y]) {
                    return false;

                }
            }
        }
        return true;
    }

    static bool check1(int your_matrix[3][3], int row, int colum) {
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (i == y) {
                    if (your_matrix[i][y] != 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    static bool check0(int your_matrix[3][3], int row, int colum) {
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (i != y) {
                    if (your_matrix[i][y] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    static bool check_identity(int your_matrix[3][3]) {
        bool condation1 = check1(your_matrix, 3, 3);
        bool condation2 = check0(your_matrix, 3, 3);
        if (condation1 && condation2 == true) {
            return true;
        }
        else {
            return false;
        }
    }

    static bool scalar_matrix(int your_matrix[3][3], int row, int colum) {
        int scal = your_matrix[0][0];
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (i == y && your_matrix[i][y] != scal) {
                    return false;
                }
                else if (i != y && your_matrix[i][y] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    static int countNumber(int your_matrix[3][3], int row, int colum, int number) {
        int counter = 0;
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (your_matrix[i][y] == number) {
                    counter++;
                }
            }
        }
        return counter;
    }

    static bool exists(int your_matrix[3][3], int row, int colum, int number) {

        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (your_matrix[i][y] == number) {
                    return true;
                }
            }
        }
        return false;
    }

    static int max_number(int your_matrix[3][3], int row, int colum) {
        int max_number = INT_MIN;
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (your_matrix[i][y] > max_number) {
                    max_number = your_matrix[i][y];
                }
            }
        }
        return max_number;
    }
    static int min_number(int your_matrix[3][3], int row, int colum) {
        int min_number = INT_MAX;
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum; y++) {
                if (your_matrix[i][y] < min_number) {
                    min_number = your_matrix[i][y];
                }
            }
        }
        return min_number;
    }

    static bool palindrom(int your_matrix[3][3], int row, int colum) {
        for (int i = 0; i < row; i++) {
            for (int y = 0; y < colum / 2; y++) {
                if (your_matrix[i][y] != your_matrix[i][colum - y - 1]) {
                    return false;
                }
            }
        }
        return true;
    }



    //#######################useful function for matrix####################



    template <typename T>
    static void swap(T& number3, T& number4) {
        T  temp = number3;
        number3 = number4;
        number4 = temp;

    }

    static bool isPerfectNumber(int your_number) {
        int sum = 0;
        for (int i = 1; i < your_number; i++) {
            if (your_number % i == 0) {
                sum += i;
            }
        }
        if (sum == your_number) {
            return true;
        }
        else {
            return false;
        }
    }

    static int revers_number(int your_numbrer) {
        int remind = 0, number_revers = 0;
        while (your_numbrer > 0) {
            remind = your_numbrer % 10;
            your_numbrer /= 10;
            number_revers = number_revers * 10 + remind;

        }
        return number_revers;
    }

    static bool is_palindrom(int your_number) {
        return your_number == revers_number(your_number);
    }

    static int number_frecquency(int your_number, int your_digit) {
        int frecquency = 0;
        while (your_number > 0) {
            int remaind = 0;
            remaind = your_number % 10;
            your_number /= 10;

            if (your_digit == remaind) {
                frecquency++;
            }

        }
        return frecquency;
    }


};

