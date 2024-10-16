#include <iostream>
#include <cmath> // For abs() function
using namespace std;

int board[20], solutionCount = 0;

// Function to check if placing the queen in the current column is valid
bool isSafe(int row, int column) {
    for (int i = 1; i < row; i++) {
        // Check if there's another queen in the same column or diagonals
        if (board[i] == column || abs(board[i] - column) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Function to print the current board configuration
void printSolution(int n) {
    solutionCount++;
    cout << "\nSolution " << solutionCount << ":\n";

    // Print column numbers
    for (int i = 1; i <= n; i++) {
        cout << "\t" << i;
    }

    // Print the board
    for (int i = 1; i <= n; i++) {
        cout << "\n" << i; // Print row number
        for (int j = 1; j <= n; j++) {
            if (board[i] == j) {
                cout << "\tQ"; // Queen's position
            } else {
                cout << "\t-"; // Empty position
            }
        }
    }
    cout << endl;
}

// Function to solve the N-Queens problem using backtracking
void solveNQueens(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col; // Place the queen
            if (row == n) {
                printSolution(n); // If all queens are placed, print the solution
            } else {
                solveNQueens(row + 1, n); // Try placing the next queen
            }
        }
    }
}

int main() {
    int n;

    cout << "N-Queens Problem Using Backtracking\n";
    cout << "Enter the number of Queens: ";
    cin >> n;

    solveNQueens(1, n); // Start solving from the first row

    return 0;
}
