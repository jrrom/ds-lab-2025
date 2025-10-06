#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 50

typedef struct {
    int id;
    char* name;
} Task;

Task queue[SIZE];
int head = -1;
int rear = -1;

void enqueue(Task value) {
    if (rear + 1 > SIZE) {
        printf("Error! Queue is fully utilised");
        exit(1);
    }
    queue[++rear] = value;
    if (head == -1) head++;
}

bool is_empty() {
    return head == rear;
}

Task dequeue() {
    if (head > rear) {
        printf("Error! Queue underflow");
        exit(1);
    }
    return queue[head++];
}

void display() {
    printf("\n===\nCurrent tasks:\n===\n");
    for (int i = head; i <= rear; i++) {
        printf("[%d] Task %d : %s", i, queue[i].id, queue[i].name);
        printf("\n");
    }
    printf("===\n\n");
}

void print_task() {
    Task to_print = dequeue();
    printf("Successfully printed - %d : %s\n", to_print.id, to_print.name);
}

int main() {
    Task t1 = {1090, "doc.pdf"};
    Task t2 = {1500, "hello.docx"};
    Task t3 = {1900, "hello.xlsx"};

    enqueue(t1);
    enqueue(t2);
    enqueue(t3);
    display();

    print_task();
    print_task();
    display();

    print_task();

    printf("Successfully completed\n");
}
