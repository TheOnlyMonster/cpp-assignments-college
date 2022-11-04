#include <bits/stdc++.h>
using namespace std;
string s;
void binaryPrint(int n){
    if(n%2==0){

        n/=2;
        s.push_back('0');
    }
    else{
        n/=2;
        s.push_back('1');
    }
    if(n!=0){
        binaryPrint(n);
    }
    else{
        reverse(s.begin(),s.end());
        cout<<s;
    }
}
int main(){
    binaryPrint(2);
}