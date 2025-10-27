#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node *createNode(int data) {
	Node *new  = (Node *)malloc(sizeof(Node));
	new->data  = data;
	new->left  = NULL;
	new->right = NULL;

	return new;
}

void inorder(Node *node) {
	if (!node) return;

	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

void preorder(Node *node) {
	if (!node) return;

	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
}

void postorder(Node *node) {
	if (!node) return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);
}

void insert(Node *node, int data) {
	if (!node) return createNode(data);

	if (node->data > data) {
		node->left = insert(node->left, data);
	} else {
		node->right = insert(node->right, data);
	}

	return node;
}

Node *insert(Node *node, int data) {
    if (!node) return createNode(data);

    if (node->data > data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    return node;
}




int main() {
	Node *root = createNode(1);
	for (int i = 1; i < 10; i++) insert(root, i);
	inorder(root);
	printf("\n");
}
