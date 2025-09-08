#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
    int value;
    node* tail;
};

node *create(int arr[], int size) {
    node *first  = (node *)malloc(sizeof(node));
    first->value = arr[0];

    node* current = first;
    for (int i = 1; i < size; i++) {
        node* new  = (node *)malloc(sizeof(node));
        new->value = arr[i];
        current->tail = new;
        current = new;
    }
    current->tail = first;
    return first;
}

node *get_last(node *first) {
    node *current;
    for (current = first; current->tail != first; current = current->tail);

    return current;
}

void append(node *first, int value) {
    node *current;
    for (current = first; current->tail != first; current = current->tail);

    node *new  = (node *)malloc(sizeof(node));
    new->value = value;
    new->tail  = first;

    current->tail = new;
}

void delete(node *first) {
    node *current;
    for (current = first; current->tail->tail != first; current = current->tail);

    node *delete = current->tail;
    current->tail = current->tail->tail;
    free(delete);
}

void delete_start(node **n) {
    node* current;
    for (current = *n; current->tail != *n; current = current->tail);

    node *delete = current->tail;
    current->tail = current->tail->tail;
    free(delete);

    *n = current->tail;
}

void display(node *first) {
    for (node *current = first;; current = current->tail) {
        printf("[%d] ", current->value);
        if (current->tail == first) break;
    }
    printf("\n");
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    node *val = create(arr, 5);
    
    append(val, 6);
    display(val);
    
    delete(val);
    display(val);
    delete_start(&val);
    display(val);
}

/*
[1] [2] [3] [4] [5] [6] 
[1] [2] [3] [4] [5] 
[2] [3] [4] [5] 
*/
