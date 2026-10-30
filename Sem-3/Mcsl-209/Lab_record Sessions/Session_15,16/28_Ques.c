// Question 28- Write a program in C language to implement Kruskal's algorithm.

#include <stdio.h>
#define MAX 100

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void sortEdges(struct Edge e[], int m)
{
    int i, j;
    struct Edge temp;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (e[i].w > e[j].w)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

int main(void)
{
    struct Edge e[MAX];
    int n, m, i, a, b;
    int total = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        printf("Enter source, destination and weight: ");
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(e, m);

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < m && count < n - 1; i++)
    {
        a = find(e[i].u);
        b = find(e[i].v);

        if (a != b)
        {
            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);

            parent[a] = b;
            total += e[i].w;
            count++;
        }
    }

    if (count != n - 1)
    {
        printf("Graph is not connected\n");
    }
    else
    {
        printf("Total minimum cost: %d\n", total);
    }

    return 0;
}
