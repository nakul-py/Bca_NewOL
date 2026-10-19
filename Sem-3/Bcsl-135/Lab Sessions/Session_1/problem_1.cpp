//  Problem1. Write a program in C + + to find and print the all basic data types of C++.


#include <iostream>
using namespace std;

int main()
{
    cout << "Basic Data Types in C++" << endl;
    cout << "------------------------" << endl;

    cout << "1. bool      : " << sizeof(bool) << " byte(s)" << endl;
    cout << "2. char      : " << sizeof(char) << " byte(s)" << endl;
    cout << "3. int       : " << sizeof(int) << " byte(s)" << endl;
    cout << "4. float     : " << sizeof(float) << " byte(s)" << endl;
    cout << "5. double    : " << sizeof(double) << " byte(s)" << endl;
    cout << "6. wchar_t   : " << sizeof(wchar_t) << " byte(s)" << endl;
    cout << "7. void      : No memory size" << endl;

    return 0;
}
