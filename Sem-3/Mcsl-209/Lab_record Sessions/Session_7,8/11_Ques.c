// Qusetion 11. Write a program in C language to convert a prefix expression to a postfix expression using pointers.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char prefix[100], stack[100][100];
    char *p;
    int top = -1;
    int i;

    printf("Enter prefix expression: ");
    scanf("%99s", prefix);

    for (p = prefix + strlen(prefix) - 1; p >= prefix; p--)
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            top++;
            stack[top][0] = *p;
            stack[top][1] = '\0';
        }
        else
        {
            char a[100], b[100];

            strcpy(a, stack[top--]);
            strcpy(b, stack[top--]);

            top++;
            strcpy(stack[top], a);
            strcat(stack[top], b);

            i = strlen(stack[top]);
            stack[top][i] = *p;
            stack[top][i + 1] = '\0';
        }
    }

    printf("Postfix expression: %s\n", stack[top]);

    return 0;
}
