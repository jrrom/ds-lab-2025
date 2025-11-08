#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

// Create

Node* createNode(char data) {
    Node* new  = (Node*)malloc(sizeof(Node));
    new->data  = data;
    new->left  = NULL;
    new->right = NULL;

    return new;
}

Node* create(Node* node) {
    char value;
    printf("Enter value of new node : ");
    scanf("%c", &value);
    getchar();
    
    if (value == 'X') {
        return NULL;
    }
    
    Node* new = createNode(value);

    printf("Enter left of node %c \n", new->data);
    new->left = create(new->left);

    printf("Enter right of node %c : \n", new->data);
    new->right = create(new->right);

    return new;
}

// Display

void inorder(Node* node) {
    if (!node) return;

    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}

// Leaves

int countLeaves(Node* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int height(Node* node) {
    if (!node) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return (lh > rh ? lh : rh) + 1;
}

int find_parent(Node* node, char element) {
    if (!node) return -1;
    if ((node->left && node->left->data == element) ||
        (node->right && node->right->data == element))
        return node->data;

    int leftResult = find_parent(node->left, element);
    if (leftResult != -1) return leftResult;

    return find_parent(node->right, element);
}

int printAncestors(Node* node, char element) {
    if (!node) return 0;
    if (node->data == element) return 1;

    if (printAncestors(node->left, element) || printAncestors(node->right, element)) {
        printf("%d ", node->data);
        return 1;
    }

    return 0;
}

int main() {
    root = create(root);
    inorder(root);
    printf("\n");

    printf("Number of leaves : %d\n", countLeaves(root));
    printf("Height : %d\n", height(root));
}
