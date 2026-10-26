// Question 8-  Write a program in C language to create a linked list and implement deletion of an element using pointers.
//              Write separate programs for doubley linked lists.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

int main(void)
{
    struct Node *head = NULL, *temp, *newNode;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = malloc(sizeof(struct Node));
        if (newNode == NULL)
            return 1;

        printf("Enter value: ");
        scanf("%d", &newNode->data);
        newNode->prev = newNode->next = NULL;

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
            newNode->prev = temp;
        }
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
    }

    printf("List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
