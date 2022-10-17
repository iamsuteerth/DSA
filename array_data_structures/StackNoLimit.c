#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void push(int *, int, int);
void pop(int *, int *);
void peak(int *, int);
void display(int *, int);
int main()
{
    int *stack = NULL;
    stack = (int *)malloc(0*sizeof(int));
    int size = 0;
    bool state = true;
    int input;
    while (state)
    {
        printf("STACK OPERATIONS\n");
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for peak\n");
        printf("4 for display\n");
        printf("Anything Else to EXIT\n");
        printf("Enter command : ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("SIZE %d\n",size);
            size++;
            printf("\nEnter value to push into stack : ");
            scanf("%d", &input);
            push(stack, size, input);
            printf("Pushed %d into stack!\n", input);
            break;
        case 2:
            printf("SIZE %d\n",size);
            size--;
            pop(stack, &size);
            break;
        case 3:
            peak(stack, size);
            break;
        case 4:
            display(stack, size);
            break;
        default:
            state = false;
            break;
        }
    }
    return 0;
}
void display(int *array, int size)
{
    printf("SIZE %d \n",size);
    if (size <= 0)
    {
        printf("\nEmpty STACK!!\n");
    }
    else
    {
        printf("\nDisplaying STACK!!\n");
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%d\n", array[i]);
        }
    }
}
void push(int *array, int size, int input)
{   
    printf("SIZE %d INPUT %d\n",size,input);
    array = realloc(array, sizeof(int) * size);
    printf("SIZE %d INPUT %d\n",size-1,input);
    array[size-1] = input;
    printf("%d\n",array[size-1]);
}
void pop(int *array, int *size)
{
    if (*(size) < 0)
    {   
        printf("SIZE %d increased\n",*(size));
        printf("\nSTACK EMPTY!\n");
        *(size) = *(size) + 1;
    }
    if(*(size)>=0)
    {
        printf("SIZE %d \n",*(size));
        printf("Popped %d from stack!\n", array[*(size)]);
        array = realloc(array, sizeof(int) * (*(size)));
    }
}
void peak(int *array, int size)
{
    if (size > 0)
    {
        printf("\nElement %d\n", array[size - 1]);
    }
    else
    {
        printf("\nEmpty STACK!\n");
    }
}