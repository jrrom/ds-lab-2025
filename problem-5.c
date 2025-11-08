#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int  top = -1;

void push(char c) {
    if (top >= MAX) {
        printf("Error! Stack overflow\n");
        exit(1);
    }

    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("False\n");
        exit(1);
    }

    return stack[top--];
}

char peek() {
    return stack[top];
}

void display() {
    for (int i = 0; i <= top; i++) {
        printf("%c, ", stack[i]);
    }
    printf("\n");
}

int delimiter_type(char c) {
    switch (c) {
    case '(':
    case '{':
    case '[': return 1;
    case ')':
    case '}':
    case ']': return 2;
    default: return 0;
    }
}

int matches(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

void eval(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        switch (delimiter_type(s[i])) {
        case 1:
            push(s[i]);
            display();
            break;
        case 2: {
            int c = peek();
            if (matches(c, s[i])) {
                pop();
                display();
            }
            else {
                printf("Error! Doesn't match: \n%c %c\n", s[i], c);
                printf("False\n");
                exit(1);
            }
        }
        default:
            break;
        }
    }
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    fgets(expr, 100, stdin);
    eval(expr);
    printf("True\n");
    return 0;
}
