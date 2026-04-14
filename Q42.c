#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, i;
    if(scanf("%d", &n) != 1) return 0;
    int *stack = (int *)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    { scanf("%d", &stack[i]); }
    for(i=n-1; i>=0; i--)
    { printf("%d", stack[i]);
      if(i > 0) printf(" ");
    }
    printf("\n");
    free(stack);
    return 0;
}
