#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

node * head = NULL;

void push (int value) {
    node* new = (node*) malloc(sizeof(node));
    new->data = value;
    new->next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    node* current;
    for (current = head; current->next != NULL; current = current->next);
    current->next = new;
}

int pop() {
    if (head == NULL) {
        printf("Underflow");
        exit(1);
    }

    node* current;
    for (current = head; current->next->next != NULL; current = current->next);
    int val = current->next->data;
    free(current->next); // deleting final node
    current->next = NULL;

    return val; // returning popped value
}

void display () {
    for (node * current = head; current != NULL; current = current->next) {
        printf("[%d]->", current->data);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    display();
    return 0;
}
