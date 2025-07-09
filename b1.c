#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct {
    Node* head;
}Stack;

Node* createNode(int data) {
    Node* newNode =(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addOne( Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }else {
        Node* temp = *head;
        newNode->next = temp;
        *head = newNode;
    }
}

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->head = NULL;
    return newStack;
}

int main(void) {
    Stack* stack = createStack();
    if ( stack->head == NULL ) {
        printf("Stack is empty\n");
    }else {
        printf("%d\n", stack->head->data);
    }
    return 0;
}
