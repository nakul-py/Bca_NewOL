#include<stdio.h>
int main() {
    int num , temp, rev = 0, digit;
printf("please enter the number");
scanf("%d",&num);
    temp = num;

    do{
        digit = temp % 10;
        rev = rev * 10 + digit;
        temp = temp / 10;
    }
    while(temp != 0);

    if(num == rev)
        printf("Palindrome");
    else
        printf("not palindrome");

    return 0;
}