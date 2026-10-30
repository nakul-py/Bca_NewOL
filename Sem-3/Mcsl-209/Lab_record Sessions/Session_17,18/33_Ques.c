// Question 33- Write a program in C language to implement Quick sort using pointers.

#include <stdio.h>

void quickSort(int *a, int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = *(a + high);
        i = low - 1;

        for (j = low; j < high; j++)
        {
            if (*(a + j) < pivot)
            {
                i++;

                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }

        temp = *(a + i + 1);
        *(a + i + 1) = *(a + high);
        *(a + high) = temp;

        int pos = i + 1;

        quickSort(a, low, pos - 1);
        quickSort(a, pos + 1, high);
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

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    printf("\n");
    return 0;
}
