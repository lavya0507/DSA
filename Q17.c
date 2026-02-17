#include<stdio.h>
int main()
{
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
    { printf("Enter integer at position %d: ", i);
      scanf("%d", &arr[i]); }
    int max = arr[0], min = arr[0];
    for(i=1; i<n; i++)
    { if(max < arr[i])
      { max = arr[i]; }
      else if(min > arr[i])
      { min = arr[i]; }
    }
    printf("\nThe maximum value is %d", max);
    printf("\nThe minimum value is %d", min);
    return 0;
}