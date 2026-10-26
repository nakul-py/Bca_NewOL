// Q10. Write a program in C language to accept a singly linked list of integers, sort its elements in ascending order, and
//      insert a given integer at the appropriate position.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head = NULL, *temp, *newNode;
    int n, i, t, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = malloc(sizeof(struct Node));
        if (newNode == NULL)
            return 1;

        printf("Enter value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    /* Sort the list by swapping data */
    for (struct Node *p = head; p != NULL; p = p->next)
    {
        for (struct Node *q = p->next; q != NULL; q = q->next)
        {
            if (p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }

    printf("Enter integer to insert: ");
    scanf("%d", &value);

    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
        return 1;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value <= head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL &&
               temp->next->data < value)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Sorted list after insertion: ");
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    /* Free allocated memory */
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
