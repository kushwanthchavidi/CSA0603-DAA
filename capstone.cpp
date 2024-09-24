#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of ways to transform s into t in exactly k operations
int stringTransformation(char* s, char* t, int k) {
    int n = strlen(s);
    int match_count = 0;

    // Iterate through all possible rotations
    for (int i = 0; i < n; i++) {
        int is_match = 1;
        for (int j = 0; j < n; j++) {
            if (s[(i + j) % n] != t[j]) {
                is_match = 0;
                break;
            }
        }

        // If rotation matches t, check if k matches this rotation pattern
        if (is_match) {
            // If k is even and the rotation index i is even, or if both are odd,
            // then this is a valid transformation because every 2nd operation returns to a previous state.
            if ((k % 2 == 0 && i % 2 == 0) || (k % 2 == 1 && i % 2 == 1)) {
                match_count++;
            }
        }
    }

    return match_count % MOD;
}

int main() {
    char s[100], t[100];
    int k;

    // Input the strings and integer k from the user
    printf("Enter string s: ");
    scanf("%s", s);

    printf("Enter string t: ");
    scanf("%s", t);

    printf("Enter the number of operations k: ");
    scanf("%d", &k);

    // Call the function and display the result
    int result = stringTransformation(s, t, k);
    printf("Number of ways to transform s into t in exactly %d operations: %d\n", k, result);

    return 0;
}





 
