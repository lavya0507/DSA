#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *front, *rear;
    int size;
} Deque;

// Initialize Deque
void initDeque(Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// push_front: O(1)
void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (!dq->front) dq->rear = newNode;
    else dq->front->prev = newNode;
    dq->front = newNode;
    dq->size++;
}

// push_back: O(1)
void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = dq->rear;
    newNode->next = NULL;
    if (!dq->rear) dq->front = newNode;
    else dq->rear->next = newNode;
    dq->rear = newNode;
    dq->size++;
}

// pop_front: O(1)
void pop_front(Deque* dq) {
    if (!dq->front) return;
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (!dq->front) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
    dq->size--;
}

// pop_back: O(1)
void pop_back(Deque* dq) {
    if (!dq->rear) return;
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (!dq->rear) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
    dq->size--;
}

// Utility: print state
void display(Deque* dq) {
    Node* curr = dq->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);
    
    printf("Front: %d, Back: %d, Size: %d\n", dq.front->data, dq.rear->data, dq.size);
    display(&dq); // Output: 20 10 30

    pop_front(&dq);
    display(&dq); // Output: 10 30

    return 0;
}
