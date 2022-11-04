#include "header.h"
int BigDecimalInt::size(){
    return this->decStr.length();
}
bool BigDecimalInt::operator<(BigDecimalInt anotherDec){
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
    }
    return true;
} 
bool BigDecimalInt::operator>(BigDecimalInt anotherDec){
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
    BigDecimalInt sM_Size(0),sL_Size(0);
    int bSize,mSize;
    int x;
    if(num2.size() > num1.size()){
        sL_Size=num2;
        sM_Size=num1;
        bSize=num2.decStr.length();
        mSize=num1.decStr.length();
        // if(num2.sign=='-' && num1.sign=='+'){
        //     res+='-';
        // }
    }
    else if(num2.size() < num1.size()){
        sL_Size=num1;
        sM_Size=num2;
        bSize=num1.decStr.length();
        mSize=num2.decStr.length();
        if(num1.sign=='+'&&num2.sign=='+'){
            res+='-';
        }
    }
    else{
        sL_Size=num2;
        sM_Size=num1;
        bSize=num2.size();
        mSize=num1.size();
    }
    s=getNumWithAddedZeros(bSize,mSize)+sM_Size.decStr;
    sM_Size.decStr=s;
    l=sL_Size.decStr;
    if(((int)sL_Size.decStr[0]-48 < (int)sM_Size.decStr[0]-48) && sL_Size.sign=='+' && sM_Size.sign=='+'){
        res+='-';
        string t;
        t=l;
        l=s;
        s=t;
    }
    else if(((int)sL_Size.decStr[0]-48 > (int)sM_Size.decStr[0]-48) && sL_Size.sign=='-' && sM_Size.sign=='+'){
        res+='-';
    }
    else if(((int)sL_Size.decStr[0]-48 < (int)sM_Size.decStr[0]-48) && sL_Size.sign=='-' && sM_Size.sign=='+'){
        string t;
        t=l;
        l=s;
        s=t;
    }
    else if((int)sL_Size.decStr[0]-48 == (int)sM_Size.decStr[0]-48){
        for (int i = 0; i < l.length(); i++)
        {
            if( sL_Size.sign=='-' && sM_Size.sign=='+' ){
                if((int)sL_Size.decStr[i]-48>(int)sM_Size.decStr[i]-48){
                    res+='-';
                    break;
                }
                else if((int)sL_Size.decStr[i]-48<(int)sM_Size.decStr[i]-48){
                    string t;
                    t=l;
                    l=s;
                    s=t;
                    break;
                }
            }
            else if( sL_Size.sign=='+' && sM_Size.sign=='-' ){
                if((int)sL_Size.decStr[i]-48>(int)sM_Size.decStr[i]-48){
                    break;
                }
                else if((int)sL_Size.decStr[i]-48<(int)sM_Size.decStr[i]-48){
                    res+='-';
                    string t;
                    t=l;
                    l=s;
                    s=t;
                    break;
                }
            }
            else if(sL_Size.sign=='+' && sM_Size.sign=='+'){
                if((int)sL_Size.decStr[i]-48<(int)sM_Size.decStr[i]-48){
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
    for (int i = bSize-1; i >= 0 ; i--)
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
    string res,l,s,sM_Size,sL_Size;
    int bSize,mSize;
    if(num2.sign=='-'&&num1.sign=='-'){
        res+='-';
    }
    if(num2.size() > num1.size()){
        bSize=num2.size();
        mSize=num1.size();
        sM_Size=num1.decStr;
        sL_Size=num2.decStr;
    }
    else if(num2.size() < num1.size()){
        bSize=num1.size();
        mSize=num2.size();
        sM_Size=num2.decStr;
        sL_Size=num1.decStr;
    }
    else{
        bSize=num2.size();
        mSize=num1.size();
        sM_Size=num2.decStr;
        sL_Size=num1.decStr;
    }
    s=getNumWithAddedZeros(bSize,mSize)+sM_Size;
    l=sL_Size;
    for (int i = bSize-1; i >= 0 ; i--)
    {
        static int rem=0;
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