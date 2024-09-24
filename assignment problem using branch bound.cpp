#include <stdio.h>
#include <limits.h>

int main() {
    int n; 
    int cost[20][20]; 
    int assigned[20]; 
    int min_cost = INT_MAX; 
    int solution[20]; 
    int temp_solution[20]; 
    int current_cost = 0; 
    printf("192211304");
    printf("Enter the number of agents/tasks: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (cost of assigning task j to agent i):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        assigned[i] = 0; 
        solution[i] = -1; 
    }

    int level = 0; 
    int i = 0;

    while (1) {
        while (i < n && assigned[i] == 1) {
            i++; 
        }

        if (i < n) {
            temp_solution[level] = i; 

            current_cost = 0;
            for (int j = 0; j <= level; j++) {
                current_cost += cost[j][temp_solution[j]];
            }

            if (current_cost < min_cost) { 
                if (level == n - 1) { 
                    min_cost = current_cost;
                    for (int k = 0; k < n; k++) {
                        solution[k] = temp_solution[k]; 
                    }
                } else {
                    assigned[i] = 1;
                    level++;
                    i = 0; 
                    continue;
                }
            }
        }

        if (i >= n || current_cost >= min_cost) {
            if (level == 0) {
                break;
            }

            level--;
            i = temp_solution[level];
            assigned[i] = 0;
            i++; 
        }
    }

    printf("The minimum cost is: %d\n", min_cost);
    printf("The optimal assignment is:\n");
    for (int i = 0; i < n; i++) {
        printf("Agent %d -> Task %d\n", i + 1, solution[i] + 1);
    }

    return 0;
}

