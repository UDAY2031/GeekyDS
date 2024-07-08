#include<stdio.h>
#include<stdbool.h>
#define max 10

int count = 0;

bool issafe(int board[], int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void printsolution(int board[], int n) {
    printf("Solution %d:\n", count);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int board[], int row, int n) {
    if (row == n) {
        count++;
        printsolution(board, n);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (issafe(board, row, j)) {
            board[row] = j;
            solve(board, row + 1, n);
            board[row] = -1;
        }
    }
}

int main() {
    int n = 4;
    int board[max];
    for (int i = 0; i < n; ++i) {
        board[i] = -1;
    }
    solve(board, 0, n);
    printf("Total solutions for %d-Queens: %d\n", n, count);
    return 0;
}

