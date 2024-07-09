#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define INF INT_MAX

// Define the structure for an edge
typedef struct {
    int u, v, w;
} Edge;

// Function to implement Bellman-Ford algorithm
int* bellmanFord(int vertices, Edge edges[], int edges_count, int source) {
    int* distances = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; ++i) {
        distances[i] = INF;
    }
    distances[source] = 0;

    // Relax edges (vertices - 1) times
    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < edges_count; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (distances[u] != INF && distances[v] > distances[u] + w) {
                distances[v] = distances[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edges_count; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (distances[u] != INF && distances[v] > distances[u] + w) {
            free(distances);
            return NULL; // Return NULL to indicate a negative cycle
        }
    }

    return distances;
}

int main() {
    int vertices, edges_count;

    // Get input for number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges_count);

    // Get input for each edge (source, destination, weight)
    Edge* edges = (Edge*)malloc(edges_count * sizeof(Edge));
    for (int i = 0; i < edges_count; ++i) {
        printf("Enter source, destination, and weight for edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Get input for source vertex
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call Bellman-Ford algorithm
    int* distances = bellmanFord(vertices, edges, edges_count, source);

    // Print the distances
    if (distances == NULL) {
        printf("Graph contains a negative weight cycle!\n");
    } else {
        printf("Vertex \t\t Distance from Source\n");
        for (int i = 0; i < vertices; ++i) {
            if (distances[i] == INF) {
                printf("%d \t\t INF\n", i);
            } else {
                printf("%d \t\t %d\n", i, distances[i]);
            }
        }
        free(distances);
    }

    free(edges);
    return 0;
}

