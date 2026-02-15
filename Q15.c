#include<stdio.h>
int main()
{
    int n, m, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);
    int arr[n][m], sum = 0;
    for(i=0; i<n; i++)
    { for(j=0; j<m; j++)
      { printf("Enter elements at position [%d][%d]: ", i+1, j+1);
        scanf("%d", &arr[i][j]); }
    }
    for(i=0; i<n; i++)
    { sum += arr[i][i]; }
    printf("The sum of the diagonal elements is %d", sum);
    return 0;
}