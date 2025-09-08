#include <stdio.h>
#include <stdlib.h>

typedef struct Exponential exp;

struct Exponential {
    exp* prev;
    int coefficient;
    int exponent;
    exp* next;
};

exp* from_arr(int arr[], int size) {
    exp* first   = NULL;
    exp* current = NULL;

    for (int i = 0; i < size; i++) {
        exp* new = (exp *)malloc(sizeof(exp));
        
        new->coefficient = arr[i];
        new->exponent    = i;

        if (first == NULL)   first = new;
        if (current != NULL) current->next = new;
        new->prev = current;
        new->next = NULL;
        current = new;
    }

    return first;
}

int length(exp* e) {
    int i = 0;
    for (exp* current = e; current; current = current->next)
        i++;
    return i;
}

exp* sum(exp* a, exp* b) {
    int size_a = length(a);
    int size_b = length(b);
    int max_length = size_a > size_b ? size_a : size_b;
    int new[max_length];

    exp* max = size_a > size_b ? a : b;
    exp* min = size_a < size_b ? a : b;
    int i;
    
    for (i = 0; max && min; max = max->next, min = min->next, i++)
        new[i] = max->coefficient + min->coefficient;

    for (; max; max = max->next, i++)
        new[i] = max->coefficient;

    return from_arr(new, max_length);
}

void display(exp* e) {
    for (exp* current = e; current; current = current->next)
        printf("[%dx^%d] ", current->coefficient, current->exponent);
    printf("\n");
}

int main() {
    int n1;
    printf("Enter the size of the exponential to create : ");
    scanf("%d", &n1);
    int temp1[n1];
    for (int i = 0; i < n1; i++) {
        printf("Enter coefficient of x^%d : ", i);
        scanf("%d", &temp1[i]);
    }

    int n2;
    printf("Enter the size of the exponential to create : ");
    scanf("%d", &n2);
    int temp2[n2];
    for (int i = 0; i < n2; i++) {
        printf("Enter coefficient of x^%d : ", i);
        scanf("%d", &temp2[i]);
    }

    exp* a = from_arr(temp1, n1);
    exp* b = from_arr(temp2, n2);
    printf("\nExponential A is : \n");
    display(a);
    printf("\nExponential B is : \n");
    display(b);
    exp* c = sum(a, b);
    printf("\nA + B is : \n");
    display(c);
}
