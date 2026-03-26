#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void zigzag(struct Node* root)
{
    if(root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;

    while(front < rear)
    {
        int size = rear - front;
        int temp[100];

        for(int i = 0; i < size; i++)
        {
            struct Node* curr = queue[front++];

            int index = (level % 2 == 0) ? i : (size - 1 - i);
            temp[index] = curr->data;

            if(curr->left)
                queue[rear++] = curr->left;
            if(curr->right)
                queue[rear++] = curr->right;
        }

        for(int i = 0; i < size; i++)
            printf("%d ", temp[i]);

        level++;
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* nodes[n];

    // Create nodes
    for(int i=0;i<n;i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Link children
    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    zigzag(root);

    return 0;
}
