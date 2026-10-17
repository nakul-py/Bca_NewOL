// searching of element in an array

#include <stdio.h>
int main()
{
    int i, ar[5], key, found = 0, loc;
    printf("enter 5 numbers of array \n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("enter key to search: ");
    scanf("%d", &key);

    for (i = 0; i < 5; i++)

    {
        if (key == ar[i])

        {
            found = 1;
            loc = i + 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("key not in the list");
    }
    else
    {
        printf("\n\t 😉 Found at location %d \n", loc);
    }
    return 0;
}

