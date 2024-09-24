#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("R.Babu eshwar-192211778\n");
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n+1];  

    printf("Enter the dimensions of matrices (p0, p1, ..., pn):\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int m[n+1][n+1]; 

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("The minimum number of scalar multiplications is: %d\n", m[1][n]);

    return 0;
}

