// Q14. Write a program in C language to implement a deque using arrays. Implement all operations associated with a deque.

#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if (front == 0)
    {
        printf("Cannot insert at front\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deque[front] = x;
}

void insertRear(int x)
{
    if (rear == MAX - 1)
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    deque[rear] = x;
}

void deleteFront(void)
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void deleteRear(void)
{
    if (rear == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void display(void)
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main(void)
{
    int choice, x;

    while (1)
    {
        printf("\n1. Insert Front\n2. Insert Rear\n");
        printf("3. Delete Front\n4. Delete Rear\n");
        printf("5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            insertFront(x);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &x);
            insertRear(x);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
