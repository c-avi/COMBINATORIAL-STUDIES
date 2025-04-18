#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        solve(0, n, board, result, leftRow, upperDiag, lowerDiag);
        return result;
    }
    
private:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& result, 
               vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDiag[row + col] == 0 && lowerDiag[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = upperDiag[row + col] = lowerDiag[n - 1 + col - row] = 1;
                
                solve(col + 1, n, board, result, leftRow, upperDiag, lowerDiag);
                
                board[row][col] = '.';
                leftRow[row] = upperDiag[row + col] = lowerDiag[n - 1 + col - row] = 0;
            }
        }
    }
};

// Function to display solutions
void printSolutions(const vector<vector<string>>& solutions) {
    if (solutions.empty()) {
        cout << "No solutions found.\n";
        return;
    }
    
    cout << "Total Solutions: " << solutions.size() << "\n";
    for (const auto& solution : solutions) {
        for (const string& row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of n (1-9): ";
    cin >> n;

    if (n < 1 || n > 9) {
        cout << "Invalid input! Please enter a number between 1 and 9.\n";
        return 1;
    }

    Solution solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    printSolutions(solutions);

    return 0;
}
