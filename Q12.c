#include<stdio.h>
int main()
{
    int i, j, n, m;
    printf("Enter the size of the array(n*m): ");
    scanf("%d %d", &n, &m);
    if(n != m)
    { printf("The matrix is not Symmetric.");
      return 1; }
    int arr[n][m];
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
    { printf("Enter the element at position [%d][%d]: ", i+1, j+1);
      scanf("%d", &arr[i][j]); }
    }
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
    { if(arr[j][i] != arr[i][j])
      { printf("The matrix is not Symmetric.");
        return 1; }
    }
    }
    printf("The matrix is Symmetric.");
    return 0;
}