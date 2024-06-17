#include <stdio.h>

#define n 5 // Number of nodes in the graph

// Function to perform DFS
void DFS(int graph[n][n], int visited[], int node) {
    // Mark the current node as visited
    visited[node] = 1;
    printf("%d ", node); // Add a space after %d to separate node numbers

    // Visit all the adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, visited, i); // Corrected line
        }
    }
}

int main() {
    // Define the graph as an adjacency matrix
    int graph[n][n] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    int visited[n] = {0}; // Array to keep track of visited nodes

    int startnode;
    printf("Enter the start node: ");
    scanf("%d", &startnode);

    printf("DFS traversal starting from node %d: ", startnode);
    DFS(graph, visited, startnode);
    printf("\n");

    return 0;
}

