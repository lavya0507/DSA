#include<stdio.h>
int main()
{
    int n, m, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);
    int arr[n][m];
    printf("Enter matrix elements:\n");
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
      { scanf("%d", &arr[i][j]); }
    }
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    printf("Spiral Traversal: ");
    while(top <= bottom && left <= right)
    { for(i=left; i<=right; ++i)
      { printf("%d ", arr[top][i]); }
        top++;
      for(i=top; i<=bottom; ++i)
      { printf("%d ", arr[i][right]); }
        right--;
      if(top <= bottom)
      { for(i=right; i>=left; --i)
        { printf("%d ", arr[bottom][i]); }
         bottom--;
      }
      if(left <= right)
      { for(i=bottom; i>=top; --i)
        { printf("%d ", arr[i][left]); }
        left++;
      }
    }
    printf("\n");
    return 0;
}
