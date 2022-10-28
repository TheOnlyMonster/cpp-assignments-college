#include <bits/stdc++.h>
using namespace std;
char mainAlph[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' ,'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v' ,'w' ,'x', 'y', 'z'};
deque<char> keyGenerator(string key){
    deque<char> alph={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' ,'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v' ,'w' ,'x', 'y', 'z'};
    for (int i = key.length()-1; i >=0; i--)
    {
        for (auto it=alph.begin();it!=alph.end();it++)
        {
            if(key[i]==*it){
                alph.erase(it);
                break;
            }
        }
        alph.push_front(key[i]);
    }
    return alph;
}
string decipher(string s,string key){
    string decipherMessage;
    deque<char> alphkey = keyGenerator(key);
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]!=' '){
            for (int j = 0; j < 26; j++)
            {
                if(s[i]==alphkey[j]){
                    decipherMessage+=mainAlph[j];
                    break;
                }
            }
        }
        else{
            decipherMessage+=' ';
        }
    }
    return decipherMessage;
}
string cipher(string s,string key){
    string cipherMessage;
    deque<char> alphkey = keyGenerator(key);
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]!=' '){
            for (int j = 0; j < 26; j++)
            {
                if(s[i]==mainAlph[j]){
                    cipherMessage+=alphkey[j];
                    break;
                }
            }
        }
        else{
            cipherMessage+=' ';
        }
    }
    return cipherMessage;
}
int main(){
    
    string s;
    int n;
    bool r = true;
    while(r){
        cout<<"Ahlan ya user ya habebi"<<endl;
        cout<<"What do you like to do today?"<<endl;
        cout<<"1-Cipher a message"<<endl;
        cout<<"2-Decipher a message"<<endl;
        cout<<"3-End"<<endl;
        cin>>n;
        if(n==1){
            cin.clear();
            cin.sync();
            cout<<"Please enter the message to cipher:"<<endl;
            getline(cin,s);
            string key;
            cout<<"Enter a key to cipher: "<<endl;
            cout<<"====================================================="<<endl;
            cin>>key;
            cout<<"====================================================="<<endl;
            cout<< cipher(s,key)<<endl;
            cout<<"====================================================="<<endl;
        }
        else if(n==2){
            cin.clear();
            cin.sync();
            cout<<"Please enter the message to decipher:"<<endl;
            getline(cin,s);
            string key;
            cout<<"Enter a key to decipher: "<<endl;
            cout<<"====================================================="<<endl;
            cin>>key;
            cout<<"====================================================="<<endl;
            cout<< decipher(s,key)<<endl;
            cout<<"====================================================="<<endl;
        }
        else{
            r=false;
        }
    }
}