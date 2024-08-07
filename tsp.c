#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 10

void tsp(int graph[MAX][MAX], bool visited[], int currpos, int n, int count, int cost, int* ans) {
    if (count == n && graph[currpos][0] > 0) {
        if (*ans > cost + graph[currpos][0]) {
            *ans = cost + graph[currpos][0];
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (graph[currpos][i] > 0 && !visited[i]) {
            visited[i] = true;
            tsp(graph, visited, i, n, count + 1, cost + graph[currpos][i], ans);
            visited[i] = false;
        }
    }
}

int main() {
    int n = 5;  // Number of cities
    int graph[MAX][MAX] = {
        {0, 2, 0, 12, 5},  // A
        {2, 0, 8, 4, 0},   // B
        {0, 8, 0, 3, 3},   // C
        {12, 4, 3, 0, 10}, // D
        {5, 0, 3, 10, 0}   // E
    };

    int start = 0;  // Starting node A (0-indexed)
    bool visited[MAX] = {false};
    visited[start] = true;
    int ans = INT_MAX;

    tsp(graph, visited, start, n, 1, 0, &ans);
    printf("The minimum cost is: %d\n", ans);

    return 0;
}
