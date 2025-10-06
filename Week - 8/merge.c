#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* new_node(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->next = NULL;
    return n;
}

Node* append(Node *head, int v) {
    Node *n = new_node(v);
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

void print_list(Node *head) {
    Node *cur = head;
    while (cur) {
        printf("%d", cur->val);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

Node* merge_sorted_lists(Node *a, Node *b) {
    Node temp;
    Node *tail = &temp;
    temp.next = NULL;

    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != NULL) ? a : b;
    return temp.next;
}

int main(void) {
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8, 9};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    Node *list1 = NULL;
    Node *list2 = NULL;

    for (int i = 0; i < n1; ++i) list1 = append(list1, a[i]);
    for (int i = 0; i < n2; ++i) list2 = append(list2, b[i]);

    printf("List 1: ");
    print_list(list1);
    printf("List 2: ");
    print_list(list2);

    Node *merged = merge_sorted_lists(list1, list2);
    printf("Merged: ");
    print_list(merged);

    return 0;
}
