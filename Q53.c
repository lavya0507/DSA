#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QNode arr[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[++q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) { 
  return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
  return q->front > q->rear;
}

void verticalTraversal(struct Node* root) {
    if(root == NULL) return;
    struct Queue q;
    q.front = 0; q.rear = -1;
    int map[201][100], count[201] = {0};
    enqueue(&q, root, 0);
    int min = 0, max = 0;

    while(!isEmpty(&q))
    {
        struct QNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd;
        int index = hd + 100;

        map[index][count[index]++] = curr->data;
        if(hd < min) min = hd;
        if(hd > max) max = hd;
        if(curr->left)
            enqueue(&q, curr->left, hd - 1);
        if(curr->right)
            enqueue(&q, curr->right, hd + 1);
    }

    for(int i=min+100; i<=max+100; i++)
    { for(int j=0; j<count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* nodes[n];

    for(int i=0; i<n; i++)
    {   if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

   for(int i=0; i<n; i++)
    {   if(nodes[i] != NULL)
        {   int left = 2*i + 1;
            int right = 2*i + 2;
            if(left < n)
                nodes[i]->left = nodes[left];
            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];
    verticalTraversal(root);
    return 0;
}
