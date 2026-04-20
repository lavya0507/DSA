#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 100
#define INF INT_MAX

int findMinKey(int key[], bool mstSet[], int n) {
    int v, min = INF, min_index;
    for(v=1; v<=n; v++)
    { if(mstSet[v] == false && key[v] < min)
      { min = key[v];
        min_index = v; }
    }
    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int key[MAX], total_weight = 0, i, count;
    bool mstSet[MAX];
    for(i=1; i<=n; i++)
    { key[i] = INF;
      mstSet[i] = false; }
    key[1] = 0;
    for(count=0; count<n; count++)
    { int u = findMinKey(key, mstSet, n);
      mstSet[u] = true;
      total_weight += key[u];
      for(int v=1; v<=n; v++)
      { if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        { key[v] = graph[u][v]; }
      }
    }
    printf("%d\n", total_weight);
}

int main()
{
    int i, n, m, graph[MAX][MAX] = {0};
    if(scanf("%d %d", &n, &m) != 2) return 0;

    for(i=0; i<m; i++)
    { int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      graph[u][v] = w;
      graph[v][u] = w; }
    primMST(graph, n);
    return 0;
}