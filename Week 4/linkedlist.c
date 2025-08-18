#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node {
    int head;
    node* tail;
};

void print_list(node* element) {
    for (node* i = element; i->tail; i = i->tail) {
        printf("%d\t", i->head);
    }
}

node* create_list(int arr[], int size) {
    node* first = (node*)malloc(sizeof(node*));
    node* current = first;
    for (int i = 0; i < size; i++) {
        current->head = arr[i];

        node* next = (node*)malloc(sizeof(node*));
        next->tail = NULL;

        current->tail = next;
        current = next;
    }
    return first;
}

enum Switch {
    BEFORE,
    AFTER
};

void insert(node* element, int value, int pos, enum Switch option) {
    node* current = element;
    int until = option == BEFORE ? pos - 1 : pos;

    if (option == BEFORE && pos == 0) {
        printf("\nN/A\n");
        return;
    }

    for (int i = 0; i < until; i++) {
        if (!current->tail) {
            printf("\nError!\n");
            return;
        }
        current = current->tail;
    }
    node* next = (node*)malloc(sizeof(node*));
    next->head = value;
    next->tail = current->tail;
    current->tail = next;
}

node* insert_head(node* element, int value) {
    node* first = (node*)malloc(sizeof(node*));
    first->head = value;
    first->tail = element;
    return first;
}

void delete(node* element, int pos) {
    node* current = element;
    for (int i = 0; i < pos; i++) {
        if (!current->tail) {
            printf("\nError!\n");
            return;
        }
        current = current->tail;
    }
    node* next = current->tail->tail;

    // If it is the last element
    if (!next) {
        free(current->tail);
        current->tail = NULL;
        return;
    }

    free(current->tail);
    current->tail = next;
}

node* reverse(node* element) {
    node* new = (node*)malloc(sizeof(node*));
    new->head = element->head;
    new->tail = NULL;
    for (node* current = element; current->tail; current = current->tail) {
        new = insert_head(new, current->head);
    }
    return new;
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5 };
    node* list = create_list(nums, 5);
    node* list2 = reverse(list);
    print_list(list2);

    return 0;
}
