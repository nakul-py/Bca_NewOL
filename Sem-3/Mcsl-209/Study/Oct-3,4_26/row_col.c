#include <stdio.h>

// Nested loop
int main()

{
    int r, c;
    for (r = 1; r <= 4; r++)
    {
        for (c = 1; c <= 4; c++)
        {
            if (r == c)
            {
                printf("1\t");
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
    return 0;
}


int main()

{
    int r, c;
    for (r = 1; r <= 4; r++)
    {
        for (c = 1; c <= r; c++)
        {
           printf("%d\t", c);
            
        }
        printf("\n");
    }
    return 0;
}
