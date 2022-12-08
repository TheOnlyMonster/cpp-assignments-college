#include "header.h"
char BigDecimalInt::Sign(){
    return this->sign;
}
int BigDecimalInt::size(){
    return this->decStr.length();
}
bool BigDecimalInt::operator<(BigDecimalInt anotherDec){
    bool same=false;
    if(this->sign=='-'&&anotherDec.sign=='+'){
        return true;
    }
    else if(this->sign=='+'&&anotherDec.sign=='-'){
        return false;
    }
    else if(this->sign=='+'&&anotherDec.sign=='+'){
        if(this->decStr.length()<anotherDec.decStr.length()){
            return true;
        }
        else if(this->decStr.length()>anotherDec.decStr.length()){
            return false;
        }
        else{
            for (int i = 0; i < this->decStr.length(); i++)
            {
                if(this->decStr[i]<anotherDec.decStr[i]){
                    return true;
                    break;
                }
                else if(this->decStr[i]>anotherDec.decStr[i]){
                    return false;
                    break;
                }
            }
        }
    }
    if(this->decStr.length()<anotherDec.decStr.length()){
        return false;
    }
    else if(this->decStr.length()>anotherDec.decStr.length()){
        return true;
    }
    for (int i = 0; i < this->decStr.length(); i++)
    {
        if(this->decStr[i]<anotherDec.decStr[i]){
            return false;
            break;
        }
        else if(this->decStr[i]>anotherDec.decStr[i]){
            return true;
            break;
        }
        else{
            same=true;
        }
        
    }
    if(same){
        return false;
    }
    return true;
} 
bool BigDecimalInt::operator>(BigDecimalInt anotherDec){
    bool same=false;
    if(this->sign=='-'&&anotherDec.sign=='+'){
        return false;
    }
    else if(this->sign=='+'&&anotherDec.sign=='-'){
        return true;
    }
    else if(this->sign=='+'&&anotherDec.sign=='+'){
        if(this->decStr.length()<anotherDec.decStr.length()){
            return false;
        }
        else if(this->decStr.length()>anotherDec.decStr.length()){
            return true;
        }
        else{
            for (int i = 0; i < this->decStr.length(); i++)
            {
                if(this->decStr[i]<anotherDec.decStr[i]){
                    return false;
                    break;
                }
                else if(this->decStr[i]>anotherDec.decStr[i]){
                    return true;
                    break;
                }
            }
        }
    }
    if(this->decStr.length()<anotherDec.decStr.length()){
        return true;
    }
    else if(this->decStr.length()>anotherDec.decStr.length()){
        return false;
    }
    for (int i = 0; i < this->decStr.length(); i++)
    {
        if(this->decStr[i]<anotherDec.decStr[i]){
            return true;
            break;
        }
        else if(this->decStr[i]>anotherDec.decStr[i]){
            return false;
            break;
        }
        else{
            same=true;
        }
    }
    if(same){
        return false;
    }
    return true;
} 
bool BigDecimalInt::operator==(BigDecimalInt anotherDec){
    if(this->sign==anotherDec.sign && this->size() == anotherDec.size()){
        for (int i = 0; i < this->size(); i++)
        {
            if(this->decStr[i]!=anotherDec.decStr[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){
    if((this->sign=='+'&&anotherDec.sign=='+')||(this->sign=='-'&&anotherDec.sign=='-')){
        return sum(*this,anotherDec);
    }
    else if(this->sign=='-'||anotherDec.sign=='-'){
        return subtract(*this,anotherDec);
    }
    return sum(*this,anotherDec);
}
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){
    if(this->sign=='-'&&anotherDec.sign=='-'){
        anotherDec.sign='+';
        return subtract(*this,anotherDec);
    }
    else if(this->sign=='+'&&anotherDec.sign=='-'){
        return sum(*this,anotherDec);
    }
    else if(this->sign=='-'&&anotherDec.sign=='+'){
        anotherDec.sign='-';
        return sum(*this,anotherDec);
    }
    return subtract(*this,anotherDec);
}
BigDecimalInt::BigDecimalInt(int decInt){
    decStr=to_string(decInt);
    decStrValue=decStr;
    if(decStr[0]=='-'){
        sign='-';
    }
    if(decStr[0]=='+'||decStr[0]=='-'){
        decStr.erase(0,1);
    }
    this->decStr=decStr;
}
BigDecimalInt::BigDecimalInt(string decStr){
    int ctr=0;
    int len = decStr.length();
    for (int i = 0; i < len; i++)
    {
        if(decStr[i]=='+'||decStr[i]=='-'){
            continue;
        }
        if(decStr[i]=='0'&&i+1!=len){
            ctr++;
        }
        else{
            break;
        }
    }
    if(decStr[0]=='-'){
        decStr='-'+decStr.substr(ctr+1);
    }
    else{
        decStr=decStr.substr(ctr);
    }
    decStrValue=decStr;
    if(decStr[0]=='-'){
        sign='-';
    }
    if(decStr[0]=='+'||decStr[0]=='-'){
        decStr.erase(0,1);
    }
    this->decStr=decStr;
}
ostream& operator <<(ostream& out, BigDecimalInt b){
    out<<b.decStrValue;
    return out;
}
BigDecimalInt BigDecimalInt::subtract(BigDecimalInt num2, BigDecimalInt num1){
    string res,l,s;
    int x;
    if(num2.size() < num1.size()){
        BigDecimalInt temp(0);
        temp=num2;
        num2=num1;
        num1=temp;
        if(num2.sign=='+'&&num1.sign=='+'){
            res+='-';
        }
    }
    s=getNumWithAddedZeros(num2.size(),num1.size())+num1.decStr;
    l=num2.decStr;
    if((int)l[0]-48 < (int)s[0]-48){
        if((num1.sign=='-'&&num2.sign=='+')||(num2.sign=='+'&&num1.sign=='+')){
            res+='-';
            string t;
            t=l;
            l=s;
            s=t;
        }
    }
    if((int)l[0]-48 > (int)s[0]-48){
        
        if(num2.sign=='-'&&num1.sign=='+'){
            res+='-';
        }
    }
    else if((int)num2.decStr[0]-48 == (int)num1.decStr[0]-48){
        for (int i = 0; i < l.length(); i++)
        {
            if( num2.sign=='-' && num1.sign=='+' ){
                if((int)num2.decStr[i]-48>(int)num1.decStr[i]-48){
                    res+='-';
                    break;
                }
                else if((int)num2.decStr[i]-48<(int)num1.decStr[i]-48){
                    string t;
                    t=l;
                    l=s;
                    s=t;
                    break;
                }
            }
            else if( num2.sign=='+' && num1.sign=='-' ){
                if((int)num2.decStr[i]-48>(int)num1.decStr[i]-48){
                    break;
                }
                else if((int)num2.decStr[i]-48<(int)num1.decStr[i]-48){
                    res+='-';
                    string t;
                    t=l;
                    l=s;
                    s=t;
                    break;
                }
            }
            else if(num2.sign=='+' && num1.sign=='+'){
                if((int)num2.decStr[i]-48<(int)num1.decStr[i]-48){
                    res+='-';
                    string t;
                    t=l;
                    l=s;
                    s=t;
                    break;
                }
            }
        }
    }
    for (int i = num2.size()-1; i >= 0 ; i--)
    {
        int rem=0;
        int temp=0;
        if((int)l[i]-48 < (int)s[i]-48 && i!=0){
            rem=10;
            l[i-1]-=1;
        }
        temp=((int)l[i]-48 + rem) - ((int)s[i]-48);
        string stemp = to_string(temp);
        res.push_back(stemp[0]);
    }
    if(res[0]=='-'){
        reverse(res.begin()+1,res.end());
    }
    else{
        reverse(res.begin(),res.end());
    }
    BigDecimalInt BigDecimalIntRes(res);
    return BigDecimalIntRes;
}
BigDecimalInt BigDecimalInt::sum(BigDecimalInt num2,BigDecimalInt num1){
    string res,l,s;
    if(num2.sign=='-'&&num1.sign=='-'){
        res+='-';
    }
    if(num2.size() < num1.size()){
        BigDecimalInt temp(0);
        temp=num2;
        num2=num1;
        num1=temp;
    }
    s=getNumWithAddedZeros(num2.size(),num1.size())+num1.decStr;
    l=num2.decStr;
    int rem=0;
    for (int i = num2.size()-1; i >= 0 ; i--)
    {
        int temp=0;
        temp=(int)s[i]-48 + rem + (int)l[i]-48;
        rem=0;
        if(temp>=10){ 
            string stemp = to_string(temp);
            res.push_back(stemp[1]);
            rem=stemp[0]-48;
            if(i-1<0){
                res.push_back(stemp[0]);
            }
        }
        else{
            string stemp = to_string(temp);
            res.push_back(stemp[0]);
        }
    }
    if(res[0]=='-'){
        reverse(res.begin()+1,res.end());
    }
    
    else{
        reverse(res.begin(),res.end());
    }
    BigDecimalInt BigDecimalIntRes(res);
    return BigDecimalIntRes;
}
string BigDecimalInt::getNumWithAddedZeros(int b,int m){
    string s;
    int x = b-m;
    for (int i = 0; i < x; i++)
    {
        s+='0';
    }
    return s;
}