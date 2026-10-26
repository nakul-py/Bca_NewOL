
// Question 7- Write a program in C language to accept a paragraph of text as input and display a list of words with the number of occurrences of each word.
//             Use an array of structures, with each structure containing two fields: one for the word and the other for its occurrence count.

#include <stdio.h>
#include <string.h>

struct Word
{
    char word[50];
    int count;
};

int main(void)
{
    char text[1000];
    struct Word w[100];
    char *token;
    int i, n = 0, found;

    printf("Enter a paragraph:\n");
    fgets(text, sizeof(text), stdin);

    token = strtok(text, " .,!?;\n");

    while (token != NULL)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (strcmp(w[i].word, token) == 0)
            {
                w[i].count++;
                found = 1;
                break;
            }
        }

        if (found == 0 && n < 100)
        {
            strcpy(w[n].word, token);
            w[n].count = 1;
            n++;
        }

        token = strtok(NULL, " .,!?;\n");
    }

    printf("\nWord \t\tOccurrences\n");

    for (i = 0; i < n; i++)
    {
        printf("%-20s %-10d\n", w[i].word, w[i].count);
    }

    return 0;
}
