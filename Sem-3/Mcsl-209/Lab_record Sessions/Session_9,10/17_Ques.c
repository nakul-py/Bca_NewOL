// Q17. Write a program in C language to implement a queue using two stacks.

#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int x)
{
    if (top1 == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    s1[++top1] = x;
    printf("Inserted: %d\n", x);
}

void dequeue(void)
{
    if (top2 == -1)
    {
        while (top1 != -1)
            s2[++top2] = s1[top1--];
    }

    if (top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted: %d\n", s2[top2--]);
}

void display(void)
{
    int i;

    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    /* s2 is stored in reverse order */
    for (i = top2; i >= 0; i--)
        printf("%d ", s2[i]);

    /* s1 contains the newer elements */
    for (i = 0; i <= top1; i++)
        printf("%d ", s1[i]);

    printf("\n");
}

int main(void)
{
    int choice, x;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
