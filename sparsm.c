#include <stdio.h>
#include <stdlib.h>

int arr[100];
int top = -1;

void insert(int data) {
    if (top == -1) {
        arr[++top] = data;
        return;
    }
    
    int position = top + 1;
    for (int i = 0; i <= top; i++) {
        if (data < arr[i]) {
            position = i;
            break;
        }
    }

    for (int i = top + 1; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = data;
    top++;
}

void display() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(200);
    insert(300);
    insert(150);
    display();
}
