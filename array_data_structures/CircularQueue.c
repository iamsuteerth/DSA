#include <stdio.h>
#include <stdbool.h>
struct q
{
    int front;
    int rear;
    int array[6];
} queue;
void enq(struct q *ptr, int val)
{   
    if((ptr->front == 0 && ptr->rear == 5) || (ptr->front == ptr->rear +1)){
        printf("Overflow\n");
        return;
    }
    if(ptr->front == -1 && ptr->rear == -1){
        ptr->front = 0;
        ptr->rear = 0;
    }
    else if (ptr->rear == 5)
    {
        ptr->rear = 0;
    }
    else
    {
        ptr->rear = ptr->rear + 1;
    }
    ptr->array[ptr->rear] = val;
}
int deq(struct q *ptr)
{
    if (ptr->front == -1)
    {
        return -1;
    }
    
    int temp = ptr->array[ptr->front];
    if (ptr->front == ptr->rear)
    {
        ptr->rear = -1;
        ptr->front = -1;
    }
    else if (ptr->front == 5){
        ptr->front = 0;
    }
    else
    {
        ptr->front = ptr->front + 1;
    }
    return temp;
}
void display(struct q *ptr)
{
    printf("Front %d, Rear %d\n", ptr->front, ptr->rear);
    for (int i = 0; i < 6; i++)
    {
        printf("%d %d\n", i, ptr->array[i]);
    }
}
void display_front(struct q *ptr)
{
    if(ptr->front == -1){
        printf("Empty List\n");
    }
    else{
        printf("Front = %d\n",ptr->front);
    }
}
void display_rear(struct q *ptr)
{
    if(ptr->front == -1){
        printf("Empty List\n");
    }
    else{
        printf("Rear = %d\n",ptr->rear);
    }
}
int main()
{
    int temp;
    struct q *ptr = &queue;
    ptr->front = -1;
    ptr->rear = -1;
    int op, value;
    bool state = true;
    while (state)
    {
        printf("Enter 1 for enq\n");
        printf("Enter 2 for deq\n");
        printf("Enter 3 for display\n");
        printf("Enter 4 for displaying front\n");
        printf("Enter 5 for displaying rear\n");
        printf("-> ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &value);
            enq(ptr, value);
            break;
        case 2:
            temp = deq(ptr);
            if (temp == -1){
                printf("Underflow\n");
                break;
            }
            printf("Dequeued %d\n",temp);
            break;
        case 3:
            display(ptr);
            break;
        case 4:
            display_front(ptr);
            break;
        case 5:
            display_rear(ptr);
            break;
        default:
            state = !state;
            break;
        }
    }
    return 0;
}
