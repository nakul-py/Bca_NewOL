// Question 31- Write a program in C language to implement linear search using pointers.

#include <stdio.h>

int main(void)
{
    int a[100], n, key, i;
    int *p, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    p = a;

    for (i = 0; i < n; i++)
    {
        if (*(p + i) == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
