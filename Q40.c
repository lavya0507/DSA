#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure to keep track of front and rear
struct Queue {
    struct Node *front, *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add an element to the rear
void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue: Remove and return the front element
int dequeue(struct Queue* q) {
    // If queue is empty, return -1
    if (q->front == NULL) {
        return -1;
    }

    struct Node* temp = q->front;
    int data = temp->data;

    q->front = q->front->next;

    // If front becomes NULL, set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') { // "enqueue"
            int val;
            scanf("%d", &val);
            enqueue(q, val);
        } else if (op[0] == 'd') { // "dequeue"
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
