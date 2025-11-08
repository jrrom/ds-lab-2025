#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6

int queue[MAX] = { 0 };
int front = -1, rear = -1;

bool is_empty() {
    return front == -1;
}

bool is_full() {
    return (rear + 1) % MAX == front;
}

void push(int data) {
    if (is_full()) {
        printf("Error! Queue overflow\n");
        exit(1);
    }
    if (front == -1) front = 0;
    
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}
int pop() {
    if (is_empty()) {
        printf("Error! Queue underflow\n");
        exit(1);
    }

    int data = queue[front];
    queue[front] = 0;

    if (front == rear) {
        // removing the last element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    return data;
}

void display() {
    for (int i = 0; i < MAX; i++) {
        if (queue[i] == 0) printf("_ ");
        else printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    display();
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    display();
    push(7);
    display();
    push(8);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
}
