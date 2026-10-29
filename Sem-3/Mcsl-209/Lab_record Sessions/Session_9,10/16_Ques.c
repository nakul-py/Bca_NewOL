// Q16. Write a program in C language to reverse the elements of a queue.

#include <stdio.h>
#define MAX 100

int main(void)
{
    int queue[MAX], stack[MAX];
    int n, i, top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter queue elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    /* Push queue elements onto stack */
    for (i = 0; i < n; i++)
        stack[++top] = queue[i];

    /* Pop stack elements back into queue */
    for (i = 0; i < n; i++)
        queue[i] = stack[top--];

    printf("Reversed queue: ");
    for (i = 0; i < n; i++)
        printf("%d ", queue[i]);

    printf("\n");
    return 0;
}
