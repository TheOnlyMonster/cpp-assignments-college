#ifndef HEADER_H
#define HEADER_H
#include <bits/stdc++.h>
using namespace std;
class BigDecimalInt{
    protected:
        char sign='+';
        int decInt;    
        BigDecimalInt subtract(BigDecimalInt num2, BigDecimalInt num1);
        BigDecimalInt sum(BigDecimalInt num2,BigDecimalInt num1);
        string getNumWithAddedZeros(int b,int m);
    public:
        string decStrValue;
        string decStr;
        char Sign();
        virtual int size();
        BigDecimalInt(int decInt);
        BigDecimalInt(string decStr);
        bool operator<(BigDecimalInt anotherDec);
        bool operator>(BigDecimalInt anotherDec);
        bool operator==(BigDecimalInt anotherDec);
        BigDecimalInt operator+(BigDecimalInt anotherDec);
        BigDecimalInt operator-(BigDecimalInt anotherDec);
        friend ostream& operator <<(ostream& out, BigDecimalInt b);
};
class BigReal:public BigDecimalInt{
    private:
        int fractionIndex;
        string realStr;
        double realNum;
        void setNumA();
        void setNumB();
        void getNumAWithAddedZeros(BigReal&);
        string numA;
        string numB;
    public:
        // BigReal(double realNumber = 0.0); // Default constructor 
        BigReal(string realNumber); 
        BigReal(BigDecimalInt bigInteger); 
        // BigReal(const BigReal& other); // Copy constructor 
        // BigReal(BigReal&& other); // Move constructor 
        // BigReal& operator=(BigReal& other); // Assignment operator 
        // BigReal& operator=(BigReal&& other); // Move assignment 
        BigReal operator+(BigReal& other); 
        BigReal operator-(BigReal& other); 
        // bool operator<(BigReal anotherReal);                
        bool operator>(BigReal anotherReal);                
        // bool operator==(BigReal anotherReal);                
        int size(); //overidden
        // friend ostream& operator<<(ostream& out, BigReal num); //why do we need this? 
        friend istream& operator>>(istream& out, BigReal& num); 
};
#endif