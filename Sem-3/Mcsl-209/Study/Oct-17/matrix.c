#include <stdio.h>

// Input the matrix

void main()
{

    int m1[3][3], r, c, k, m2[3][3], m3[3][3];

    printf("\n 1st Matrix input \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value for %d %d location :", r, c);
            scanf("%d", &m1[r][c]);
        }
    }

    printf("\n 2nd Matrix input \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value for %d %d location :", r, c);
            scanf("%d", &m2[r][c]);
        }
    }

    printf("\n 1st Matrix Display \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d\t", m1[r][c]);
        }
        printf("\n");
    }

    printf("\n 2nd Matrix Display \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d\t", m2[r][c]);
        }
        printf("\n");
    }

    // Addition

    printf("\n Addition \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            m3[r][c] = m1[r][c] + m2[r][c];
        }
    }

    printf("\n Addition display \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("%d\t", m3[r][c]);
        }
        printf("\n");
    }

    // Multiplication

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            m3[r][c] = 0;

            for (k = 0; k < 3; k++)
            {
                m3[r][c] = m1[r][k] * m2[k][c];
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
