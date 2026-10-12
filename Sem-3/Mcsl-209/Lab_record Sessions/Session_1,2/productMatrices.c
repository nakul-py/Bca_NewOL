// Question 1

// Write a program in `C’ language that accepts two matrices as input and printstheir product.

#include <stdio.h>

void main()
{
    int c, r, k, m1[3][3], m2[3][3], m3[3][3], sum = 0;

    printf("First Matrix input- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value [%d][%d]: ", r, c);
            scanf("%d", &m1[r][c]);
        }
    }

    printf("Second Matrix input- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value [%d][%d]: ", r, c);
            scanf("%d", &m2[r][c]);
        }
    }

    printf("Display First Matrix- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d ", m1[r][c]);
        }
        printf("\n");
    }

    printf("Display Second Matrix- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d ", m2[r][c]);
        }
        printf("\n");
    }

    //  Multiplication

    for(r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            m3[r][c] = 0;

            for (k = 0; k < 3; k++)
            {
                m3[r][c] = m3[r][c] + m1[r][k] * m2[k][c];
            }
        }
    }

    printf("Display Product Matrix- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d ", m3[r][c]);
        }
        printf("\n");
    }
}
