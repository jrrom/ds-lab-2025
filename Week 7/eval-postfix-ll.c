// Doesn't work, work on it later

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node node;

node* create(int first) {
	node* head = (node*)malloc(sizeof(node));
	head->data = first;
	head->next = NULL;

	return head;
}

void delete(node** head) {
	node* next;
	for (node* current = *head; current; current = next) {
		next = current->next;
		free(current);
	}
	*head = NULL;
}

void push(node* head, int data) {


	node* next = (node*)malloc(sizeof(node));
	next->data = data;
	next->next = NULL;

	if (head->next == NULL) {
		head->next = next;
		return;
	}

	node* current;
	for (current = head; current->next; current = current->next);
	current->next = next;
}

int pop(node** head) {
	if (*head == NULL) {
		printf("Error: Linked List Stack Underflow\n");
		exit(1);
	}

	if ((*head)->next == NULL) {
		int value = (*head)->data;
		free(*head);
		*head = NULL;
		return value;
	}

	node* current;
	for (current = *head; current->next->next; current = current->next);

	node* popped_node = current->next;
	int value = popped_node->data;
	current->next = NULL;
	free(popped_node);

	return value;
}

void display(node* head) {
	for (node* current = head; current; current = current->next) {
		printf("[%d]->", current->data);
	}
	printf("NULL\n");
}

int is_num(char c) {
	return ('0' <= c && c <= '9');
}

int eval(char input[]) {
	node* eval_stack = create((int) input[0]);
	for (int i = 1; input[i] != '\0'; i++) {
		char cur = input[i];
		if (is_num(cur)) {
			push(eval_stack, cur - (int)'0');
			continue;
		}

		int first  = pop(&eval_stack);
		int second = pop(&eval_stack);
		switch (cur) {
			case '+': push(eval_stack, second + first); break;
			case '-': push(eval_stack, second - first); break;
			case '/': push(eval_stack, second / first); break;
			case '%': push(eval_stack, second % first); break;
			case '^': push(eval_stack, second ^ first); break;
			case '*': push(eval_stack, second * first); break;
		}
	}
	display(eval_stack);
	delete(&eval_stack);
}

int main() {
	char postfix[MAX];
	scanf("%s", postfix);
	eval(postfix);
}
