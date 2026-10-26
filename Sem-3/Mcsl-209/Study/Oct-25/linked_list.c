#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int info;
    struct node *next;
} *start;

void create_list(int);
void display_list();
void insert_at_beg(int);
void insert_at_end(int);

void main()
{
    int choice, val;

    start = NULL;
    while (1)
    {
        printf("1. to create list \n");
        printf("2. to display list \n");
        printf("3. to exit \n");
        printf("4. to insert at begining \n");
        printf("5. to insert at end \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            create_list(val);
            break;
        case 2:
            display_list();
            break;
        case 3:
            exit(1);
            break;
        case 4:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insert_at_beg(val);
            break;
        case 5:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            insert_at_end(val);
            break;
        default:
            printf("Wrong input choice \n");
            break;
        }
    }
} // end of main

void create_list(int m)
{
    struct node *nn, *p;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->info = m;
    nn->next = NULL;

    if (start == NULL)
        start = nn;
    else
    {
        p = start;
        while (p->next != NULL)
            p = p->next;
        p->next = nn;
    }
} // end of create

void display_list()
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
    }

    printf("\n");
} // end of display

void insert_at_beg(int b)
{
    struct node *nn, *p, *q;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->info = b;
    nn->next = NULL;

    if (start == NULL)
    {
        start = nn;
    }
    else
    {
        p = start;
        nn->next = p;
        start = nn;
    }
}

void insert_at_end(int e)
{
    struct node *nn, *p;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->info = e;
    nn->next = NULL;

    if (start == NULL)
        start = nn;
    else
    {
        p = start;
        while (p->next != NULL)
            p = p->next;
        p->next = nn;
    }
}

