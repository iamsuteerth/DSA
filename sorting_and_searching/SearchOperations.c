#include<stdio.h>
#include<stdbool.h>
int linear_search(int value, int array[], int n){
    for (int i = 0; i < n; i++)
    {
        if (array[i]==value)
        {
            return i;
        }
    }
    return -1;
}
int bin_search(int value, int array[], int n){
    int low = 0;
    int high = n;
    int mid = (high+low)/2;
    while(low<=high){
        int mid = (high+low)/2;
        if(array[mid] == value){
            return mid;
        }
        else if (array[mid]>value){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
void display(int array[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = %d\n",i,array[i]);
    }
}
int main(){
    int sorted_array[10] = {1,4,7,10,12,17,20,23,24,30};
    int array[10] = {7,10,1,12,4,17,23,30,24,20};
    bool state = true;
    int val,t,op;
    while(state){
        display(array, 10);
        printf("Enter value to search : ");
        scanf("%d",&val);
        printf("Enter 1 for Linear Search\nEnter 2 for Binary Search\nAnything Else to Exit : ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            t = linear_search(val, array, 10);
            if(t==-1){
                printf("Element not found!\n\n");
            }
            else {
                printf("Element found at %d\n\n",t);
            }
            break;
        case 2:
            printf("Array must be sorted for performing Bin Search!\nSorted Array\n");
            display(sorted_array,10);
            t = bin_search(val, sorted_array, 10);
            if(t==-1){
                printf("Element not found!\n\n");
            }
            else {
                printf("Element found\n\n");
            }
            break;
        default:
            state = !state;
            break;
        }
    }
    return 0;
}