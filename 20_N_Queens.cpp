#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    bool isValid(int row, int col, int &n, vector<string> &board){
        int i = row, j = col;

        while (i < n){

        }
        while (i >= 0 && j>=0){
            if (board[i][j] == 'Q') return 0;
            i--;
            j--;
        }
        i = row, j = col;

        while (i >= 0 and col < n){
            if (board[i][j] == 'Q'){
                
            }
        }
    }
    void getCombinations(){

    }

public:
    vector<vector<string>> solvedQueens(int n){
        vector <vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        for (){

        }
    }
};