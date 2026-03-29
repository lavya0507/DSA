#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

bool isMirror(struct Node* root1, struct Node* root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 && root2 && root1->data == root2->data)
    { return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left); }
    return false;
}

int main()
{ int n;
  if(scanf("%d", &n) != 1) return 0;
  int arr[n];
  for(int i = 0; i < n; i++)
  { scanf("%d", &arr[i]); }
  if(n == 0 || arr[0] == -1)
  { printf("YES\n");
    return 0; }
  struct Node* root = newNode(arr[0]);
  struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
  int head = 0, tail = 0;
  queue[tail++] = root;

  int i = 1;
  while (i < n)
  { struct Node* curr = queue[head++];
    if(i < n)
    { curr->left = newNode(arr[i++]);
      if (curr->left) queue[tail++] = curr->left; }
    if(i < n)
    { curr->right = newNode(arr[i++]);
      if(curr->right) queue[tail++] = curr->right; }
  }

  if(isMirror(root->left, root->right))
  { printf("YES\n"); }
  else
  { printf("NO\n"); }
  return 0;
}
