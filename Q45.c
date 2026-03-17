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

int max(int a, int b)
{ return (a > b) ? a : b; }

int height(struct Node* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    { scanf("%d",&arr[i]); }
  
    struct Node* nodes[n];
    for(int i=0;i<n;i++)
    { if(arr[i] == -1)
      { nodes[i] = NULL; }
      else
      { nodes[i] = createNode(arr[i]); }
    }
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

    printf("%d", height(root));

    return 0;
}
