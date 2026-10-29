// Q18. Write a program in C language to implement a stack using two queues.

#include <stdio.h>
#define MAX 100

struct Queue
{
    int arr[MAX];
    int front, rear, count;
};

struct Queue q1 = {{0}, 0, 0, 0};
struct Queue q2 = {{0}, 0, 0, 0};

void enqueue(struct Queue *q, int x)
{
    if (q->count == MAX)
        return;

    q->arr[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
}

int dequeue(struct Queue *q)
{
    int x = q->arr[q->front];

    q->front = (q->front + 1) % MAX;
    q->count--;

    return x;
}

void push(int x)
{
    struct Queue temp;

    if (q1.count == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }

    enqueue(&q2, x);

    while (q1.count > 0)
        enqueue(&q2, dequeue(&q1));

    temp = q1;
    q1 = q2;
    q2 = temp;

    printf("Pushed: %d\n", x);
}

void pop(void)
{
    if (q1.count == 0)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Popped: %d\n", dequeue(&q1));
}

void display(void)
{
    int i, index;

    if (q1.count == 0)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");

    for (i = 0; i < q1.count; i++)
    {
        index = (q1.front + i) % MAX;
        printf("%d ", q1.arr[index]);
    }

    printf("\n");
}

int main(void)
{
    int choice, x;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
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
