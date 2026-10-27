#include <stdio.h>

#define MAX 50

int graph[MAX][MAX];
int n;
int visited[MAX];

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = -1;
    int i, u;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front <= rear) {
        u = queue[front++];
        printf("%d ", u);

        for (i = 0; i < n; i++) {
            if (graph[u][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

void dfsUtil(int u) {
    int i;

    visited[u] = 1;
    printf("%d ", u);

    for (i = 0; i < n; i++) {
        if (graph[u][i] && !visited[i])
            dfsUtil(i);
    }
}

void dfs(int start) {
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS: ");
    dfsUtil(start);
    printf("\n");
}

int main(void) {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(start);
    dfs(start);

    return 0;
}
