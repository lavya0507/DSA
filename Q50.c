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

// Search in BST
struct Node* search(struct Node* root, int val)
{
    if(root == NULL || root->data == val)
        return root;

    if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

// Inorder traversal
void inorder(struct Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int val;
    scanf("%d",&val);

    struct Node* root = NULL;

    // Build BST
    for(int i=0;i<n;i++)
    {
        if(arr[i] != -1)
            root = insert(root, arr[i]);
    }

    // Search
    struct Node* result = search(root, val);

    if(result == NULL)
        printf("NULL");
    else
        inorder(result);

    return 0;
}
