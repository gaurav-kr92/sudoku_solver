#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int> > v;
bool solved=false;

void about_sudoku(){
    cout<<"The objective in sudoku is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid (also called 'boxes', 'blocks', or 'regions') contain all of the digits from 1 to 9."<<endl;
    cout<<"The puzzle setter provides a partially completed grid (one which you must have right now), which for a well-posed puzzle has a single solution."<<endl;

}

void printsudoku(){
    cout<<endl<<" ___ ___ ___ ___ ___ ___ ___ ___ ___"<<endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(v[i][j]!=0){
                cout<<"| "<<v[i][j]<<" ";
            }
            else{
                cout<<"|   ";
            }
            
        }
        cout<<"|"<<endl<<" ___ ___ ___ ___ ___ ___ ___ ___ ___"<<endl;
    }
    cout<<endl;
}


// function to check vaild input . 

bool isValidSudoku() {
        // For hashing in rowise , colwise and 3*3 group wise. 

        set<pair<int,int > > row,col,grid;
        //Iterating through each each cell;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                // checking occurence in their neighbour.
                if(v[i][j]!= 0 ){
                int count=(i/3)*3 +j/3;
                
                // row check
                if(row.find(make_pair(i,v[i][j]))==row.end())
                    row.insert(make_pair(i,v[i][j]));
                 else return false;

                // col check
                if(col.find(make_pair(j,v[i][j]))==col.end())
                    col.insert(make_pair(j,v[i][j]));
                 else return false;
                
                // small grid check 
                if(grid.find(make_pair(count,v[i][j]))==grid.end())
                    grid.insert(make_pair(count,v[i][j]));
                 else  return false;
                }
            }
        }
        return true;

        // Time Complexity = O(9*9);
        // Space Complexity = O(9*9);
    }

 // Function for checking valid option to be filled; 

bool isvalid(int row, int col, int c){
    for(int i =0 ; i<9; i++){
        if(v[i][col] == c) return false;
        if(v[row][i] == c) return false; 

        if(v[3 *(row/3) + i/3][3 *(col/3) + i%3] == c){
            return false;
        }
    }
    return true;
}

// Function to solve sudoku 

bool sudoku(){
    // Checking each and every cell 
    // Iterating through row wise. 
    for(int i=0; i<9; i++){
        // iterating all colums. 
        for(int j=0; j<9; j++){
            if(v[i][j]== 0){
                // Checking val a sol 
                for(int c =1; c <= 9 ; c++){
                    if(isvalid(i,j,c)){
                        v[i][j] = c;
                        // recusive call 
                        if(sudoku()){
                            return true;
                        }
                        else {
                            // backtracking
                            v[i][j]= 0 ;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;

    // Time complexity = O(9^(9*9)) 
    // space complexitiy= O(9*9);

}


void solve(){
    v.assign(9,vector<int>(9,0));
    cout<<"Input your sudoku in the following format: "<<endl;
    cout<<"Enter the values column-wise for every row."<<endl;
    cout<<"First enter the column-wise elements in the first row and proceed to the other rows in similar fashion"<<endl;
    cout<<"Enter the given values at respective positions and denote empty cells with a '.' character (without the quotes) or with a 0"<<endl;
    cout<<"DO NOT DENOTE EMPTY CELLS WITH A SPACE"<<endl;
    cout<<endl<<"Input your sudoku: "<<endl;
    for(int i=0;i<9;i++){
        string s; 
        cin>>s;
        for(int j=0;j<9;j++){
            if (s[j]!='.') v[i][j]=s[j]-'0';
        }
    }
    cout<<"Your sudoku looks like this:"<<endl;
    printsudoku();
    cout<<endl<<"Enter Y to proceed, and any other key to input again"<<endl;
    char ch; cin>>ch;
    if(ch=='Y' || ch=='y'){
        
        solved=false;
        sudoku();
        if(isValidSudoku()){
            cout<<"Solved sudoku: "<<endl;
            printsudoku();
        }else{
            cout<<"Opps! Invaild Input"<<endl; 
        }
    }
    else{
        solve();
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);cout.tie(NULL);
    cout<<"********* WELCOME TO THE SUDOKU SOLVER *********"<<endl;
    while(true){
        cout<<"Enter 1 to learn about sudoku"<<endl;
        cout<<"Enter 2 to solve your sudoku!"<<endl;
        cout<<"Enter 3 to exit"<<endl;
        cout<<endl<<"Enter your choice:"<<endl;
        int choice; 
        cin>>choice;
        if(choice==3){
            cout<<"Thanks for using the sudoku solver!"<<endl;
            break;
        }
        if(choice==1){
            about_sudoku();
            cout<<endl;
            
        }
        else solve();
    }
}