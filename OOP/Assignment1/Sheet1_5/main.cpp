#include <bits/stdc++.h>
using namespace std;
struct dominoT{
    int leftDots;
    int rightDots;
};
void FormsDominoChain(vector<dominoT> dominoS);
bool BoolFormsDominoChain(vector<dominoT> dominoS);
int main(){
    vector<dominoT> dominoSet = {{1,4},{2,6},{4,4},{6,1},{4,3}};
    FormsDominoChain(dominoSet);
    if(BoolFormsDominoChain(dominoSet)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
bool Is_R_L(vector<dominoT>domins,vector<dominoT>temp){
    int counter=0;
    for (int i = 0; i < domins.size() - 1; i++)
    {
        if(temp[i].rightDots == temp[i+1].leftDots){
            counter++;
        }
    }
    if(counter+1 == domins.size()){
        return true;
    }
    return false;
}
bool HasLeftDot(vector<int> v,int c){
    for (int i = 0; i < v.size(); i++)
    { 
        if(v[i]-1==c){
            return false;
        }
    }
    return true;
}
bool Path(int m, vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]==m){
            return false;
        }
    }
    return true;
}
void FormsDominoChain(vector<dominoT> dominoS){
    static int my_index=0;
    static int ctr=0;
    static vector<dominoT> temp;
    static vector<int> index_of_no_l_dot;
    static vector<int> path;
    if(temp.size()==dominoS.size() && Is_R_L(dominoS,temp)){
        for (int i = 0; i < temp.size(); i++)
        {
            if(i+1==temp.size()){
                cout<<temp[i].leftDots<<"|"<<temp[i].rightDots<<"\n";
                break;
            }
            else{
                cout<<temp[i].leftDots<<"|"<<temp[i].rightDots<<" - ";
            }
        }
    }
    else if(temp.size()==0){
        if(my_index>dominoS.size()){
            cout<<"Can't form chains"<<'\n';
        }
        else{
            index_of_no_l_dot.clear();
            temp.push_back(dominoS[my_index]);
            my_index++;
            ctr=0;
            path.clear();
            FormsDominoChain(dominoS);
        }
    }
    else{
        bool found=false;
        for (int i = 0; i < dominoS.size(); i++)
        {
            if(temp[ctr].rightDots==dominoS[i].leftDots && HasLeftDot(index_of_no_l_dot,ctr) && Path(i,path)){
                path.push_back(i);
                found=true;
                ctr++;
                temp.push_back(dominoS[i]);
                break;
            }
        }
        if(found){
            FormsDominoChain(dominoS);
        }
        else{
            index_of_no_l_dot.push_back(ctr);
            temp.pop_back();
            ctr--;
            FormsDominoChain(dominoS);
        }
    }
}
bool BoolFormsDominoChain(vector<dominoT> dominoS){
    static int my_index=0;
    static int ctr=0;
    static vector<dominoT> temp;
    static vector<int> index_of_no_l_dot;
    static vector<int> path;
    if(temp.size()==dominoS.size() && Is_R_L(dominoS,temp)){
        return true;
    }
    else if(temp.size()==0){
        if(my_index>dominoS.size()){
            return false;
        }
        index_of_no_l_dot.clear();
        temp.push_back(dominoS[my_index]);
        my_index++;
        ctr=0;
        path.clear();
        return BoolFormsDominoChain(dominoS);
    }
    bool found=false;
    for (int i = 0; i < dominoS.size(); i++)
    {
        if(temp[ctr].rightDots==dominoS[i].leftDots && HasLeftDot(index_of_no_l_dot,ctr) && Path(i,path)){
            path.push_back(i);
            found=true;
            ctr++;
            temp.push_back(dominoS[i]);
            break;
        }
    }
    if(found){
        return BoolFormsDominoChain(dominoS);
    }
    index_of_no_l_dot.push_back(ctr);
    temp.pop_back();
    ctr--;
    return BoolFormsDominoChain(dominoS);
}