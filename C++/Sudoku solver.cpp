// Github username: Codebraker7
// Aim: my aim is to participate in ongoing Hacktoberfest 2022 by contributing to this repo.
// Date: 4th October, 2022

//Start coding
#include <bits/stdc++.h>
using namespace std;

bool canPlace(int sudoku[][9], int n, int i, int j, int num) {
    // Check if placing the number i is safe or not
    // Check in row and column
    for (int x = 0; x < n; x++) {
        if (sudoku[i][x] == num || sudoku[x][j] == num) {
            return false;
        }
    }
    // Check in subgrid
    int t = sqrt(n);
    // For this first find which subgrid it is((0,0),(1,2),(2,1) etc)
    // can be done by dividing current cell by 3
    // And then find the starting point of that subgrid of that subgrid.
    // formula ->
    // for row - (i/t)*t  [i/t is for identifying subgrid and *t is
    // for finding row of starting cell of the subgrid]
    // for col - (j/t)*t  [j/t is for identifying subgrid and *t is for
    // finding col of starting cell of the subgrid]
    int sx = (i / t) * t;
    int sy = (j / t) * t;
    for (int i = sx; i < sx + t; i++) {
        for (int j = sy; j < sy + t; j++)
            if (sudoku[i][j] == num) {
                return false;
            }
    }
    // If NOTA then number can be placed at that cell
    return true;
}

bool sudokuSolver(int sudoku[][9], int n, int i, int j) {
    // Base case
    if (i == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << endl;
        }
        return true;
    }
    // When a row ends
    if (j == n) {
        return sudokuSolver(sudoku, n, i + 1, 0);
    }
    // Skip pre-filled cells
    if (sudoku[i][j] != 0) {
        return sudokuSolver(sudoku, n, i, j + 1);
    }
    // Recursive case
    // Fill current cell with possible options
    for (int num = 1; num <= n; num++) {
        if (canPlace(sudoku, n, i, j, num)) {
            // Fill the cell assuming that number is right for this cell.
            sudoku[i][j] = num;
            bool ans = sudokuSolver(sudoku, n, i, j + 1);
            if (ans) {
                return true;
            }
        }
    }
    // Backtrack here because ek cell ke liye saare numbers try karenge pehle
    // and fir saaron se false aaya toh jaake hum peeche wala number change
    // karenge to zero and try another number there.
    sudoku[i][j] = 0;
    return false;
}

int main() {
    int n = 9;
    int sudoku[9][9] = 
        {
            {4,0,0,3,0,0,8,0,0},
            {0,0,2,0,0,9,0,0,0},
            {0,0,0,0,0,0,0,7,0},
            {0,7,6,0,8,0,0,0,0},
            {0,0,0,4,0,0,9,0,0},
            {0,0,0,5,0,0,0,0,0},
            {9,8,0,0,0,0,5,0,0},
            {0,0,0,0,6,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}
        };
    sudokuSolver(sudoku, n, 0, 0);
    return 0;
}