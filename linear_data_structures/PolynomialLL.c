#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    float coef;
    int expo;
    struct node *link;
};

struct node *create(struct node *);
struct node *insert_s(struct node *, float, int);
struct node *insert(struct node *, float, int);
void display(struct node *ptr);
void add(struct node *, struct node *);
void multiply(struct node *, struct node *);
int main()

{
    struct node *polynomial1 = NULL;
    struct node *polynomial2 = NULL;
    int op;
    bool state = true;
    while (state)
    {
        printf("Enter polynomial One\n");
        polynomial1 = create(polynomial1);
        display(polynomial1);

        printf("Enter polynomial Two\n");
        polynomial2 = create(polynomial2);
        display(polynomial2);

        printf("1 for Addition\n2 for Multiplication\nAnything else to exit\n->");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add(polynomial1, polynomial2);
            break;
        case 2:
            multiply(polynomial1, polynomial2);
            break;
        default:
            break;
        }
    }
}

struct node *create(struct node *start)
{
    int i, n, ex;
    float co;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter coeficient for term %d : ", i);
        scanf("%f", &co);
        printf("Enter exponent for term %d : ", i);
        scanf("%d", &ex);
        start = insert_s(start, co, ex);
    }
    return start;
}
struct node *insert_s(struct node *start, float co, int ex)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coef = co;
    temp->expo = ex;
    if (start == NULL || ex > start->expo)
    {
        temp->link = start;
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL && ptr->link->expo >= ex)
            ptr = ptr->link;
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return start;
}

struct node *insert(struct node *start, float co, int ex)
{
    struct node *ptr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coef = co;
    temp->expo = ex;
    if (start == NULL)
    {
        temp->link = start;
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return start;
}

void display(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Zero polynomial\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("(%.1fx^%d)", ptr->coef, ptr->expo);
        ptr = ptr->link;
        if (ptr != NULL)
            printf(" + ");
        else
            printf("\n");
    }
}
void add(struct node *p1, struct node *p2)
{
    struct node *start3;
    start3 = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            start3 = insert(start3, p1->coef, p1->expo);
            p1 = p1->link;
        }
        else if (p2->expo > p1->expo)
        {
            start3 = insert(start3, p2->coef, p2->expo);
            p2 = p2->link;
        }
        else if (p1->expo == p2->expo)
        {
            start3 = insert(start3, p1->coef + p2->coef, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while (p1 != NULL)
    {
        start3 = insert(start3, p1->coef, p1->expo);
        p1 = p1->link;
    }
    while (p2 != NULL)
    {
        start3 = insert(start3, p2->coef, p2->expo);
        p2 = p2->link;
    }
    struct node *ptr = start3;
    struct node *temp = NULL;
    while (ptr->link != NULL)
    {
        if (ptr->expo == ptr->link->expo)
        {
            ptr->coef = ptr->coef + ptr->link->coef;
            temp = ptr->link;
            ptr->link = ptr->link->link;
            free(temp);
        }
        else
        {
            ptr = ptr->link;
        }
    }
    printf("Added polynomial is : ");
    display(start3);
}

void multiply(struct node *p1, struct node *p2)
{
    struct node *start3 = NULL;
    struct node *p2_beg = p2;
    if (p1 == NULL || p2 == NULL)
    {
        printf("Multiplied polynomial is zero polynomial\n");
        return;
    }
    while (p1 != NULL)
    {
        p2 = p2_beg;
        while (p2 != NULL)
        {
            start3 = insert_s(start3, p1->coef * p2->coef, p1->expo + p2->expo);
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    struct node *ptr = start3;
    struct node *temp = NULL;
    while (ptr->link != NULL)
    {
        if (ptr->expo == ptr->link->expo)
        {
            ptr->coef = ptr->coef + ptr->link->coef;
            temp = ptr->link;
            ptr->link = ptr->link->link;
            free(temp);
        }
        else
        {
            ptr = ptr->link;
        }
    }
    printf("Multiplied polynomial is : ");
    display(start3);
}