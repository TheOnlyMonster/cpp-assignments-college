#include <bits/stdc++.h>
using namespace std;
class LabelGenerator{
    protected:
        string p;
        int l;
        int counter;
    public:
        LabelGenerator(string, int);
        virtual string nextLabel();
};
class FileLabelGenerator:public LabelGenerator{
    private:
        string s;
        string f;
    public:
        string nextLabel();
        FileLabelGenerator(string, int, string);
};
string FileLabelGenerator::nextLabel(){
    ifstream myFile(f);
    for (int i = 0; i < counter; i++)
    {
        getline(myFile,s);
    }
    return LabelGenerator::nextLabel()+' '+s;
}
FileLabelGenerator::FileLabelGenerator(string p, int l, string f):LabelGenerator(p,l){
    this->f=f;
}
LabelGenerator::LabelGenerator(string p, int l){
    this->p=p;
    this->l=l;
    counter=l;
}
string LabelGenerator::nextLabel(){
    return p+to_string(counter++);
}
int main(){
    LabelGenerator figureNumbers("Figure ", 1); 
    LabelGenerator pointNumbers("P", 0); 
    cout << "Figure numbers: "; 
    for (int i = 0; i < 3; i++) { 
        cout << figureNumbers.nextLabel() << ", "; 
    } 
    cout << endl << "Point numbers: "; 
    for (int i = 0; i < 5; i++) { 
        cout << pointNumbers.nextLabel() << ", "; 
    } 
    cout << endl << "More figures: "; 
    for (int i = 0; i < 3; i++) { 
        cout << figureNumbers.nextLabel() << ", "; 
    } 
    cout << endl;

    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt"); 
    cout << "Figure labels: \n"; 
    for (int i = 0; i < 3; i++) { 
    cout << figureLabels.nextLabel() << endl; 
    }
}