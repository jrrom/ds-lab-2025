#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int c; // coefficient
    int p; // power
    struct Node* next;
};

typedef struct Node node;

node* head;

void init() {
    head = NULL;
}

void from_array(int arr[], int size) {
    if (size <= 0) exit(1);

    node* first = (node*) malloc(sizeof(node));
    first->c = arr[0]; first->p = 0;
    first->next = NULL;
    node* current = first;
    for (int i=0; i<size; i++) {
        node* new = (node*) malloc(sizeof(node));
        new->c = arr[i]; new->p = size-i-1;
        new->next = NULL;
        current->next = new;
        current = new;
    }
    head = first;
}

node* connect (node* head) {
    node* new = NULL;
    node* current = new;
    for (node* i = head; i != NULL; i=i->next) {
        if (i->c == 0) continue;

        node* next = (node*) malloc(sizeof(node));
        next->c = i->c;
        next->p = i->p;
        if (new == NULL) {
            new = next;
            current = new;
            continue;
        }
        current->next = next;
        current = next;
    }
    return new;
}

void display(node* head) {
    for (node* current=head; current != NULL; current=current->next) {
        printf("%dx^%d + ", current->c, current->p);
    }
    printf("\n");
}

int main() {
    init();
    int arr[] = {4,0,5,7};
    from_array(arr, 4);
    display(head);

    printf("Before:\n");
    display(head);

    node* new = connect(head);
    printf("After:\n");
    display(new);

    
    return 0;
}

