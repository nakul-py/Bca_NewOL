// Question 4

// Write a program to concatenate two strings S1 and S2.

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[20];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}
