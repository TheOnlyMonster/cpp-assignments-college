#ifndef HEADER_H
#define HEADER_H
#include <bits/stdc++.h>
using namespace std;
class BigDecimalInt{
    private:
        char sign='+';
        int decInt;
        string decStr;
        string decStrValue;
        BigDecimalInt subtract(BigDecimalInt num2, BigDecimalInt num1);
        BigDecimalInt sum(BigDecimalInt num2,BigDecimalInt num1);
        string getNumWithAddedZeros(int b,int m);
    public:
        int size();
        BigDecimalInt(int decInt);
        BigDecimalInt(string decStr);
        bool operator<(BigDecimalInt anotherDec);
        bool operator>(BigDecimalInt anotherDec);
        bool operator==(BigDecimalInt anotherDec);
        BigDecimalInt operator+(BigDecimalInt anotherDec);
        BigDecimalInt operator-(BigDecimalInt anotherDec);
        friend ostream& operator <<(ostream& out, BigDecimalInt b);
};
#endif