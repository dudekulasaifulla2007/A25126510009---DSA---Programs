#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS traversal
void DFS(int vertex) {
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int start, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initially no vertex is visited
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}