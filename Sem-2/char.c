#include <stdio.h>

// Character

// int main()
// {
//     char ch;
//     printf("Enter a character: ");
//     scanf(" %c", &ch);

//     if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//         ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//     {
//         printf("%c is a vowel.\n", ch);
//     }
//     else
//         printf("%c is a consonant\n", ch);
//     return 0;
// }

//  Table of 3

int main()
{
    int i = 1;

    for (; i <= 10; i++)
    {
        printf("3 x %d = %d\n", i, 3 * i);
    }
    printf("End of the loop\n");
    return 0;
}
