// Question 35- Write a program in C language to implement 2-way Merge sort using pointers.

#include <stdio.h>

void merge(int *a, int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1;
    int k = 0, x;

    while (i <= mid && j <= high)
    {
        if (*(a + i) < *(a + j))
            temp[k++] = *(a + i++);
        else
            temp[k++] = *(a + j++);
    }

    while (i <= mid)
        temp[k++] = *(a + i++);

    while (j <= high)
        temp[k++] = *(a + j++);

    for (i = low, x = 0; i <= high; i++, x++)
        *(a + i) = temp[x];
}

void mergeSort(int *a, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main(void)
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    printf("\n");
    return 0;
}
