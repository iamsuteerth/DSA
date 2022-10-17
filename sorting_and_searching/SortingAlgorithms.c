#include <stdio.h>
#include <stdbool.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void display(int array[], int n){
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    printf("]\n");
}
void insertion_sort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void bubble_sort(int array[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j + 1], &array[j]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
void selection_sort(int array[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}
void counting_sort(int array[], int n)
{
    int max=0;
    int output[n];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    int count[max+1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[array[i]]++;
    }
    for (int i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

int main()
{
    bool state = true;
    int op,n;
    while (state)
    {   
        
        printf("Enter size of array : ");
        scanf("%d", &n);
        int array[n];
        printf("Enter the array\n");
        for (int i = 0; i < n; i++)
        {
            printf("Element %d : ",i);
            scanf("%d",(array+i));
        }
        
        display(array,n);
        printf("Enter 1 for Bubble Sort\n");
        printf("Enter 2 for Insertion Sort\n");
        printf("Enter 3 for Selection Sort\n");
        printf("Enter 4 for Counting Sort\n");
        printf("->");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Unsorted Array \n\n");
            display(array,n);
            printf("Sorted Array \n\n");
            bubble_sort(array, n);
            display(array,n);
            break;
        case 2:
            printf("Unsorted Array \n\n");
            display(array,n);
            printf("Sorted Array \n\n");
            insertion_sort(array, n);
            display(array,n);
            break;
        case 3:
            printf("Unsorted Array \n\n");
            display(array,n);
            printf("Sorted Array \n\n");
            selection_sort(array, n);
            display(array,n);
            break;
        case 4:
            printf("Unsorted Array \n\n");
            display(array,n);
            printf("Sorted Array \n\n");
            counting_sort(array, n);
            display(array,n);
            break;
        default:
            state = !state;
            break;
        }
    }
    
    return 0;
}