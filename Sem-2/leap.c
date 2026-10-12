#include <stdio.h>

int main()
{
    int year;
    int isLeap;

    printf("Enter a year: ");
    scanf("%d", &year);

    isLeap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

    switch (isLeap)
    {
    case 1:
        printf("%d is a leap year.\n", year);
        break;

    case 0:
        printf("%d is not a leap year.\n", year);
        break;

    default:
        printf("Invalid input.\n");
    }

    return 0;
}