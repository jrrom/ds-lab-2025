#include <stdio.h>
#include <stdbool.h>
#define SIZE 6

int queue[SIZE];
int head = -1;
int rear = -1;

bool is_empty() {
    return head == -1;
}

bool is_full() {
    return ((rear + 1) % SIZE) == head;
}

void enqueue(int value) {
    if (is_full()) {
        printf("Error! Queue is full\n");
        return;
    }
    if (is_empty()) {
        head = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
}

int dequeue() {
    if (is_empty()) {
        printf("Error! Queue underflow\n");
        return -1;
    }
    int value = queue[head];
    if (head == rear) {          // now becomes empty
        head = rear = -1;
    } else {
        head = (head + 1) % SIZE;
    }
    return value;
}

void display() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }

    int count = (rear - head + SIZE) % SIZE + 1;
    printf("Queue elements: ");
    for (int i = 0; i < count; i++) {
        int idx = (head + i) % SIZE;
        printf("%d ", queue[idx]);
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();           // 10 20 30
    printf("%d\n", dequeue());
    display();           // 20 30
    enqueue(40); enqueue(50); enqueue(60); enqueue(70);
    display();           // shows wrapped elements when full
    enqueue(80);         // prints "Error! Queue is full"
    return 0;
}

