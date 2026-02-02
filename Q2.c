#include<stdio.h>
int main() 
{
    int n, i, index;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++) 
    {  printf("Enter the element at position [%d]: ", i);
       scanf("%d", &arr[i]); }
    printf("Enter the index you want to delete: ");
    scanf("%d", &index);
    for(i=index; i<n; i++)
    { arr[i] = arr[i+1]; }
    printf("\nFinal Array: ");
    for(i=0; i<n-1; i++)
    { printf("%d ", arr[i]); }
    return 0;
}