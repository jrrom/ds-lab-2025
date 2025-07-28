// Program to multiply two matrices

// Preprocessor directives
#include<stdio.h>

// Main function
int main() {
    int row1, row2, col1, col2;
    printf("Enter dimensions of matrix A: ");
    scanf("%d %d", &row1, &col1);
    int A[row1][col1];

    printf("Enter dimensions of matrix B: ");
    scanf("%d %d", &row2, &col2);
    int B[row2][col2];

    if (col1 != row2) {
        printf("\nThe columns of the first array must be equal to the rows of the second array\n");
        return -1;
    }

    printf("\nEnter the values of the matrix A:\n");
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter the values of the matrix B:\n");
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            scanf("%d", &B[i][j]);

    // Matrix multiplication
    int C[row1][col2];
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            C[i][j] = 0;
            for (int k = 0; k < row2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}
