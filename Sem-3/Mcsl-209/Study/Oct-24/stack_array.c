/* Program of stack using array */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top = -1;
int stack_arr[MAX];

int push();
int pop();
int display();

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Wrong choice\n");
        }
    }

    return 0;
}

int push()
{
    int pushed_item;

    if (top == (MAX - 1))
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the item to be pushed in stack : ");
        scanf("%d", &pushed_item);
        top = top + 1;
        stack_arr[top] = pushed_item;
    }

    return 0;
}

int pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("Popped item is : %d\n", stack_arr[top]);
        top = top - 1;
    }

    return 0;
}

int display()
{
    int i;

    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are :\n");

        for (i = top; i >= 0; i--)
            printf("%d\n", stack_arr[i]);
    }

    return 0;
}