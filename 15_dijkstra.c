#include <stdio.h>

#define MAX 50
#define INF 10000000

int findMinDistance(int dist[], int visited[], int n) {
    int i;
    int min = INF;
    int minIndex = -1;

    for (i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX];
    int i, count, u, v;

    for (i = 0; i < n; i++) {
        dist[i] = graph[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;

    for (count = 0; count < n - 1; count++) {
        u = findMinDistance(dist, visited, n);

        if (u == -1)
            break;

        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] != INF &&
                dist[v] > dist[u] + graph[u][v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> %d = INF\n", source, i);
        else
            printf("%d -> %d = %d\n", source, i, dist[i]);
    }
}

int main(void) {
    int graph[MAX][MAX];
    int n, i, j, source, destination;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix.\n");
    printf("Use %d for no edge.\n", INF);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    printf("\nEnter end vertex to see its distance: ");
    scanf("%d", &destination);

    /* Run again to obtain the requested source-to-destination distance. */
    {
        int dist[MAX], visited[MAX];
        int count, u, v;

        for (i = 0; i < n; i++) {
            dist[i] = graph[source][i];
            visited[i] = 0;
        }

        dist[source] = 0;

        for (count = 0; count < n - 1; count++) {
            u = findMinDistance(dist, visited, n);
            if (u == -1) break;
            visited[u] = 1;

            for (v = 0; v < n; v++) {
                if (!visited[v] &&
                    graph[u][v] != INF &&
                    dist[u] != INF &&
                    dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        if (destination < 0 || destination >= n ||
            dist[destination] == INF)
            printf("No path exists.\n");
        else
            printf("Shortest distance from %d to %d = %d\n",
                   source, destination, dist[destination]);
    }

    return 0;
}
