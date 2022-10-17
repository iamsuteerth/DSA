#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node* top = NULL;

void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; // assign value to the node
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
    printf("Node is Inserted\n\n");
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        struct Node *temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peak() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("Top most element is %d\n", top->data);
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Peak\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display(); 
            break;
        case 4:
            peak();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}