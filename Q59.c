#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the index of a value in the inorder array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to construct the tree
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    // Use the last element in the current postorder range as root
    int curr = postorder[*postIndex];
    struct Node* node = newNode(curr);
    (*postIndex)--;

    // Find this root's index in the inorder array
    int inIndex = findIndex(inorder, inStart, inEnd, curr);

    // Build Right subtree first, then Left
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to print preorder traversal
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printPreorder(root);
    printf("\n");

    return 0;
}
