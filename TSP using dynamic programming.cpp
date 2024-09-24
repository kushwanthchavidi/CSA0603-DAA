#include <stdio.h>
#include <limits.h>

#define MAX 16  
#define INF INT_MAX  

int dist[MAX][MAX];  
int dp[1 << MAX][MAX];  
int n;  

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];  
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int answer = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAnswer = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAnswer < answer) {
                answer = newAnswer;
            }
        }
    }

    dp[mask][pos] = answer;
    return answer;
}

int main() {
	printf("C.Kushwanthu-192211304\n");
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0);

    printf("The minimum cost of the TSP is: %d\n", result);

    return 0;
}

