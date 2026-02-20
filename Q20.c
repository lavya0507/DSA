#include <stdio.h>
int main()
{
    int i, j, n, count=0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
    { printf("Enter the element at position [%d]: ", i);
      scanf("%d", &arr[i]); }
    for(i=0; i<n; i++)
    { int sum = 0;
      for(j=i; j<n; j++)
      { sum += arr[j];
        if(sum == 0)
        { count++; }
      }
    }
    printf("%d", count);
    return 0;
}
