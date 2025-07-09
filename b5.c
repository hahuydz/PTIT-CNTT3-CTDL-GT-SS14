#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node* head;
}Stack;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* node = createNode(data);
    node->next = stack->head;
    stack->head = node;
}

int top(Stack* stack) {
    Node* node = stack->head;
    if ( node == NULL ) {
        printf("Stack is empty\n");
        return -1;
    }
    return node->data;
}

void show(Stack* stack) {
    Node* node = stack->head;
    if (node == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while ( node != NULL ) {
        printf("%d\t", node->data);
        node = node->next;
    }
}

int main(void) {
    Stack* stack = createStack();
    for ( int i = 1; i <= 5; i++) {
        push(stack, i);
    }
    show(stack);
    printf("\ntop: %d\n", top(stack));
    return 0;
}
