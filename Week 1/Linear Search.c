#include <stdio.h>

// Week 1 - Linear Search

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 1) {
        printf("Size of the array must be greater than 1");
        return -1;
    }

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int element;
    printf("\nEnter the element to search for: ");
    scanf("%d", &element);

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("The element is at position %d in the array", i);
        }
    }
}
