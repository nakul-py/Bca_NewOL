// Question 36- Write a program in C language to implement Bubble sort using pointers.

#include <stdio.h>

void bubbleSort(int *a, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (*(a + j) > *(a + j + 1))
            {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
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

    bubbleSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    printf("\n");
    return 0;
}
