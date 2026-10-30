// Question 32- Write a program in C language to implement binary search using pointers.

#include <stdio.h>

int main(void)
{
    int a[100], n, key;
    int low, high, mid, i;
    int *p, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    p = a;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (*(p + mid) == key)
        {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (*(p + mid) < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
