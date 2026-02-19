#include <stdio.h>
int main()
{
    int n, i, j;
    if(scanf("%d", &n) < 1 || n < 2) return 0;
    int arr[n];
    for(i=0; i<n; i++)
    { scanf("%d", &arr[i]); }
    int a = arr[0], b = arr[1];
    long min_abs = a + b;
    if(min_abs<0) min_abs = -min_abs;
    for(i=0; i<n; i++)
    { for(j=i+1; j<n; j++)
    { int sum = arr[i] + arr[j];
      long current_abs = (sum < 0) ? -(long)sum : (long)sum;
      if(current_abs < min_abs)
      { min_abs = current_abs;
        a = arr[i];
        b = arr[j]; }
    }
    }
    printf("%d %d\n", a, b);
    return 0;
}
