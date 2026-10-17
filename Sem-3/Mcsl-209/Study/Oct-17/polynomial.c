#include <stdio.h>

void main()
{
    int i, poly[5][2];

    for (i = 0; i < 3; i++)
    {
        printf("Enter the coefficient for term %d: ", i);
        scanf("%d", &poly[i][0]);
        printf("Enter the exponent for term %d: ", i);
        scanf("%d", &poly[i][1]);
    }

    printf("p(x) = ");

    for (i = 0; i < 3; i++)
    {
        printf("%dx^%d", poly[i][0], poly[i][1]);

        if (i < 3 - 1)
        {
            printf(" + ");
        }
    }

    printf("\n");
}
