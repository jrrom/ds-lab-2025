#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

struct Node {
    struct Node* left;
    char data;
    struct Node* right;
};

typedef Node struct Node;

// Stack
struct Stack {
    char arr[SIZE];
    int topindex
};

typedef Stack struct Stack;

void push(Stack* stack, int value) {
    if (stack->top_index >= SIZE) {
        printf("Error! Stack overflow");
        exit(1);
    }

    stack->arr[++(stack->top_index)] = value;
}

void pop(Stack* stack) {
    if (stack->top_index == -1) {
        printf("Error! Stack underflow");
        exit(1);
    }

    return (stack->arr[(stack->top_index)--]);
}

// Traversal
// Size counting from 1
void inorder(Node* node, int* arr, int size) {
    Stack stack;
    stack.arr       = arr;
    stack.top_index = size - 1;
    
    if (!node) return;

    while (node->left) {
        stack.push(node->left);
    }
}
