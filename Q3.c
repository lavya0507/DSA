#include<stdio.h>
int main()
{
    int i, n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n], found = 0;

    for(i=0; i<n; i++)
    { printf("Enter the element at position [%d]: ", i);
      scanf("%d", &arr[i]); }
    printf("Enter the array you want to find: ");
    scanf("%d", &target);
    for(i=0; i<n; i++)
    { if(target == arr[i])
      { found = 1;
        break; }
    }
    if(found == 1)
    { printf("Found at index: %d\n", i); }
    else
    { printf("Not found\n"); }
    printf("Number of comparisons: %d", i+1);
    return 0;

}
