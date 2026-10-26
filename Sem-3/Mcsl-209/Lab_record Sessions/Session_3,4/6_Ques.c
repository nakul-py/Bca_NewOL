// Question 2

// Write a program in ‘C’ language to multiply two sparse matrices.

#include <stdio.h>

void main()
{
    int c, r, k, m1[3][3], m2[3][3], m3[3][3];
    int z1 = 0, z2 = 0, z3 = 0, prod = 0;

    printf("First Matrix input- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value [%d][%d]: ", r, c);
            scanf("%d", &m1[r][c]);

            if (m1[r][c] == 0)
            {
                z1++;
            }
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

    if (z1 > 9 - z1)
    {
        printf("First Matrix is sparse\n");
    }
    else
    {
        printf("First Matrix is not sparse\n");
    }

    printf("Second Matrix input- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value [%d][%d]: ", r, c);
            scanf("%d", &m2[r][c]);

            if (m2[r][c] == 0)
            {
                z2++;
            }
        }
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

    if (z2 > 9 - z2)
    {
        printf("Second Matrix is sparse\n");
    }
    else
    {
        printf("Second Matrix is not sparse\n");
    }

    // Product of matrices
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            for (k = 0; k < 3; k++)
            {
                prod = prod + m1[r][k] * m2[k][c];
            }
            m3[r][c] = prod;
            prod = 0;
        }
    }

    printf("Display Product Matrix- \n");

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d ", m3[r][c]);

            if (m3[r][c] == 0)
            {
                z3++;
            }
        }
        printf("\n");
    }

    if (z3 > 9 - z3)
    {
        printf("Product Matrix is sparse\n");
    }
    else
    {
        printf("Product Matrix is not sparse\n");
    }
}
