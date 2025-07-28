// To find the smallest element of the array using pointers

// Preprocessor directives
#include <stdio.h>

void find_smallest(int[], int, int*)

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    find_smallest(arr, n, &smallest);

    printf("The smallest element in the array is: %d\n", smallest);
}

void find_smallest(int arr[], int size, int* smallest) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < *smallest) *smallest = arr[i];
    }
}
