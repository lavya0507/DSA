#include<stdio.h>
#include<stdlib.h>

int findIndex(int arr[], int start, int end, int value) {
    for(int i=start; i<=end; i++)
    { if(arr[i] == value) return i; }
    return -1;
}
void printPostorder(int preorder[], int inorder[], int inStart, int inEnd, int* preIdx) {
    if (inStart > inEnd) return;
    int rootVal = preorder[*preIdx];
    (*preIdx)++;
    int rootIdx = findIndex(inorder, inStart, inEnd, rootVal);
    printPostorder(preorder, inorder, inStart, rootIdx - 1, preIdx);
    printPostorder(preorder, inorder, rootIdx + 1, inEnd, preIdx);
    printf("%d ", rootVal);
}
int main()
{
    int n;
    if(scanf("%d", &n) != 1) return 0;
    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", &preorder[i]);
    for(int i=0; i<n; i++) scanf("%d", &inorder[i]);

    int preIdx = 0;
    printPostorder(preorder, inorder, 0, n - 1, &preIdx);
    printf("\n");
    free(preorder);
    free(inorder);
    return 0;
}
