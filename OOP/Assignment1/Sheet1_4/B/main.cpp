#include <bits/stdc++.h>
using namespace std;

string binaryPrint(int n){
    static string s;
    string t;
    if(n%2==0){
        n/=2;
        s.push_back('0');
    }
    else{
        n/=2;
        s.push_back('1');
    }
    if(n!=0){
        return binaryPrint(n);
    }
    reverse(s.begin(),s.end());
    t=s;
    s.clear();
    return t;
}
void PrintAndAddZero(int k,int i){
    string t,m=binaryPrint(i);
    // cout<<m<<" ";
    for (int j = 0; j < k-m.length(); j++)
    {
        t+='0';
    }
    t+=m;
    cout<<t;
}
void numbers(string prefix,int k){
    int prop = pow(2,k);
    for (int i = 0; i < prop; i++)
    {
        cout<<prefix;
        PrintAndAddZero(k,i);
        cout<<endl;
    }
}
int main(){
    numbers("101",4);
}












// #include <bits/stdc++.h>
// using namespace std;
// void numbers(string prefix,int k);
// int main(){
//     numbers("s",3);
// }
// void numbers(string prefix,int k){
//     int temp = pow(2,k);
//     vector<int> v;
//     for (int i = 2,j=0; i < temp;i+=2,j++)
//     {
//         v.push_back(temp/i);
//         cout<<v[j]<<" ";
//     }
//     for (int i = 0; i <v.size(); i++)
//     {

//     }  
// }