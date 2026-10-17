#include <stdio.h>

void main()
{

    int c, r, m1[3][3];
    int z = 0, nz = 0;

    printf("\n 1st Matrix input \n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter value for %d %d location :", r, c);
            scanf("%d", &m1[r][c]);
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

    // Check for Sparse Matrix

    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            if (m1[r][c] == 0)
            {
                z++;
            }
            else
            {
                nz++;
            }
        }
    }

    if (z > nz)
    {
        printf("Sparse Matrix \n");
    }
    else
    {
        printf("Not Sparse \n");
    }
}