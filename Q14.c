#include<stdio.h>
int main()
{
    int n, m, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);
    int arr[n][m];
    if(n != m)
    { printf("Invalid Size of the matrix.");
      return 1; }
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
      { printf("Enter elements at position [%d][%d]: ", i+1, j+1);
        scanf("%d", &arr[i][j]); }
    }
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
      { if((arr[i][j] != 0) && i != j)
      { printf("The matrix is not an Identity Matrix.");
        return 1; }
      }
    }
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
      { if((arr[i][j] != 1) && i == j)
      { printf("The matrix is not an Identity Matrix.");
        return 1; }
      }
    }
    printf("The matrix is an Identity Matrix.");
    return 0;
}