#include <stdio.h>
#include <limits.h>

#define n 5

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < n; i++)
        if (!sptSet[i] && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

void dijkstra(int graph[n][n], int src) {
    int dist[n], sptSet[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX, sptSet[i] = 0;
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int i = minDistance(dist, sptSet);
        sptSet[i] = 1;
        for (int j = 0; j < n; j++)
            if (!sptSet[j] && graph[i][j] && dist[i] != INT_MAX && dist[i] + graph[i][j] < dist[j])
                dist[j] = dist[i] + graph[i][j];
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; i++) printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int graph[n][n] = {
        {0, 10, 0, 0, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {0, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

