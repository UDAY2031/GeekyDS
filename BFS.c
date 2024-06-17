#include <stdio.h>
#include <stdbool.h>

#define n 5 // Number of nodes in the graph

// Function to perform BFS
void BFS(int graph[n][n], int startnode) {
    bool visited[n] = {0}; // Array to keep track of visited nodes
    int queue[n];
    int front = 0, rear = 0;

    queue[rear++] = startnode;
    visited[startnode] = 1;

    printf("BFS traversal starting from node %d: ", startnode);

    while (front < rear) {
        int currentnode = queue[front++];
        printf("%d ", currentnode); // Add space for readability

        for (int i = 0; i < n; i++) {
            if (graph[currentnode][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[n][n] = {
        {0, 1, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    int startnode;
    printf("Enter the start node (0 to 4): ");
    scanf("%d", &startnode);

    BFS(graph, startnode);

    return 0;
}

