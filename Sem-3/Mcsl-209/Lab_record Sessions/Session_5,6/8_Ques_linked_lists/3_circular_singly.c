// Question 8-  Write a program in C language to create a linked list and implement deletion of an element using pointers.
//              Write separate programs for circular singly linked lists.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head = NULL, *tail = NULL, *temp, *newNode;
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

        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head != NULL)
    {
        temp = head;
        struct Node *prev = tail;

        do
        {
            if (temp->data == value)
                break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data == value)
        {
            if (temp == head && temp == tail)
            {
                head = tail = NULL;
            }
            else
            {
                prev->next = temp->next;

                if (temp == head)
                    head = temp->next;

                if (temp == tail)
                    tail = prev;

                tail->next = head;
            }
            free(temp);
        }
        else
        {
            printf("Element not found\n");
        }
    }
    else
    {
        printf("List is empty\n");
    }

    printf("List: ");
    if (head != NULL)
    {
        temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");

    while (head != NULL)
    {
        temp = head;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        free(temp);
    }

    return 0;
}
