#include <stdio.h>
#include <string.h>

// print sum of 1 to 10 numbers

int main()
{
    int sum = 0;
    int i = 1;
    while (i <= 10)
    {
        sum = sum + i;
        i++;
    }
    printf("Sum of numbers from 1 to 10 is: %d \n", sum);
    return 0;
}

// print table of given number

int main()
{
    int i = 1, num;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (i <= 10)
    {
        printf("%d\n", num * i);
        i++;
    }
    return 0;
}

// Print factrioal of a given number


int main()
{
    int i = 1;
    int fact = 1;
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (i <= num)
    {
        fact = fact * i;
        i++;
    }
    printf("Factorial of %d is: %d \n", num, fact);
    return 0;
}