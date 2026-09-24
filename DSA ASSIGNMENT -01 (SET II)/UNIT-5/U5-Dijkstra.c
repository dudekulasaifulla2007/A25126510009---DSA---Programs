#include <stdio.h>

#define MAX 20
#define INF 99999

int main() {
    int n, i, j, source;
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    printf("(Enter 0 if there is no direct road)\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    // Dijkstra's algorithm
    for (i = 1; i < n; i++) {

        int min = INF;
        int u = -1;

        // Find unvisited vertex with minimum distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        // No more reachable vertices
        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != INF &&
                distance[u] + graph[u][j] < distance[j]) {

                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    // Display result
    printf("\nShortest distances from source vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Vertex %d -> Unreachable\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }

    return 0;
}