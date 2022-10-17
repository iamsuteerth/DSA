#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} * head;
void Binsert(int value)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = value;
    nnode->left = NULL;
    nnode->right = NULL;
    if (head == NULL)
    {
        head = nnode;
    }
    else
    {
        struct Node *first = head;
        nnode->right = first;
        first->left = nnode;
        head = nnode;
    }
}
void Einsert(int value)
{
    struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
    nnode->data = value;
    nnode->right = NULL;
    nnode->left = NULL;
    if (head == NULL)
    {
        head = nnode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = nnode;
        nnode->left = temp;
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
            temp = temp->right;
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
            int ctr = 0;
            struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
            nnode->data = value;
            nnode->right = NULL;
            nnode->left = NULL;
            struct Node *temp = head;
            struct Node *prev = NULL;
            while (temp->right != NULL && ctr != n)
            {
                prev = temp;
                temp = temp->right;
                ctr++;
            }
            if (ctr == n)
            {
                prev->right = nnode;
                temp->left = nnode;
                nnode->left = prev;
                nnode->right = temp;
            }
        }
    }
}
void Fwd_Display()
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
            temp = temp->right;
            i++;
        }
        printf("\n");
    }
}
void Bwd_Display()
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
        while (temp->right != NULL)
        {
            temp = temp->right;
            i++;
        }
        while (temp != NULL)
        {
            printf("Element %d %d\n", i, temp->data);
            temp = temp->left;
            i--;
        }
        printf("\n");
    }
}
void Bdelete()
{
    if (head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        struct Node *temp = head;
        head = temp->right;
        temp->left = NULL;
        temp->right = NULL;
        free(temp);
    }
}
void Edelete()
{
    if (head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp->right != NULL)
        {
            prev = temp;
            temp = temp->right;
        }
        prev->right = NULL;
        temp->left = NULL;
        temp->right = NULL;
        free(temp);
    }
}
void Pdelete(int n)
{
    if (n == 0)
    {
        Bdelete();
    }
    else
    {
        struct Node *temp = head;
        int i = 0;
        do
        {
            temp = temp->right;
            i++;
        } while (temp != NULL);
        if (n > i)
        {
            printf("Invalid Index!\n");
            return;
        }
        if (i == n)
        {
            Edelete();
        }
        else
        {
            int ctr = 0;
            struct Node *temp = head;
            struct Node *prev = head;
            while (temp->right != NULL && ctr != n)
            {
                prev = temp;
                temp = temp->right;
                ctr++;
            }
            prev->right = temp->right;
            temp->right->left = prev;
            free(temp);
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
            temp = temp->right;
            pos++;
        }
        if (dp == -1)
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
            printf("1 for forward traversal\n2For backward traversal\n->");
            scanf("%d", &op2);
            switch (op2)
            {
            case 1:
                Fwd_Display();
                break;
            case 2:
                Bwd_Display();
                break;
            default:
                break;
            }
            break;
        default:
            state = false;
            break;
        }
    }
    return 0;
}