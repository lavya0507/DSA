#include<stdio.h>
int main()
{
    int i, j, n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
    { printf("Enter integer at position %d: ", i);
      scanf("%d", &arr[i]); }
    printf("Enter the number of times you want to rotate the array: ");
    scanf("%d", &k);
    for(i=0; i<k; i++)
    { int temp = arr[n-1];
      for(j=n; j>0; j--)
      { arr[j] = arr[j-1]; }
      arr[0] = temp; }
    printf("\nNew Array: \n");
    for(i=0; i<n; i++)
    { printf("%d ", arr[i]); }
    return 0;
}