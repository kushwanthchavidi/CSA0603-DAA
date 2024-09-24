#include <stdio.h>

#define INF 99999  
#define MAX 10  

int main() {
    int n;  
    int dist[MAX][MAX];  
    printf("C.Kushwanthu-192211304\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the distance matrix (use %d to represent infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nThe shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");  
            } else {
                printf("%7d", dist[i][j]);  
            }
        }
        printf("\n");
    }

    return 0;
}

