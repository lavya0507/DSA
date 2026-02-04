#include<stdio.h>
int main()
{
    int  i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n], temp = 0;
    for(i=0; i<n; i++)
    { printf("Enter element at position [%d]: ", i);
      scanf("%d", &arr[i]); }
    for(i=0; i<n/2; i++)
    { temp = arr[i];
      arr[i] = arr[n-i-1]; 
      arr[n-i-1] = temp; }
    printf("New array: \n");
    for(i=0; i<n; i++)
    { printf("%d ", arr[i]); }
    return 0;
}