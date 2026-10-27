#include <stdio.h>

#define MAX 20
#define INF 10000000

void printMatrix(int dist[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%8s", "INF");
            else
                printf("%8d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int dist[MAX][MAX], int n) {
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(void) {
    int dist[MAX][MAX];
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for absent edge):\n", INF);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    printf("\nInitial Matrix:\n");
    printMatrix(dist, n);

    floydWarshall(dist, n);

    printf("\nFinal Distance Matrix:\n");
    printMatrix(dist, n);

    return 0;
}
