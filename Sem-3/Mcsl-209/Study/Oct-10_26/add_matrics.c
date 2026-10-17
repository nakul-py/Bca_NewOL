// Addition of two matrices

#include <stdio.h> 

int main()
{
    int r, c, A[3][3], B[3][3], C[3][3];
    printf("\t Element of First matrix \n\n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter element of array %d %d : ", r, c);
            scanf("%d", &A[r][c]);
        }
    }
    printf("\n");
    printf("\t Element of Second matrix \n\n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Enter element of array %d %d : ", r, c);
            scanf("%d", &B[r][c]);
        }
    }

    printf("\n\n");
    printf("\t     MATRIX A \n\n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("\t %d ", A[r][c]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("\t     MATRIX B \n\n");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("\t %d ", B[r][c]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("\t  Addition begins \n\n ");
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            C[r][c] = A[r][c] + B[r][c];
        }
    }
    for (r = 0; r < 3; r++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("\t %d ", C[r][c]);
        }
        printf("\n");
    }
    return 0;
}
