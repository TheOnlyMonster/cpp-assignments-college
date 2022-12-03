#include <bits/stdc++.h>
using namespace std;
class Universe{
    private:
        char alive='*';
        char dead='#';
        char game[20][50];
        char temp_game[20][50];
    public:
        Universe();
    void initialize(); //generates a starting layout
    void reset(); // sets all the cells as dead.
    int count_neighbors(int,int); //returns the number of alive neighbors
    void next_generation(); //produces a new state of the game based on the transition rules. 
    void display(); //shows the game status on the console
    void run(); //to start the game for a certain number of runs. 
};
Universe::Universe(){
    Universe::initialize();
}
void Universe::initialize(){
    Universe::reset();
    int m,n,k;
    cout<<"How many cells you want to revive? ";
    cin>>m;
    int i=0;
    while(i<m){
        cin>>n>>k;
        game[n][k]=alive;
        i++;
    }
    Universe::display();
}
void Universe::reset(){
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            game[i][j]=dead;
        }
    }
}
void Universe::display(){
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cout<<game[i][j];
            temp_game[i][j]=game[i][j];
        }
        cout<<endl;
    }
    system("pause");
    system("cls");
    Universe::next_generation();
}
int Universe::count_neighbors(int row,int col){
    int temp_count=0;
    if(game[row+1][col]==alive){
        temp_count++;
    }
    if(game[row-1][col]==alive){
        temp_count++;
    }
    if(game[row][col+1]==alive){
        temp_count++;
    }
    if(game[row][col-1]==alive){
        temp_count++;
    }
    return temp_count;
}
void Universe::next_generation(){
    bool state_change=false;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if( (game[i][j]==alive && count_neighbors(i,j)<2) || (game[i][j]==alive && count_neighbors(i,j)>3) ){
                temp_game[i][j]=dead;
                state_change=true;
            }
            else if(game[i][j]==alive && (count_neighbors(i,j)==2 || count_neighbors(i,j)==3) ){
                temp_game[i][j]=alive;
                state_change=true;
            }
            else if(game[i][j]==dead && count_neighbors(i,j)==3 ){
                temp_game[i][j]=alive;
                state_change=true;
            }
        }
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            game[i][j]=temp_game[i][j];
        }
    }
    if(state_change){
        Universe::display();
    }
}
int main(){
    Universe u;
}