/* You are given a sorted array of distinct integers, arr, and a target integer, target. Your */
/* task is to implement a recursive binary search algorithm to find the index of target */
/* within arr. If target is not present, the function should return -1. */
/* Implement the same on the given array to find the element 23 */

/* arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91] */

/* Note: Use dynamic memory allocation functions and pointers to create memory */
/* and access the elements of an array. */

#include <stdio.h>
#include <stdlib.h>

int bin_search(int *arr, int size, int target, int high, int low) {
    int medium = (high + low) / 2;
    
    if (low > high) return -1;

    if (*(arr + medium) == target) return medium;
    if (*(arr + medium) < target)
        return bin_search(arr, size, target, high, medium + 1);
    if (*(arr + medium) > target)
        return bin_search(arr, size, target, medium - 1, low);
    
}

void display(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d]", *(arr + i));
            return;
        }
        printf("%d, ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n;
    int target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter %d : ", i + 1);
        scanf("%d", arr + i);
    }

    printf("\nThe entered array is: \n");
    display(arr, n);

    printf("\nEnter the target to search for : ");
    scanf("%d", &target);

    int val = bin_search(arr, n, target, n - 1, 0);
    if (val == - 1) {
        printf("The value is not present.\n");
        return 1;
    }

    printf("The value is present at index %d", val);
    return 0;
}
