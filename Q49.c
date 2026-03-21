#include <stdio.h>
#include <stdlib.h>

typdef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

struct Node* createNode(int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(node* root, int val) {
    if(root == NULL)
    { return createNode(val); }
    if(val < root->data)
    { root->left = insert(root->left, val); }
    else
    { root->right = insert(root->right, val); }
    return root;
}

void inorder(node* root) {
    if(root == NULL)
    { return; }
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
      { scanf("%d",&arr[i]); }
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);
    struct Node* root = NULL;
    for(int i=0;i<n;i++)
    { if(arr[i] != -1)
      { root = insert(root, arr[i]); }
    }
    root = insert(root, val);
    inorder(root);
    return 0;
}
