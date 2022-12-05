#include <bits/stdc++.h>
using namespace std;
class MyClass{
    int len;
    char* ptr;
    public:
        MyClass(MyClass &&other){
            cout<<"Entered Move constructor"<<endl;
            ptr=new char[other.len];
            ptr=other.ptr;
            len=other.len;
            other.ptr=nullptr;
            other.len=0;
        }
        MyClass(const char *x,int len){
            cout<<"Entered Parametrized constructor"<<endl;
            this->len=len;
            ptr=new char[len];
            strcpy(ptr,x);
        }
        MyClass(const MyClass &other):MyClass(other.ptr,other.len){
            cout<<"Deep Copy Constructor Called"<<endl;
        }
        void getPtrAddress(){
            cout<<&ptr<<endl;
        }
        void getPtrValue(){
            cout<<ptr<<" "<<len<<endl;
        }
        void ChangePtrValue(const char *x,int len){
            this->len=len;
            ptr=new char[len];
            strcpy(ptr,x);
        }
        ~MyClass(){
            cout<<"Destructor"<<endl;
            if(this->ptr==nullptr){
                cout<<"nullptr Destroyed"<<endl;
            }
            else{
                cout<<"non nullptr Destroyed"<<endl;
            }
        }
};
int main(){
    // obj1.getPtrAddress();
    // obj2.getPtrAddress();
    // obj1.getPtrValue();
    // obj2.getPtrValue();
    // obj1.ChangePtrValue("ali",3);
    // obj2.ChangePtrValue("abdo",4);
    // obj1.getPtrAddress();
    // obj2.getPtrAddress();
    // obj1.getPtrValue();
    // obj2.getPtrValue();
    // cout<<"========================="<<endl;
    // MyClass obj4 = MyClass("ooo",3);
    // MyClass obj4(MyClass("oooo",4));
    // obj4.getPtrAddress();
    // obj4.getPtrValue();
}