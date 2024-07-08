#include <stdio.h>
#include <stdlib.h>

int knapsack(int mcap, int weights[], int values[], int n, int** m) {
    for (int i = 0; i <= n; ++i) {
        m[i][0] = 0;
    }
    for (int j = 0; j <= mcap; ++j) {
        m[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= mcap; ++j) {
            if (weights[i - 1] > j) {
                m[i][j] = m[i - 1][j];
            } else {
                int a = m[i - 1][j];
                int b = values[i - 1] + m[i - 1][j - weights[i - 1]];
                m[i][j] = (b > a) ? b : a;
            }
        }
    }
    return m[n][mcap];
}

void finditem(int **M, int weights[], int n, int mcap) {
    int i = n;
    int k = mcap;
    while (i > 0 && k > 0) {
        if (M[i][k] != M[i - 1][k]) {
            printf("%d\n", i - 1);
            k -= weights[i - 1];
        }
        i--;
    }
    printf("\n");
}

int main() {
    int items[] = {1, 2, 3, 4};
    int weights[] = {3, 5, 6, 2};
    int values[] = {10, 4, 9, 11};
    int mcap = 7;
    int n = sizeof(weights) / sizeof(weights[0]);
    int **M = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        M[i] = (int*)calloc(mcap + 1, sizeof(int));
    }
    int result = knapsack(mcap, weights, values, n, M);
    printf("%d\n", result);
    finditem(M, weights, n, mcap);
    for (int i = 0; i <= n; i++) {
        free(M[i]);
    }
    free(M);
    return 0;
}

