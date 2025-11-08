#include <stdio.h>
#include <stdlib.h>

// C program to implement a SLL

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    return new;
}

void display() {
    for (Node* current = head; current; current = current->next) {
        printf("%d->", current->data);
    }
    printf("NULL\n");
}

void prepend(int data) {
    Node* new = createNode(data);
    new->next = head;
    head = new;
    return;
}

void append(int data) {
    Node* new = createNode(data);
    Node* current = head;

    if (head == NULL) {
        head = new;
        return;
    }
    
    while (current->next != NULL)
        current = current->next;

    current->next = new;
}

void insert(int data, int index) {
    Node* new = createNode(data);

    if (index == 0 || head == NULL) {
        new->next = head;
        head = new;
        return;
    }

    Node* current = head;
    for (int i = 0; current->next && i < index - 1; i++)
        current = current->next;

    new->next = current->next;
    current->next = new;
}

void sort() {
    for (Node* i = head; i; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

void reverse() {
    Node* prev    = NULL;
    Node* current = head;
    Node* next    = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main() {
    append(5);
    append(10);
    append(15);

    insert(12, 5);
    
    display();
    sort();
    display();
    reverse();
    display();
}
