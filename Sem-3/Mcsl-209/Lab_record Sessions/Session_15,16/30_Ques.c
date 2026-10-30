// Question 30- Write a program in C language to accept a directed graph as input and print all its strongly connected components.

#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;

void dfs1(int u, int n)
{
    int v;

    visited[u] = 1;

    for (v = 0; v < n; v++)
    {
        if (graph[u][v] && !visited[v])
            dfs1(v, n);
    }

    stack[++top] = u;
}

void dfs2(int u, int n)
{
    int v;

    visited[u] = 1;
    printf("%d ", u);

    for (v = 0; v < n; v++)
    {
        if (graph[v][u] && !visited[v])
            dfs2(v, n);
    }
}

int main(void)
{
    int n, i, j, component = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    /* First DFS */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs1(i, n);
    }

    /* Second DFS on transpose graph */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");

    while (top != -1)
    {
        int u = stack[top--];

        if (!visited[u])
        {
            component++;
            printf("Component %d: ", component);

            dfs2(u, n);

            printf("\n");
        }
    }

    return 0;
}
