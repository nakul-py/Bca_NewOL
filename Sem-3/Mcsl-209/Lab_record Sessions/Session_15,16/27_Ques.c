// Question 27- Write a program in C language to implement Dijkstra's algorithm.

#include <stdio.h>
#define MAX 20
#define INF 99999

int main(void)
{
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX] = {0};
    int n, source, i, j, count, min, u;

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

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    for (count = 0; count < n; count++)
    {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (i = 0; i < n; i++)
        {
            if (!visited[i] && graph[u][i] > 0 &&
                dist[u] + graph[u][i] < dist[i])
            {

                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printf("\nShortest distances:\n");

    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("%d -> %d = Unreachable\n", source, i);
        else
            printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}
