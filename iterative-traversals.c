#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 48

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    int top;
    Node** arr;
} Stack;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top   = -1;
    stack->arr   = (Node**)malloc(sizeof(Node) * MAX);

    return stack;
}

bool is_empty(Stack* stack) {
    return stack->top == -1;
}

bool is_full(Stack* stack) {
    return stack->top + 1 >= MAX;
}

void push(Stack* stack, Node* node) {
    if (is_full(stack)) {
        printf("Error! Stack Overflow\n");
        return;
    }

    stack->arr[++stack->top] = node;
}

Node* pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Error! Stack Underflow\n");
        exit(1);
    }

    return stack->arr[stack->top--];
}

Node* peek(Stack* stack) {
    if (is_empty(stack)) return NULL;
    return stack->arr[stack->top];
}

// Traversals

void inorderIterative(Node* root) {
    if (root == NULL) return;

    Stack *stack = createStack();
    Node* current = root;
    while (current != NULL || !is_empty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

void preorderIterative(Node* root) {
    if (root == NULL) return;

    Stack* stack = createStack();
    push(stack, root);

    while (!is_empty(stack)) {
        Node* current = pop(stack);
        printf("%d ", current->data);

        if (current->right)
            push(stack, current->right);

        if (current->left)
            push(stack, current->left);
    }
}

void postorderIterative(Node* root) {
    if (root == NULL) return;

    Stack* stack1 = createStack();
    Stack* stack2 = createStack();

    push(stack1, root);
    while (!is_empty(stack1)) {
        Node* current = pop(stack1);
        push(stack2, current);

        if (current->left)
            push(stack2, current->left);

        if (current->right)
            push(stack2, current->right);
    }

    while (!is_empty(stack2)) {
        Node* current = pop(stack2);
        printf("%d ", current->data);
    }
}

int main() {
    // Create a sample tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("Inorder traversal:   ");
    preorderIterative(root);
    printf("\n");
}    

