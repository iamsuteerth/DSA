#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void enq();
void deq ();
void display();
void displayFront();
void displayRear();
void main()
{
    int choice;
    while (1)
    {
        printf("\n1. Enqueue an element\n2. Dequeue an element\n3. Display the queue\n4. Display Front Element\n5. Display Rear Element\n6. Exit\n");
        printf("\nEnter your choice ? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enq();
            break;
        case 2:
            deq ();
            break;
        case 3:
            display();
            break;
        case 4:
            displayFront();
            break;
        case 5:
            displayRear();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}
void enq()
{
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL && rear == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}
void deq ()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void displayFront()
{
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else {
        printf("Front : %d",front->data);
    }
}
void displayRear()
{
    if (rear == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else {
        printf("Rear : %d",rear->data);
    }
}