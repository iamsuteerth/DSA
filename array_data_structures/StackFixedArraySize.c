#include <stdio.h>
#include <stdbool.h>
struct stk{
    int stack[10];
    int top;
};
void push(struct stk*, int);
void pop(struct stk*);
void peak(struct stk*);
void display(struct stk*);
int main()
{
    bool state = true;
    int operation;
    int input;
    struct stk s;
    struct stk* ptr = &s;
    ptr->top = -1;
    while (state)
    {
        printf("\n----STACK OPERATIONS----\n");
        printf("1 : Push\n");
        printf("2 : Pop\n");
        printf("3 : Peak\n");
        printf("4 : Display\n");
        printf("Enter operation code : ");
        scanf("%d",&operation);
        printf("------------------------\n");
        switch (operation)
        {
        case 1:
            printf("Enter value to push : ");
            scanf("%d",&input);
            push(ptr, input);
            break;
        case 2:
            pop(ptr);
            break;
        case 3:
            peak(ptr);
            break;
        case 4:
            display(ptr);
            break;
        default:
            state = false;
            break;
        }
    }
    return 0;
}
void push(struct stk* ptr, int value){
    if(ptr->top == -1){
        ptr->stack[9] = value;
        ptr->top = 9;
    }
    else if (ptr->top == 0){
        printf("Stack Overflow!\n");
    }
    else{
        ptr->stack[ptr->top - 1] = value;
        ptr->top--;
    }
}
void pop(struct stk* ptr){
    if(ptr->top == -1){
        printf("Stack EMPTY!\n");
    }
    else {
        printf("Element popped %d\n",ptr->stack[ptr->top]);
        if(ptr->top == 9){
            ptr->top = -1;
        }
        else{
            ptr->top++;
        }
    }
}
void peak(struct stk* ptr){
    if(ptr->top == -1){
        printf("Stack EMPTY!\n");
    }
    else{
        printf("Top element %d\n",ptr->stack[ptr->top]);
    }
}
void display(struct stk* ptr){
    if(ptr->top==-1){
        printf("Stack EMPTY!\n");
    }
    else {
        for (int i = (ptr->top); i < 10 ; i++)
        {
            printf("%d\n",ptr->stack[i]);
        }
    } 
}