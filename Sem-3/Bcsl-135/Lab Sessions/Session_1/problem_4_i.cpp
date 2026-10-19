// Write a program in C + + that prints the factorial of a given number

#include <iostream>
using namespace std;

int main()
{
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers.";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        cout << "Factorial = " << fact;
    }

    return 0;
}