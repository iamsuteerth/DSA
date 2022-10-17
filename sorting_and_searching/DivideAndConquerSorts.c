#include <stdio.h>
#include <stdbool.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void display(int array[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", array[i]);
    }
    printf(" ]\n");
}
// Merge Sort Section
void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Temp Arrays
    int L[n1], R[n2];
    // Copy Data
    for (i = 0; i < n1; i++)
    {
        L[i] = array[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l; // Merged SubArray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = (l + (r - 1)) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
// Quick Sort Section
void quickSort(int array[], int lb, int ub)
{
    int mid, i, j, key;
    bool flag = true;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        swap(&array[mid], &array[lb]);
        i = lb;
        j = ub + 1;
        key = array[i];
        while (flag)
        {
            while (array[i] < key)
            {
                i++;
            }
            while (array[j] > key)
            {
                j--;
            }
            if (i < j)
            {
                swap(&array[i], &array[j]);
            }
            else
            {
                flag = false;
            }
        }
        swap(&key, &array[j]);
        quickSort(array, lb, j - 1);
        quickSort(array, j + 1, ub);
    }
}
int main()
{
    bool state = true;
    int op, n;
    while (state)
    {

        printf("Enter size of array : ");
        scanf("%d", &n);
        int array[n];
        printf("Enter the array\n");
        for (int i = 0; i < n; i++)
        {
            printf("Element %d : ", i);
            scanf("%d", &array[i]);
        }
        printf("Enter 1 for Merge Sort\n");
        printf("Enter 2 for Quick Sort\n");
        printf("Anything else to exit!\n");
        printf("->");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Unsorted Array \n\n");
            display(array, n);
            printf("Sorted Array \n\n");
            mergeSort(array, 0, n - 1);
            display(array, n);
            break;
        case 2:
            printf("Unsorted Array \n\n");
            display(array, n);
            printf("Sorted Array \n\n");
            quickSort(array, 0, n - 1);
            display(array, n);
            break;
        default:
            state = !state;
            break;
        }
    }
    return 0;
}