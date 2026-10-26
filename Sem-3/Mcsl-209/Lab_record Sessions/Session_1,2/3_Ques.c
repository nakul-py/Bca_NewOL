// Question 3

/*
  Write a program in `C’ Language that accepts two strings S1 and S2 as input.
  The program should check if S2 is a substring of S1 or not. If S2 is a substringof S1,
  then the program should output the starting location and endinglocation of S2 in S1.
  If S2 appears more than once in S1, then the locations of all instances have to be given.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int found = 0, start, end, len;
    char str1[100], str2[50];
    char *ptr;

    printf("Enter String1: ");
    scanf("%s", str1);
    printf("Enter String2: ");
    scanf("%s", str2);

    len = strlen(str2);
    ptr = str1;

    while ((ptr = strstr(ptr, str2)) != NULL)
    {
        start = ptr - str1;
        end = start + len - 1;
        printf("Substring found at location %d to %d\n", start + 1, end + 1);

        found = 1;
        ptr++;
    }

    if (found == 0)
    {
        printf("String2 is not SubString of String1 \n");
    }

    return 0;
}

//  Sir's idea to find substring, its working. But we also have to find start and end loc of substing
//  so we are using While loop to check the start and end loc.

//  if (strcmp(str1, str2) > 0)
//     {
//         if (strstr(str1, str2) != NULL)
//         {
//             printf("String2 is SubString of String1 \n");
//         }
//         else
//         {
//             printf("String2 is not SubString of String1 \n");
//         }
//     }
//     else
//     {
//         printf("String2 cannot be  SubString of String1 \n");
//     }
