// Problem 3. Write a program in C + + to find the maximu mark,average- marks and
// minimum marks obtained by a study in five papers as given below:
//
//            Paper 1    Paper 2    Paper 3    Paper 4    Paper 5
//  Marks       50         70         65         80         56

#include <iostream>
using namespace std;

int main()
{
    int marks[5] = {50, 70, 65, 80, 56};
    int maxMarks, minMarks, sum = 0;
    float average;

    maxMarks = marks[0];
    minMarks = marks[0];

    for (int i = 0; i < 5; i++)
    {
        sum = sum + marks[i];

        if (marks[i] > maxMarks)
        {
            maxMarks = marks[i];
        }

        if (marks[i] < minMarks)
        {
            minMarks = marks[i];
        }
    }

    average = (float)sum / 5;

    cout << "Maximum Marks = " << maxMarks << endl;
    cout << "Minimum Marks = " << minMarks << endl;
    cout << "Average Marks = " << average << endl;

    return 0;
}
