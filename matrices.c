#include <stdio.h>
#include <stdlib.h>

int** create(int rows, int cols) {
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < cols; i++)
        *(matrix + i) = (int *)malloc(sizeof(int) * cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }

    return matrix;
}

void display(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int** m = create(3, 3);
    display(m, 3, 3);
}
