// Write a program in C + + that generate a Fibonacci series of 50 numbers.

#include <iostream>
using namespace std;

int main()
{
    long long first = 0, second = 1, next;

    cout << "Fibonacci Series of 50 numbers: \n";

    for (int i = 1; i <= 50; i++)
    {
        cout << first << " \n";

        next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
    return 0;
}