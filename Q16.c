#include<stdio.h>
int main()
{
    int i, j, k, temp, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
    { printf("Enter integer at position %d: ", i);
      scanf("%d", &arr[i]); }
    for(i=0; i<n; i++)
    { temp = arr[i];
      int found = 0, count = 0;
      for(j=0; j<i; j++)
      { if(temp == arr[j])
        { found = 1;
          break; }
      }
      if(found == 0)
      { for(k=0; k<n; k++)
      {if(temp == arr[k])
      { count++; }  }
      printf("%d:%d\n", temp, count); }
    }
    return 0;
}