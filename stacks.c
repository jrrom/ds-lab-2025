#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int data) {
    if (top + 1 > MAX) {
        printf("Error! Stack overflow.\n");
        exit(1);
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Error! Stack underflow.\n");
        printf("\nNot balanced\n");
        exit(1);
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Error! Peek Empty\n");
        exit(1);
    }
    return stack[top];
}

void display() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

// Program to check if ([{}]) is correct

int delimiter(char c) {
    switch (c) {
    case ')':
    case ']':
    case '}': return 2;
    case '(':
    case '[':
    case '{': return 1;
    default : return 0;
    }
}

int matches(char open, char close) {
    return (open == '(' && close == ')')
           || (open == '[' && close == ']')
           || (open == '{' && close == '}');
}

int check(char c[]) {
    for (int i = 0; c[i] != '\0'; i++) {
        switch(delimiter(c[i])) {
            
        case 1:
            push(c[i]);
            break;
            
        case 2: {
            if (matches(pop(), c[i])) {
                continue;
            } else {
                printf("Not balanced\n");
                exit(1);
            }
        }
            
        }
    }

    return top == -1;
}

int main() {
    char c[MAX];

    printf("Enter expression to check : ");
    scanf("%s", c);

    printf("%s\n", check(c) == 1 ? "Balanced" : "Not balanced");
}
