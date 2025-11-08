#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->left = new->right = NULL;
}

Node* insert(Node* node, int data) {
    if (node == NULL)
        return createNode(data);


    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    return node;
}

int search(Node* node, int data) {
    if (!node) return 0;
    if (node->data == data) return 1;

    return node->data > data
           ? search(node->left, data)
           : search(node->right, data);
}

int findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;

    return root->data;
}

Node* deleteNode(Node* node, int key) {
    if (!node) return NULL;

    if (node->data > key) {
        node->left = deleteNode(node->left, key);
    } else if (node->data < key) {
        node->right = deleteNode(node->right, key);
    } else {
        // NO kids
        if (!node->left && !node->right) {
            free(node);
            return NULL;
        }

        // 1 kid
        if (!node->left) {
            Node* tmp = node->right;
            free(node);
            return tmp;
        }

        if (!node->right) {
            Node* tmp = node->left;
            free(node);
            return tmp;
        }

        // 2 kids
        int tmp = findMin(node->right);
        node->data = tmp;
        node->right = deleteNode(node->right, tmp);
    }

    return node;
}

void inorder(Node* node) {
    if (node == NULL) return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}


int main() {
    head = insert(head, 5);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 6);
//    head = deleteNode(head, 5);

    inorder(head);
    printf("\n");
}
