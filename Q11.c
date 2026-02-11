#include<stdio.h>
int main()
{
  int i, j, r, c;
  printf("Enter the size of both the Array's: ");
  scanf("%d %d", &r, &c);
  int arr1[r][c], arr2[r][c];
  printf("\nEnter for Array-1:\n");
  for(i=0; i<r; i++)
  { for(j=0; j<c; j++)
  { printf("Enter element at position [%d][%d]: ", i+1, j+1);
    scanf("%d", &arr1[i][j]); }
  }
  printf("\nEnter for Array-2:\n");
  for(i=0; i<r; i++)
  { for(j=0; j<c; j++)
  { printf("Enter element at position [%d][%d]: ", i+1, j+1);
    scanf("%d", &arr2[i][j]); }
  }
  int sum[r][c];
  printf("\nThe addition of the two matrices is as follows:\n");
  for(i=0; i<r; i++)
  { for(j=0; j<c; j++)
  { sum[i][j] = arr1[i][j] + arr2[i][j];
    printf("%d ", sum[i][j]); }
  printf("\n");
  }
  return 0;
}