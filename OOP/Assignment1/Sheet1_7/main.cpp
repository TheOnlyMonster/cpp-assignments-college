#include <bits/stdc++.h>
using namespace std;
bool bears(int n){
    if(n<42){
        return false;
    }
    if(n==42){
        return true;
    }
    if(n%5==0 && bears(n-42)){
        return true;
    }
    if((n%4==0 || n%3==0)){
        if((n%10)*floor(n%100 / 10)!=0){
            return bears(n-((n%10)*floor(n%100 / 10)));
        }
    }
    if(n%2==0 && bears(n/2)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    cout<<bears(250)<<'\n';
    cout<<bears(42)<<'\n';
    cout<<bears(84)<<'\n';
    cout<<bears(53)<<'\n';
    cout<<bears(41)<<'\n';
}
