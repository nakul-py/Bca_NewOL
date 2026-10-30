// Question 37- Write a program in C language to implement Topological sort using pointers.

#include <stdio.h>
#define MAX 20

int main(void)
{
    int graph[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX], result[MAX];
    int n, i, j;
    int front = 0, rear = -1, count = 0;

    int (*p)[MAX] = graph;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", *(p + i) + j);

            if (*(*(p + i) + j) == 1)
                indegree[j]++;
        }
    }

    /* Add vertices with indegree 0 */
    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    /* Perform topological sorting */
    while (front <= rear)
    {
        int u = queue[front++];

        result[count++] = u;

        for (j = 0; j < n; j++)
        {
            if (*(*(p + u) + j) == 1)
            {
                indegree[j]--;

                if (indegree[j] == 0)
                    queue[++rear] = j;
            }
        }
    }

    if (count != n)
    {
        printf("Topological sorting is not possible\n");
    }
    else
    {
        printf("Topological order: ");

        for (i = 0; i < count; i++)
            printf("%d ", result[i]);

        printf("\n");
    }

    return 0;
}
