#include <stdio.h>
#define inf 99999999
#define n 5

int cost[n][n] = {
    { 0, 10, 0, 0, 5 },
    { 10, 0, 1, 6, 0 },
    { 0, 1, 0, 2, 0 },
    { 0, 6, 2, 0, 3 },
    { 5, 0, 0, 3, 0 }
}, parent[n];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int union_find(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, ne = 1, min, mincost = 0;

    printf("The edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        min = inf;

        // Find the minimum cost edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        u = find(a);
        v = find(b);

        // If including this edge does not form a cycle
        if (union_find(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a + 1, b + 1, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = inf;  // Mark the edge as visited
    }

    printf("The minimum cost is %d\n", mincost);

    return 0;
}
