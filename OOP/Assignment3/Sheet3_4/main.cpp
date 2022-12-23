#include <bits/stdc++.h>
using namespace std;
void traffic(int n){
    static vector<string> v;
    if(n==0){
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back("Red");
    traffic(n-1);
    v.pop_back();
    v.push_back("Green");
    traffic(n-1);
    v.pop_back();
}
int main(){
    traffic(4);
}