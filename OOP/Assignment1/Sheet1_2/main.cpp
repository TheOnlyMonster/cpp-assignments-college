#include <bits/stdc++.h>
using namespace std;
vector<string> split(string target,string delimiter){
    
    vector<string> v;
    string tmp;
    for (int i = 0; i < target.length(); i++)
    {
        if(delimiter[0]==target[i]){
            v.push_back(tmp);
            tmp.erase();
        }
        else{
            tmp.push_back(target[i]);
        }
    }
    v.push_back(tmp);
    return v;
}
int main() 
{
    vector<string> v = split("do ra me fa so"," ");
    for (auto i = v.begin(); i!=v.end(); i++)
    {
        cout<<*i<<'\n';
    }
}