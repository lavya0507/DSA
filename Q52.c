#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* findNode(struct Node* root, int val) {
    if(root == NULL)
        return NULL;
    if(root->data == val)
        return root;

    struct Node* left = findNode(root->left, val);
    if(left != NULL)
        return left;
    return findNode(root->right, val);
}

struct Node* findLCA(struct Node* root, struct Node* p, struct Node* q) {
    if(root == NULL)
        return NULL;
    if(root == p || root == q)
        return root;

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    if(left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    { scanf("%d",&arr[i]); }

    int pVal, qVal;
    scanf("%d %d",&pVal, &qVal);
    struct Node* nodes[n];
    for(int i=0;i<n;i++)
    { if(arr[i] == -1)
          nodes[i] = NULL;
      else
          nodes[i] = createNode(arr[i]);
    }
    for(int i=0;i<n;i++)
      {  if(nodes[i] != NULL)
         { int left = 2*i + 1;
           int right = 2*i + 2;
           if(left < n)
             nodes[i]->left = nodes[left];
           if(right < n)
             nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];
    struct Node* p = findNode(root, pVal);
    struct Node* q = findNode(root, qVal);
    struct Node* lca = findLCA(root, p, q);

    if(lca != NULL)
        printf("%d", lca->data);
    return 0;
}
