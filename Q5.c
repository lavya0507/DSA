#include<stdio.h>
int main()
{
    int i, j, n, m;
    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    printf("Enter the size of the second array: ");
    scanf("%d", &m);
    int arr1[n+m], arr2[m];
    printf("First array: \n");
    for(i=0; i<n; i++)
    { printf("Enter the element at position [%d]: ", i);
      scanf("%d", &arr1[i]); }
    printf("Second array: \n");
    for(i=0; i<m; i++)
    { printf("Enter the element at position [%d]: ", i);
      scanf("%d", &arr2[i]); }
    for(i=0; i<m; i++)
    { arr1[i+m] = arr2[i]; }

    for(i=0; i<n+m; i++)
    { for(j=0; j<n+m; j++)
       { if(arr1[j] > arr1[j+1])
         { int temp = arr1[j];
           arr1[j] = arr1[j+1];
           arr1[j+1] = temp; }
       }
    }
    printf("\n");
    for(i=0; i<n+m; i++)
    { printf("%d", arr1[i]); }
    return 0;
}
