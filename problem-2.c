/* Design and implement a C program to efficiently represent and perform basic */
/* operations on a sparse matrix using a suitable data structure. */
/* Case Study: Consider a 5x5 sparse matrix where the non-zero elements are: */
/* (5, 5, 5), (0, 2, 5), (1, 1, 9), (2, 4, 3), (3, 0, 7), (4, 3, 1) */

/* Implementation: Implement the following functions in C: */
/* • createSparseMatrix(int rows, int cols, int numNonZero): Initializes the sparse */
/* matrix structure. */
/* • insertElement(SparseMatrix* matrix, int row, int col, int value): Inserts a non- */
/* zero element into the sparse matrix. */
/* • displaySparseMatrix(SparseMatrix* matrix): Displays the sparse matrix in a user- */
/* friendly format (e.g., triplet form or a reconstructed 2D matrix). */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int numNonZero;
    int top;
    int** matrix;
} SparseMatrix;

SparseMatrix *createSparseMatrix(int rows, int cols, int numNonZero) {
    SparseMatrix *s = (SparseMatrix *)malloc(sizeof(SparseMatrix));
    s->rows = rows;
    s->cols = cols;
    s->numNonZero = numNonZero;
    s->top  = 0;

    s->matrix = (int **)malloc(sizeof(int*) * numNonZero);
    return s;
}

void displaySparseMatrix(SparseMatrix* matrix) {
    printf("Sparse matrix in triplet form:\n");
    printf("row,\tcol,\tvalue\n");
    for (int i = 0; i < matrix->top; i++) { // fixed: i < top
        int* row = matrix->matrix[i];
        printf("(%d,\t%d,\t%d)\n", row[0], row[1], row[2]); // optional newline for readability
    }
    printf("\n");
}

void insertElement(SparseMatrix* matrix, int row, int col, int value) {
    if (value == 0) {
        printf("Error! Value must be non-zero.\n");
        return;
    }

    // fixed: correct capacity check
    if (matrix->top >= matrix->numNonZero) {
        printf("Error! Cannot add to full matrix.\n");
        return;
    }

    // fixed: avoid dereferencing uninitialized pointer when top == 0
    int position = matrix->top; // default append
    if (matrix->top > 0) {
        for (int i = 0; i < matrix->top; i++) { // fixed: i < top
            int current_row = matrix->matrix[i][0];
            int current_col = matrix->matrix[i][1];

            if (row < current_row || (row == current_row && col < current_col)) {
                position = i;
                break;
            }

            if (row == current_row && col == current_col) {
                printf("Error! Element already exists.\n");
                return;
            }
        }
    }

    // fixed: shift only initialized entries: from top-1 down to position
    for (int i = matrix->top - 1; i >= position; i--) {
        matrix->matrix[i + 1] = matrix->matrix[i];
    }

    int* triplet = (int*)malloc(sizeof(int) * 3);
    triplet[0] = row;
    triplet[1] = col;
    triplet[2] = value;
    matrix->matrix[position] = triplet;
    matrix->top++;
}

int main() {
    int rows, cols, n;
    printf("Enter no. of rows, no. of cols, and number of elements : ");
    scanf("%d %d %d", &rows, &cols, &n);

    SparseMatrix *s = createSparseMatrix(rows, cols, n);
    for (int i = 0; i < n; i++) {
        int row, col, value;
        printf("Enter row %d : ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        insertElement(s, row, col, value);
    }

    printf("\n\nThe final sparse matrix is:\n");
    displaySparseMatrix(s);

    return 0;
}
