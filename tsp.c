#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define max 10

void tsp(int graph[max][max], bool visited[], int currpos, int n, int count, int cost, int* ans) {
    if(count == n && graph[currpos][0] > 0) {
        if(*ans > cost + graph[currpos][0]) {
            *ans = cost + graph[currpos][0];
        }
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(graph[currpos][i] > 0 && !visited[i]) {
            visited[i] = true;
            tsp(graph, visited, i, n, count + 1, cost + graph[currpos][i], ans);
            visited[i] = false;
        }
    }
}

int main() {
    int n, edge, start;
    printf("Enter the number of cities:\n");
    scanf("%d", &n);
    printf("Enter the number of edges:\n");
    scanf("%d", &edge);

    int graph[max][max] = {0};
    printf("Enter the distance in format of c1 c2 distance:\n");
    for(int i = 0; i < edge; ++i) {
        int c1, c2, distance;
        scanf("%d %d %d", &c1, &c2, &distance);
        c1--;  // Adjusting to 0-based index
        c2--;  // Adjusting to 0-based index
        graph[c1][c2] = distance;
        graph[c2][c1] = distance;  // Assuming undirected graph
    }

    printf("Enter the start node:\n");
    scanf("%d", &start);
    start--;  // Adjusting to 0-based index

    bool visited[max] = {false};
    visited[start] = true;
    int ans = INT_MAX;

    tsp(graph, visited, start, n, 1, 0, &ans);
    printf("The minimum cost is: %d\n", ans);

    return 0;
}

