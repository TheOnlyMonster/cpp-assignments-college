#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]==' '){
            int n_o_space=0;
            for (int j = 0; s[i+j]==' '; j++)
            {
                n_o_space++;
            }
            s.replace(i,n_o_space," ");
        }
    }
    for (int i = 1; i < s.length(); i++)
    {
        s[i]=tolower(s[i]);
    }
    cout<<char(toupper(s[0]))<<s.substr(1,s.length());
}