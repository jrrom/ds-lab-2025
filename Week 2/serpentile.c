// To print matrix like snake

// Directives
#include<stdio.h>

int main() {
    int m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter matrix:\n");
    int A[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) printf("%d ", A[i][j]);
            else printf("%d ", A[i][n - j - 1]);
        }
        printf("\n");
    }
}
