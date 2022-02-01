// Mouse in a Maze problem is like mouse have to go thorugh a maze to come out of it
// Sample input = 
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1 
// 1 1 1 0 1

// output :-
// 1 0 0 0 0 
// 1 1 1 1 0
// 0 0 0 1 0 
// 0 0 0 1 1 
// 0 0 0 0 1

#include<iostream>
using namespace std;

bool isSafe(int** a, int x, int y, int n){
    if(x<n && y<n && (a[x][y] == 1)){
        return true;
    }
    return false;
}

bool ratInMaze(int** a, int x, int y, int n,  int** sol_arr){
    if(x == n-1 && y==n-1){
        sol_arr[x][y] = 1;
        return true;
    }

    if(isSafe(a, x, y, n)){
        sol_arr[x][y] = 1;
        if(ratInMaze(a, x+1, y, n, sol_arr)){
            return true;
        }
        if(ratInMaze(a, x, y+1, n, sol_arr)){
            return true;
        }
        sol_arr[x][y] = 0;      //Backtracking
        return false;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int **a = new int*[n];
     for(int i=0; i<n; i++){
         a[i] = new int[n];
            for(int j=0; j<n; j++)
                cin>>a[i][j];
    }
    int **sol_arr = new int*[n];
    for(int i=0; i<n; i++){
         sol_arr[i] = new int[n];
            for(int j=0; j<n; j++)
                sol_arr[i][j] = 0;
    }
    if(ratInMaze(a, 0, 0, n, sol_arr)){
        cout<<endl<<"\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<sol_arr[i][j]<<" ";
            cout<<endl;
        }
        
    }

    
    return 0;
}