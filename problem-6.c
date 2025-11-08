#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

char queue[SIZE];
int front = -1, rear = -1;

int is_full() {
    return front == (rear + 1) % SIZE;
}

int is_empty() {
    return front == -1;
}

int peek() {
    return queue[front];
}

void display() {
    printf("Queue: [");
    for (int i = 0; i < SIZE; i++) {
        if (queue[i])
            printf("%c, ", queue[i]);
        else
            printf("_, ");
    }
    printf("\b\b]");
    printf("\tfront=%d\trear=%d\n", front, rear);
}

void enqueue(int value) {
    if (is_full()) {
        printf("Error! Queue overflow\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    if (front == -1) front = 0;
    display();
}

int dequeue() {
    if (is_empty()) {
        printf("Error! Queue underflow\n");
        return -1;
    }
    queue[front] = '_';
    front = (front + 1) % SIZE;
    int value = queue[front];
    display();
    return value;
}

int main() {
    printf("Enqueue Operations:\n");
    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('D');
    enqueue('E');

    printf("\nDequeue Operations:\n");
    dequeue();
    dequeue();

    printf("\nEnqueue with Wrap-Around:\n");
    enqueue('F');
    enqueue('G');
}
