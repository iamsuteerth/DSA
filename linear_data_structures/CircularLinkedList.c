#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
} * head;
void Binsert(int value)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = value;
    nnode->next = NULL;
    if (head == NULL)
    {
        head = nnode;
        nnode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = nnode;
        nnode->next = head;
        head = nnode;
    }
}
void Einsert(int value)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = value;
    struct Node *temp = head;
    if (head == NULL)
    {
        head = nnode;
        nnode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = nnode;
        nnode->next = head;
    }
}
void Pinsert(int value, int pos)
{
    if (pos == 0)
    {
        Binsert(value);
    }
    else
    {
        struct Node *temp = head;
        int i = -1;
        do
        {
            temp = temp->next;
            i++;
        } while (temp != head);
        printf("Size is %d\n", i);
        if (pos > i)
        {
            printf("Invalid Index!\n");
            return;
        }
        if (i == pos)
        {
            Einsert(value);
        }
        else
        {
            struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
            nnode->data = value;
            temp = head;
            struct Node *prev = NULL;
            int i = 0;
            while (i < pos)
            {
                i++;
                prev = temp;
                temp = temp->next;
            }
            prev->next = nnode;
            nnode->next = temp;
        }
    }
}
void Bdelete(){
    // There are two edge cases involved here
    // First one is when there is no node
    // Second one is when there is only one node
    struct Node* temp = head;
    struct Node* prev = head;
    if(head == NULL){
        printf("Empty List!\n");
    }
    else if(prev->next == head){
        free(prev);
        head = NULL;
        return;
    }
    else {
        while(prev->next != head){
            prev = prev->next;
        }
        head = head->next;
        prev->next = head;
        free(temp);
    }
}
void Edelete(){
    struct Node* temp = head;
    struct Node* prev = head;
    if(head == NULL){
        printf("Empty List!\n");
    }
    else if(prev->next == head){
        free(prev);
        head = NULL;
        return;
    }
    else {
        while(temp->next != head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}
void Pdelete(int pos){
    if (pos == 0)
    {
        Bdelete();
    }
    else
    {
        struct Node *temp = head;
        int i = -1;
        do
        {
            temp = temp->next;
            i++;
        } while (temp != head);
        printf("Size is %d\n", i);
        if (pos > i)
        {
            printf("Invalid Index!\n");
            return;
        }
        if (i == pos)
        {
            Edelete();
        }
        else
        {
            temp = head;
            struct Node *prev = NULL;
            int i = 0;
            while (i < pos)
            {
                i++;
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}
void print()
{
    if (head == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    struct Node *temp = head;
    // Since for the first time, head is temp, we use do while loop
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void search(int value)
{
    if (head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        struct Node *temp = head;
        int res = -1, index = 0;
        do
        {

            if (temp->data == value)
            {
                printf("Match found at index : %d\n", index);
                res = 0;
            }
            temp = temp->next;
            index++;
        } while (temp != head);
        if (res == -1)
        {
            printf("No match found!\n");
        }
    }
}
int main()
{
    bool state = true;
    int op1, op2, value, pos;
    while (state)
    {
        printf("Enter 1 for insertion!\n");
        printf("Enter 2 for deletion!\n");
        printf("Enter 3 for search!\n");
        printf("Enter 4 for display!\n");
        printf("Enter anything else to exit!\n");
        printf("->");
        scanf("%d", &op1);
        switch (op1)
        {
        case 1:
            printf("Insertion menu!\n");
            printf("Enter 1 for Beginning insertion!\n");
            printf("Enter 2 for End insertion!\n");
            printf("Enter 3 for Position insertion!\n");
            printf("Enter anything else to exit!\n");
            printf("->");
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                printf("Enter value : ");
                scanf("%d", &value);
                Binsert(value);
                break;
            case 2:
                printf("Enter value : ");
                scanf("%d", &value);
                Einsert(value);
                break;
            case 3:
                printf("Enter value : ");
                scanf("%d", &value);
                printf("Enter position : ");
                scanf("%d", &pos);
                Pinsert(value, pos);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("Deletion menu!\n");
            printf("Enter 1 for Beginning deletion!\n");
            printf("Enter 2 for End deletion!\n");
            printf("Enter 3 for Position deletion!\n");
            printf("Enter anything else to exit!\n");
            printf("->");
            scanf("%d",&op2);
            switch (op2)
            {
            case 1:
                Bdelete();
                break;
            case 2:
                Edelete();
                break;
            case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                Pdelete(pos);
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("Enter value : ");
            scanf("%d", &value);
            search(value);
            break;
        case 4:
            print();
            break;
        default:
            state = false;
            break;
        }
    }
    return 0;
}