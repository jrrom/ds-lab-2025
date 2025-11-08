#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min]) min = j;

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i]   = temp;
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;            
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 6, 1, 34, 0, 9};
    int size = (sizeof(arr))/(sizeof(int));

    insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
