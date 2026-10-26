// Question 2

// Write a program in `C’ Language to accept 10 strings as input and print them in lexicographic order

#include <stdio.h>
#include <string.h>

int main()
{
    char str[10][20], temp[20];
    int i, j;

    for (i = 0; i < 10; i++)
    {
        printf("Enter string %d: ", i + 1);
        scanf("%s", str[i]);
    }

    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("Strings in lexicographic order:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}