#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if(q->rear == NULL)
    { q->front = q->rear = newNode;
      return; }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

void displayQueue(Queue* q) {
    Node* temp = q->front;
    while(temp != NULL)
    { printf("%d ", temp->data);
      temp = temp->next; }
    printf("\n");
}

void freeQueue(Queue* q) {
    while(q->front != NULL)
    { dequeue(q); }
    free(q);
}

int main()
{
    int n;
    scanf("%d", &n);
    Queue* q = createQueue();
    for(int i = 0; i < n; i++)
    { int x;
      scanf("%d", &x);
      enqueue(q, x); }
    displayQueue(q);
    freeQueue(q);
    return 0;
}
