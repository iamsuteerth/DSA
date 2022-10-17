#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    int data;
    struct Node *next;
} * head;

// Insert Ops
void Binsert(int value)
{
    // Purely performing Binserts will create a stack while also using Bdelete
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = value;
    nnode->next = NULL;
    if (head == NULL)
    {
        head = nnode;
    }
    else
    {
        nnode->next = head;
        head = nnode;
    }
}
void Einsert(int value)
{

    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = value;
    nnode->next = NULL;
    if (head == NULL)
    {
        head = nnode;
    }
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nnode;
    }
}
void Pinsert(int value, int n)
{
    if (n == 0)
    {
        Binsert(value);
    }
    else
    {
        struct Node *temp = head;
        int i = 0;
        do
        {
            temp = temp->next;
            i++;
        } while (temp != NULL);
        if (n > i)
        {
            printf("Invalid Index!\n");
            return;
        }
        if (i == n)
        {
            Einsert(value);
        }
        else
        {
            struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
            nnode->data = value;
            nnode->next = NULL;
            struct Node *temp;
            struct Node *prev;
            temp = head;
            int ctr = 0;
            while (temp->next != NULL && ctr != n)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            if (ctr == n)
            {
                prev->next = nnode;
                nnode->next = temp;
            }
        }
    }
}
// Deletion Ops
void Bdelete()
{

    if (head == NULL)
    {
        printf("Empty list!\n");
    }
    else
    {
        head = head->next;
    }
}
void Edelete()
{
    if (head == NULL)
    {
        printf("Empty list!\n");
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void Pdelete(int pos)
{
    if (pos == 0)
    {
        Bdelete();
    }
    else
    {
        struct Node *temp = head;
        int i = 0;
        do
        {
            temp = temp->next;
            i++;
        } while (temp != NULL);
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
            struct Node *temp = head;
            struct Node *prev = head;
            int ctr = 0; // Actual index
            if (pos < 0 || head == NULL)
            {
                printf("Invalid index or list empty!\n");
            }
            else
            {
                while (temp != NULL && ctr != pos)
                {
                    prev = temp;
                    temp = temp->next;
                    ctr++;
                }
                if (ctr == pos)
                {
                    prev->next = temp->next;
                    free(temp);
                }
            }
        }
    }
}
void Search(int value)
{
    int dp = -1;
    if (head == NULL)
    {
        printf("Empty List!");
    }
    else
    {
        struct Node *temp = head;
        int pos = 0;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                printf("Element Found! at position %d\n", pos);
                dp = 1;
                break;
            }
            temp = temp->next;
            pos++;
        }
        if (dp == -1)
        {
            printf("No match found!\n");
        }
    }
}
void Display(void)
{
    if (head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        struct Node *temp = head;
        int i = 0;
        printf("\n");
        while (temp != NULL)
        {
            printf("Element %d %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
        printf("\n");
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
            scanf("%d", &op2);
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
                scanf("%d", &pos);
                Pdelete(pos);
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("Enter value : ");
            scanf("%d", &value);
            Search(value);
            break;
        case 4:
            Display();
            break;
        default:
            state = false;
            break;
        }
    }
    return 0;
}
