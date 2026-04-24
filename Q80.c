#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF INT_MAX

struct Node {
    int v, weight;
    struct Node* next;
};
struct Element {
    int dist, u;
};
void swap(struct Element* a, struct Element* b) {
    struct Element temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct Element heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && heap[left].dist < heap[smallest].dist) smallest = left;
    if (right < n && heap[right].dist < heap[smallest].dist) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}
void push(struct Element heap[], int* n, int d, int u) {
    heap[*n].dist = d;
    heap[*n].u = u;
    int i = (*n)++;
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
struct Element pop(struct Element heap[], int* n) {
    struct Element root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}
void dijkstra(int n, struct Node* adj[], int source) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;
    struct Element heap[1000];
    int heapSize = 0;
    push(heap, &heapSize, 0, source);

    while (heapSize > 0) {
        struct Element top = pop(heap, &heapSize);
        int u = top.u;
        int d = top.dist;
        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            if (dist[u] != INF && dist[u] + temp->weight < dist[temp->v]) {
                dist[temp->v] = dist[u] + temp->weight;
                push(heap, &heapSize, dist[temp->v], temp->v);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}
int main() {
    int n, m, source;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Node* adj[n + 1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->v = v;
        newNode->weight = w;
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    scanf("%d", &source);
    dijkstra(n, adj, source);
    return 0;
}