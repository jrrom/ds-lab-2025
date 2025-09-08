// It is kind of messed.

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

struct Stack {
    char values[SIZE];
    int top;
};

typedef struct Stack stack;

int is_empty(stack* st) {
    return st->top == -1;
}

int is_full(stack* st) {
    return st->top == SIZE - 1;
}

void init(stack* st, char str[SIZE]) {
    st->top = -1;
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; st->values[i++] = str[i], st->top++)
        if (str[i] == ' ') {
            printf("\nError:\nNo spaces.");
        }

    int i;
    int k;
    for (i = 0, k = st->top; i <= k; i++, k--) {
        int temp = st->values[i];
        st->values[i] = st->values[k];
        st->values[k] = temp;
    }
}

void init_nostr(stack* st) {
    st->top = -1;
}

void display(stack* st) {
    for (int i = 0; i <= st->top; i++)
        printf("%c ", st->values[i]);
    printf("\n");
}

void append(stack* st, char value) {
    if (is_full(st)) {
        printf("\nError:\nStack overflow.\n");
        exit(1);
    }
    st->values[++st->top] = value;
}

char pop(stack* st) {
    if (is_empty(st)) {
        return '\0';
    }
    return st->values[st->top--];
}

char peek(stack* st) {
    return st->values[st->top];
}

int is_op(char in) {
    return in == '+' || in == '-' || in == '/' || in == '*' || in == '^';
}

int prec(char in) {
    switch (in) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main() {
    printf("Enter the infix expression:\n");
    char input[SIZE];
    fgets(input, SIZE, stdin);

    stack infix;
    init(&infix, input);
    display(&infix);

    stack main;
    init_nostr(&main);
    append(&main, '(');
    display(&main);

    stack postfix;
    init_nostr(&postfix);

    for (char popped = pop(&infix); popped != '\0'; popped = pop(&infix)) {
        if (popped == '(') append(&main, '(');
        else if (popped == ')') {
            for (char closing = pop(&main); closing != '('; closing = pop(&main)) {
                append(&postfix, closing);
            }
        }
        else if(isalnum(popped)) {
            append(&postfix, popped);
        }
        else {
            int main_prec = prec(popped);
            while (!is_empty(&main) && is_op(peek(&main)) && prec(peek(&main)) >= main_prec) {
                append(&postfix, pop(&main));
            }
            append(&main, popped);

        }
        display(&postfix);
    }

    while (!is_empty(&main)) {
        char op = pop(&main);
        if (op != '(') append(&postfix, op);
        display(&postfix);
    }


    display(&postfix);

}
