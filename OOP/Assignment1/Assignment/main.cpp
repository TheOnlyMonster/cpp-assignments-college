#include "header.h"
int main(){
    BigDecimalInt num2("0000000000000"); 
    BigDecimalInt num1("+2443"); 
    BigDecimalInt num3 = num2 + num1; 
    cout<<num3;
}