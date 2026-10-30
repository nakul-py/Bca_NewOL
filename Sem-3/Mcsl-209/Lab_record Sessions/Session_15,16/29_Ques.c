// Question 29- Write a program in C language to accept an undirected graph as input and print the list of all vertices that are articulation points.

#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX];
int parent[MAX], ap[MAX];
int timer = 0;

void dfs(int u, int n)
{
    int v, children = 0;

    visited[u] = 1;
    disc[u] = low[u] = ++timer;

    for (v = 0; v < n; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;

                dfs(v, n);

                if (low[v] < low[u])
                    low[u] = low[v];

                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }
            else if (v != parent[u])
            {
                if (disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}

int main(void)
{
    int n, i, j, found = 0;

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

    for (i = 0; i < n; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
        ap[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, n);
    }

    printf("Articulation points: ");

    for (i = 0; i < n; i++)
    {
        if (ap[i])
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");
    return 0;
}
