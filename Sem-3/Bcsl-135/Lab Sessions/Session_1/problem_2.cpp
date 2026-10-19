// Problem 2. Write a program in C + + to explain the use of for loop, while loop,
// swith-case, break and continue statements.


#include <iostream>
using namespace std;

int main()
{
    int i, choice;

    // 1. FOR LOOP
    cout << "1. For Loop:" << endl;

    for (i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }

    cout << "\n\n";

    // 2. WHILE LOOP
    cout << "2. While Loop:" << endl;

    i = 1;

    while (i <= 5)
    {
        cout << i << " ";
        i++;
    }

    cout << "\n\n";

    // 3. SWITCH-CASE
    cout << "3. Switch-Case:" << endl;
    cout << "Enter a number (1-3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You selected One";
        break;

    case 2:
        cout << "You selected Two";
        break;

    case 3:
        cout << "You selected Three";
        break;

    default:
        cout << "Invalid choice";
    }

    cout << "\n\n";

    // 4. BREAK STATEMENT
    cout << "4. Break Statement:" << endl;

    for (i = 1; i <= 10; i++)
    {
        if (i == 6)
            break;

        cout << i << " ";
    }

    cout << "\n";

    // 5. CONTINUE STATEMENT
    cout << "5. Continue Statement:" << endl;

    for (i = 1; i <= 10; i++)
    {
        if (i == 6)
            continue;

        cout << i << " ";
    }

    cout << endl;

    return 0;
}
