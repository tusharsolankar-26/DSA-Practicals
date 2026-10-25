
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    int total = 0;

    printf("\nEdge\tWeight\n");

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n",
               parent[i], i, graph[parent[i]][i]);

        total += graph[parent[i]][i];
    }

    printf("Total weight of MST = %d\n", total);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = minKey(key, mstSet);

        if (u == -1)
        {
            printf("Graph is disconnected. MST cannot be formed.\n");
            return;
        }

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                mstSet[v] == false &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
