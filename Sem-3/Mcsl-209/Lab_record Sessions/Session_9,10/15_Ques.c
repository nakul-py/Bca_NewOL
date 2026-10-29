// Q15. Write a program in C language to implement a deque using pointers. Implement all operations associated with a deque.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *front = NULL, *rear = NULL;

void insertFront(int x)
{
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL)
        return;

    n->data = x;
    n->prev = NULL;
    n->next = front;

    if (front == NULL)
        front = rear = n;
    else
        front->prev = n;

    front = n;
}

void insertRear(int x)
{
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL)
        return;

    n->data = x;
    n->next = NULL;
    n->prev = rear;

    if (rear == NULL)
        front = rear = n;
    else
        rear->next = n;

    rear = n;
}

void deleteFront(void)
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear(void)
{
    struct Node *temp;

    if (rear == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    temp = rear;
    printf("Deleted: %d\n", temp->data);
    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

void display(void)
{
    struct Node *temp = front;

    if (temp == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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
            while (front != NULL)
                deleteFront();
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
