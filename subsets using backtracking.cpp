#include <stdio.h>

int main() {
    int n, target_sum;
    int set[20];        // Array to store the set of elements
    int subset[20];     // Array to store the current subset
    int current_sum = 0; // Track the sum of the current subset
    int include[20];    // To mark whether the element is included in the subset
    printf("C.Kushwanthu-192211304\n");
    // Input: number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    // Input: elements of the set
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input: target sum to achieve
    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    int total_sum = 0;
    // Calculate the total sum of the set
    for (int i = 0; i < n; i++) {
        total_sum += set[i];
    }

    // Initialize all elements of include array to 0 (not included in subset initially)
    for (int i = 0; i < n; i++) {
        include[i] = 0;
    }

    int i = 0;
    current_sum = 0;  // Start with an empty subset and a sum of 0

    // Start exploring the subsets
    while (1) {
        // Include element set[i] in the current subset if it does not exceed target_sum
        if (i < n && current_sum + set[i] <= target_sum) {
            include[i] = 1; // Include the element in the subset
            current_sum += set[i]; // Update current sum

            // If current_sum equals target_sum, print the subset
            if (current_sum == target_sum) {
                printf("Subset found: { ");
                for (int j = 0; j <= i; j++) {
                    if (include[j]) {
                        printf("%d ", set[j]);
                    }
                }
                printf("}\n");
            }
            i++; // Move to the next element
        }
        // Backtrack: If current_sum + set[i] exceeds target_sum or we have reached the last element
        else {
            while (i >= 0 && include[i] == 0) {
                i--;  // Move back to the previous element
            }

            if (i < 0) {
                break;  // If i is negative, break out of the loop, exploration is done
            }

            include[i] = 0;  // Exclude the current element from the subset
            current_sum -= set[i];  // Adjust the sum by removing set[i]
            i++;
        }
    }

    return 0;
}

