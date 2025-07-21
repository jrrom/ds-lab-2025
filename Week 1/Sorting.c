#include <stdio.h>


// Week 1 - Sorting


void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int m_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[m_index]) {
                m_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[m_index];
        arr[m_index] = temp;
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int key = arr[i];
        while (i - 1 >= 0 && key < arr[i - 1]) {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[i] = key;
    }
}

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

    // Sorting
    int menu;
    printf("\nEnter 1 to use Bubble Sort\nEnter 2 to use Selection Sort\nEnter 3 to use Insertion Sort\n");
    scanf("%d", &menu);

    switch (menu) {
    case 1:
        bubble_sort(arr, size);
        break;
    case 2:
        selection_sort(arr, size);
        break;
    case 3:
        insertion_sort(arr, size);
        break;
    default:
        printf("Please enter valid inputs");
        return;
    }

    // Printing
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

