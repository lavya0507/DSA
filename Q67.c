#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void dfs(int v, int numNodes) {
    visited[v] = 1;
    
    for (int i = 0; i < numNodes; i++) {
        // If there's an edge and neighbor isn't visited
        if (adj[v][i] && !visited[i]) {
            dfs(i, numNodes);
        }
    }
    
    // Push to stack after visiting all neighbors
    push(v);
}

void topologicalSort(int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i, numNodes);
        }
    }

    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int nodes = 6;
    adj[5][2] = 1; adj[5][0] = 1;
    adj[4][0] = 1; adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(nodes);
    return 0;
}
