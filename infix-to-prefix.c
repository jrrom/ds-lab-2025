#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char postfix[128];

int strlen(char dest[]) {
    int count;
    for (count = 0; dest[count] != '\0'; count++);
    return count;
}

void strcat_char(char dest[], char src) {
    int len = strlen(dest);
    dest[len] = src;
    dest[len + 1] = '\0';
}

void reverse(char s[]) {
    int size = strlen(s);
    for (int i = 0; i < size / 2; i++) {
        char temp = s[size - 1 - i];
        s[size - 1 - i] = s[i];
        s[i] = temp;
    }
}

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(char data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void push(char data) {
    Node* new = createNode(data);
    new->next = head;
    head = new;
}

char pop() {
    if (head == NULL) {
        printf("Error! Stack Underflow\n");
        exit(1);
    }

    char data = head->data;
    Node* temp = head;
    head = head->next;
    free(temp);
    return data;
}

char peek() {
    if (head == NULL) {
        printf("Error! Peek Empty\n");
        exit(1);
    }
    return head->data;
}

bool is_operand(char c) {
    return ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z');
}

bool is_operator(char c) {
    return (c == '^') || (c == '*') || (c == '%') || (c == '/') || (c == '+') || (c == '-');
}

int prec(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '%':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void eval(char c[]) {
    for (int i = 0; c[i] != '\0'; i++) {
        char ch = c[i];

        if (is_operand(ch)) {
            strcat_char(postfix, ch);
            continue;
        }

        if (ch == ')') {
            push(ch);
            continue;
        }

        if (ch == '(') {
            while (peek() != ')')
                strcat_char(postfix, pop());
            pop(); // remove ')'
            continue;
        }

        if (is_operator(ch)) {
            while (head != NULL && prec(peek()) < prec(ch))
                strcat_char(postfix, pop());
            push(ch);
        }
    }

    while (head != NULL)
        strcat_char(postfix, pop());
}

int main() {
    char s[128];
    printf("Enter expression: ");
    scanf("%s", s);

    reverse(s);
//    push(')'); // sentinel for reversed expression

    eval(s);
    reverse(postfix);

    printf("Postfix: %s\n", postfix);
    return 0;
}
