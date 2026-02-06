#include<stdio.h>
int main()
{
   int i, n, j=1;
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   int arr[n];
   for(i=0; i<n; i++)
   { printf("Enter element at position [%d]: ", i);
     scanf("%d", &arr[i]); }
   for(i=1; i<n; i++)
   { if(arr[i] != arr[i-1])
     { arr[j] = arr[i];
       j++;
       n--; }
   }
   for(i=0; i<n; i++)
   { printf("%d", arr[i]);}
}