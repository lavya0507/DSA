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

// Insert into BST
struct Node* insert(struct Node* root, int val)
{
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int p, int q)
{
    if(root == NULL)
        return NULL;

    if(p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    if(p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    return root; // split point
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int p, q;
    scanf("%d %d",&p,&q);

    struct Node* root = NULL;

    // Build BST
    for(int i=0;i<n;i++)
        root = insert(root, arr[i]);

    struct Node* lca = findLCA(root, p, q);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}
