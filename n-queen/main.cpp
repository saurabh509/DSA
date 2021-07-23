/*
    Name: Saurabh Badgujar
    Roll: 33107
    Batch: K9
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//vectors for storing board,diagonals,column
vector<vector<char> > board;
vector<bool> main_diag,sec_diag,column;
int ways=0;

//function to display board
void display_board(const int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<"|"<<board[i][j];
        }cout<<"|"<<endl;
    }
    cout<<endl;
}

//recursive function to place n-queens on n X n board
void place_queens(int row,const int N){
    if(row>=N){
        display_board(N);
        ways++;
        return;
    }
    for(int i=0;i<N;i++){
        if(column[i]==false && main_diag[i+row]==false && sec_diag[row-i+N]==false){
            board[row][i]='Q';
            column[i]=true;
            main_diag[i+row]=true;
            sec_diag[row-i+N]=true;
            place_queens(row+1,N);
            board[row][i]='.';
            column[i]=false;
            main_diag[i+row]=false;
            sec_diag[row-i+N]=false;
        }
    }
}

//driver code.
int main(){
    //input
    cout<<"Enter the size of the board:";
    int n;
    cin>>n;

    //dynamic memory allocation.
    board=vector<vector<char>>(n,vector<char>(n,'.'));
    main_diag=vector<bool>(2*n,0);
    sec_diag=vector<bool>(2*n,0);
    column=vector<bool>(2*n,0);

    //place queens function.
    place_queens(0,n);
    cout<<"Total ways are:"<<ways<<endl;
}
