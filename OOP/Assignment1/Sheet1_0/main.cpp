#include <bits/stdc++.h>
using namespace std;
int main(){
    char input[100];
    cin.getline(input,100);
    string s = input;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]==' '){
            int spaces_counter=0;
            for (int j = 0; s[i+j]==' '; j++)
            {
                spaces_counter++;
            }
            s.replace(i,spaces_counter," ");
        }
    }
    for (int i = 1; i < s.length(); i++)
    {
        s[i]=tolower(s[i]);
    }
    cout<<(char)toupper(s[0])<<s.substr(1,s.length());
}