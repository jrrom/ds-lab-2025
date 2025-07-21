#include <stdio.h>

// Week 1 - Smallest, Largest in an Array

int size;
int main() {
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

    int smallest = arr[0];
    int largest  = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            break;
        }

        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("\n\n");

    printf("The largest number is %d\n", largest);
    printf("The smallest number is %d", smallest);
}

