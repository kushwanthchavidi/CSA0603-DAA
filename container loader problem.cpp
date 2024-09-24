#include <stdio.h>

int main() {
    int n;               
    int capacity;       
    int weights[100];    
    int values[100];     
    int dp[101][101];    
    printf("R.Babu Eshwar-192211778\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the container: ");
    scanf("%d", &capacity);

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i] <= w) {
                dp[i][w] = dp[i - 1][w] > (dp[i - 1][w - weights[i]] + values[i])
                           ? dp[i - 1][w] 
                           : dp[i - 1][w - weights[i]] + values[i];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("The maximum value that can be obtained is: %d\n", dp[n][capacity]);

    printf("Items included in the optimal solution:\n");
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weights[i], values[i]);
            w -= weights[i]; 
        }
    }

    return 0;
}

