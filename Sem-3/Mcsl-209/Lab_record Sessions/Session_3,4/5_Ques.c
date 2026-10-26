// Question 5- Write a program in C language that accepts the enrolment number, name, and aggregate marks secured by students.
//             Assign ranks according to marks, with Rank 1 awarded to the student with the highest marks. Print the enrolment number, name,
//             and rank of each student in ascending order.

#include <stdio.h>
#include <string.h>

struct Student
{
    int enrolment;
    char name[50];
    float marks;
    int rank;
};

int main(void)
{
    struct Student s[100], temp;
    int n, i, j;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enrolment number: ");
        scanf("%d", &s[i].enrolment);

        printf("Name: ");
        scanf("%49s", s[i].name);

        printf("Aggregate marks: ");
        scanf("%f", &s[i].marks);
    }

    /* Sort students by marks in descending order */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].marks < s[j].marks)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    /* Assign ranks */
    for (i = 0; i < n; i++)
    {
        s[i].rank = i + 1;
    }

    /* Display students in ascending order of rank */
    printf("\nStudent Rank List\n");
    printf("-----------------------------------------------\n");
    printf("%-15s %-20s %-10s\n",
           "Enrolment No.", "Name", "Rank");
    printf("-----------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-15d %-20s %-10d\n",
               s[i].enrolment, s[i].name, s[i].rank);
    }

    return 0;
}
