// Q12. Write a program in C language to reverse an input string.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char *start, *end;
    char temp;
    int len;

    printf("Enter a string: ");
    scanf("%99s", str);

    len = strlen(str);
    start = str;
    end = str + len - 1;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
