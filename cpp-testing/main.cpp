#include <bits/stdc++.h>
using namespace std;
class MyClass{
    char* ptr;
    public:
        MyClass(MyClass &&other){
            cout<<"Entered Move constructor"<<endl;
            ptr=other.ptr;
            other.ptr=nullptr;
            cout<<&ptr<<endl;
            cout<<&other.ptr<<endl;
        }
        MyClass(const char *x){
            ptr=new char[5];
            strcpy(ptr,x);
        }
        MyClass(const MyClass &other):MyClass(other.ptr){
            cout<<"Deep Copy Constructor Called"<<endl;
        }
        void getPtrAddress(){
            cout<<&ptr<<endl;
        }
        void getPtrValue(){
            cout<<ptr<<endl;
        }
        void ChangePtrValue(const char* m){
            strcpy(ptr,m);
        }
};
int main(){
    char m[]="ahmed";
    MyClass obj1(m);
    MyClass obj2(obj1);
    obj1.getPtrAddress();
    obj2.getPtrAddress();
    obj1.getPtrValue();
    obj2.getPtrValue();
    obj1.ChangePtrValue("ali");
    obj2.ChangePtrValue("abdo");
    obj1.getPtrAddress();
    obj2.getPtrAddress();
    obj1.getPtrValue();
    obj2.getPtrValue();
    cout<<"========================="<<endl;
    MyClass obj4(move(obj1));
    // vector<MyClass> vec;
    // vec.push_back(MyClass{"10"});
}