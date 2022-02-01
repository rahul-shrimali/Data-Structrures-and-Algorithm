//Given an array of size 9 X 9 with partially filled sudoku, you have to solve the following sudoku problem

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void SolveSudoku(vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col, int rowidx, int colidx){
   
    if(rowidx == 9){
   
        for(auto it :a){
            for(auto i : it)
                cout<<i<<" ";
            cout<<endl;
        }
        cout<<"\n";
        return;
    }
    if(colidx == 9){
        
        
        SolveSudoku(a, mp, row, col, rowidx + 1, 0);
        return;
    }
    if(a[rowidx][colidx] != '.'){
       
        SolveSudoku(a, mp, row, col, rowidx, colidx + 1);
        return;
    }

    for(int i=1; i<=9; i++){
        int r = rowidx/3, c = colidx/3;
       
        if(!mp[{r, c}][i] and !row[rowidx][i] and !col[colidx][i]){
            a[rowidx][colidx] = i + '0';
            mp[{r, c}][i] = 1;
            row[rowidx][i] = 1;
            col[colidx][i] = 1;
            
         
            SolveSudoku(a, mp, row, col, rowidx, colidx + 1);
            //Backtracking 
            a[rowidx][colidx] = '.';
            mp[{r, c}][i] = 0;
            row[rowidx][i] = 0;
            col[colidx][i] = 0;
        } 

    }
}

void sudoku(vector<vector<char>> &a){
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    for(int i=0; i<9; i++){
        for(int j= 0; j<9; j++){
            if(a[i][j] != '.'){
                mp[{i/3, j/3}][a[i][j] - '0'] = 1;
                row[i][a[i][j]-'0'] = 1;
                col[j][a[i][j]-'0'] = 1;
            }
        }
    }

    SolveSudoku(a, mp, row, col, 0, 0);
}

int main(){
    vector<vector<char>> puzzle = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    sudoku(puzzle);
    
    return 0;
}