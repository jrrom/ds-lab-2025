#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Node* left;
    int   data;
    Node* right;
};

Node* root = NULL;

Node* newNode(int data) {
    Node* new  = (Node*)malloc(sizeof(Node));
    new->left  = NULL;
    new->right = NULL;
    new->data  = data;
    return new;
}

/* Insertion */
Node* insert(Node* node, int data) {
    if (!node) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

/* Search with printed path */
Node* search(Node* node, int key) {
    if (!node) {
        printf("%d not found\n", key);
        return NULL;
    }
    printf("%d -> ", node->data);
    if (key == node->data) {
        printf("Found %d\n", key);
        return node;
    }
    if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

/* Find minimum value node in right subtree */
Node* minNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

/* Deletion */
Node* delete(Node* node, int key) {
    if (!node) return NULL;

    if (key < node->data)
        node->left = delete(node->left, key);
    else if (key > node->data)
        node->right = delete(node->right, key);
    else {
        // Node found
        if (!node->left && !node->right) {
            free(node);
            return NULL;
        } else if (!node->left) {
            Node* temp = node->right;
            free(node);
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            free(node);
            return temp;
        } else {
            Node* temp = minNode(node->right);
            node->data = temp->data;
            node->right = delete(node->right, temp->data);
        }
    }
    return node;
}

/* In-order traversal */
void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    int set[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 55, 65, 75, 85};
    int n = sizeof(set)/sizeof(set[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, set[i]);

    inorder(root);
    printf("\n");

    search(root, 60);

    search(root, 90);

    printf("Deleting 70\n");
    root = delete(root, 70);

    printf("In-order:\n");
    inorder(root);
    printf("\n");

    return 0;
}
