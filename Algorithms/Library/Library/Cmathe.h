#pragma once
#include<iostream>
/*
    Namespace: mathe

    Description:
    A lightweight mathematical utility namespace that provides
    commonly used numeric and geometric operations.

    This namespace is designed to support algorithmic problem solving
    and foundational programming exercises by offering custom
    implementations of math-related functions without relying on
    the C++ standard math library.

    Covered Topics:
    - Rounding operations (ceil, floor, round)
    - Absolute values, power, factorial
    - Basic arithmetic helpers (sum, average, max, min)
    - Geometry calculations (rectangle, triangle, circle)
    - Number theory utilities (odd/even, prime checking)
    - Array-based numeric operations (sum, average, min, max)

    Design Notes:
    - Implemented using a namespace for procedural-style reuse.
    - Focuses on logic implementation rather than performance.
    - Intended for educational purposes and algorithm practice.
    - Complements other utilities such as clsString and Input Validation.

    This library represents the Algorithms & Problem Solving stage
    of the C++ Core Concepts learning path.
*/



namespace mathe {
    float getfractionpart(float your_number) {
        return your_number - int(your_number);
    }
    int my_ceil(float your_number) {
        int intpart;
        intpart = (int)your_number;
        float fractionpart = getfractionpart(your_number);
        if (abs(fractionpart) > 0) {

            if (your_number > 0) {

                return ++intpart;
            }
            else {

                return intpart;
            }
        }
        else {
            return intpart;
        }
    }
    int my_floor(float your_number) {
        int intpart;
        intpart = (int)your_number;


        if (your_number > 0) {

            return intpart;
        }
        else {
            --intpart;
            return intpart;
        }
    }
    int my_round(float your_number) {
        int intpart;
        intpart = (int)your_number;
        float fractionpart = getfractionpart(your_number);
        if (abs(fractionpart) >= 0.5) {
            if (your_number > 0) {
                ++intpart;
                return intpart;
            }
            else {
                --intpart;
                return intpart;
            }
        }
        else {
            return intpart;
        }
    }
    int my_abs(int your_number) {
        if (your_number >= 0) {
            return your_number;
        }
        else {
            return your_number * -1;
        }
    }
    int power(int your_number, int your_power) {
        int result = your_number;
        if (your_power == 1) {
            return your_number;
        }
        else {
            return result * power(your_number, your_power - 1);
        }
    }
    int factoriall(int your_number) {
        int fact = 1;
        if (your_number == 1 || your_number == 0) {
            return fact;
        }
        else {
            for (int i = your_number; i >= 1; i--) {
                fact *= i;
            }
            return fact;
        }
    }


    float divide_number(int your_number) {
        return (float)your_number / 2;
    }


    int calculat_sum(int n1, int n2, int n3) {
        return n1 + n2 + n3;
    }
    float calculat_average(int n1, int n2, int n3) {
        return (float)calculat_sum(n1, n2, n3) / 3;
    }


    int check_max(int n1, int n2) {
        if (n1 > n2) {
            return n1;
        }
        else {
            return n2;
        }
    }
    int check_max(int n1, int n2, int n3) {
        if (n1 > n2) {
            if (n1 > n3) {
                return n1;
            }
            else {
                return n3;
            }
        }
        else {
            if (n2 > n3) {
                return n2;
            }
            else {
                return n3;
            }
        }
    }


    float rectangle_area(float length, float width) {
        return length * width;
    }
    float rectangle_perimeter(float length, float width) {
        return 2 * (length + width);
    }

    float triangle_area(float base, float height) {
        float result = .5 * base * height;
        return result;
    }
    float triangle_perimeter(float side1, float side2, float side3) {
        return side1 + side2 + side3;
    }

    float circle_area(float radius) {
        const float pi = 3.14;
        float result = power(radius, 2) * pi;
        return result;
    }
    float circle_area_from_diameter(float diameter) {
        const float pi = 3.14;
        float result = my_ceil((3.14 * power(diameter, 2)) / 4);
        return result;
    }
    float circle_area_by_circumference(float circumference) {
        const float pi = 3.14;
        float result = (circumference * circumference) / (4 * pi);
        return result;
    }

    //sum odd and even numbers
    //check odd or even 
    enum enNumberType { odd = 1, even = 2 };
    enNumberType isOddOrEven(int your_number) {
        if (your_number % 2 == 0) {
            return enNumberType::even;
        }
        else {
            return enNumberType::odd;
        }
    }
    enum en_prime { prime = 1, not_prim = 2 };
    en_prime check_prime(int your_number) {
        int m = round(your_number / 2);
        for (int i = 2; i <= m; i++) {
            if (your_number % i == 0) {
                return en_prime::not_prim;
            }
        }
        return en_prime::prime;
    }

    int sum_odd_for(int your_number) {
        int sum = 0;
        for (int i = 1; i <= your_number; i++) {
            if (isOddOrEven(i) == enNumberType::odd) {
                sum += i;
            }
            else {
                continue;
            }
        }
        return sum;
    }
    int sum_even_for(int your_number) {
        int sum = 0;
        for (int i = 1; i <= your_number; i++) {
            if (isOddOrEven(i) == enNumberType::even) {
                sum += i;
            }
            else {
                continue;
            }
        }
        return sum;
    }


    int max_number_arry(int your_arry[100], int your_size) {
        int max_number = your_arry[0];
        for (int i = 1; i < your_size; i++) {
            if (your_arry[i] >= max_number) {
                max_number = your_arry[i];
            }
        }
        return max_number;
    }
    int min_number_arry(int your_arry[100], int your_size) {
        int min_number = your_arry[0];
        for (int i = 1; i < your_size; i++) {
            if (your_arry[i] <= min_number) {
                min_number = your_arry[i];
            }
        }
        return min_number;
    }
    int sum_number_arry(int your_arry[100], int your_size) {
        int sum_number = 0;
        for (int i = 0; i < your_size; i++) {
            sum_number += your_arry[i];
        }
        return sum_number;
    }
    float average_number_arry(int your_arry[100], int your_size) {
        int sum_number = sum_number_arry(your_arry, your_size);

        float average = (float)sum_number / your_size;

        return average;
    }
}