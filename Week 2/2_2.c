#include <stdio.h>

void selection_sort(int[], int, int, int, int);
// void selection_sort(int[], int);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter elements of the array: \n");
    for (int i = 0; i < size; i++)
      scanf("%d", &arr[i]);

    selection_sort(arr, size, 0, 1, 0);

    for (int i = 0; i < size; i++) {
	    printf("%d ", *(arr + i));
    }
}
/* void selection_sort(int arr[], int size) { */
/*     for (int i = 0; i < size - 1; i++) { */
/*         int m_index = i; */
/*         for (int j = i + 1; j < size; j++) { */
/*             if (arr[j] < arr[m_index]) m_index = j; */
/*         } */
/*         int swap = arr[m_index]; */
/*         arr[m_index] = arr[i]; */
/*         arr[i] = swap; */
/*     } */
/* } */

/* void selection_sort(int arr[], int size, int i, int j, int m_index) { */
/*     if (i >= size - 1) */
/*         return; */
    
/*     if (j >= size) { */
/*         int swap = arr[m_index]; */
/*         arr[m_index] = arr[i]; */
/*         arr[i] = swap; */
/*         return selection_sort(arr, size, i + 1, i + 2, i + 1); */
/*     } else if (arr[j] < arr[m_index]) { */
/*         return selection_sort(arr, size, i, j + 1, j); */
/*     } else { */
/*         return selection_sort(arr, size, i, j + 1, m_index); */
/*     } */
/* } */

void selection_sort(int arr[], int size, int i, int j, int m_index) {
    if (i >= size - 1)
        return;
    
    if (j >= size) {
        int swap = *(arr + m_index);
        *(arr + m_index) = *(arr + i);
        *(arr + i) = swap;
        return selection_sort(arr, size, i + 1, i + 2, i + 1);
    } else if (*(arr + j) < *(arr + m_index)) {
        return selection_sort(arr, size, i, j + 1, j);
    } else {
        return selection_sort(arr, size, i, j + 1, m_index);
    }
}
