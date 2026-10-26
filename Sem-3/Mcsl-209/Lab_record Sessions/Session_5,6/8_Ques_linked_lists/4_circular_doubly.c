// Question 8-  Write a program in C language to create a linked list and implement deletion of an element using pointers.
//              Write separate programs for circular double linked lists.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
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
            newNode->next = newNode->prev = newNode;
        }
        else
        {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head != NULL)
    {
        temp = head;

        do
        {
            if (temp->data == value)
                break;
            temp = temp->next;
        } while (temp != head);

        if (temp->data == value)
        {
            if (temp->next == temp)
            {
                head = tail = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;

                if (temp == tail)
                    tail = temp->prev;
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
        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        free(temp);
    }

    return 0;
}
