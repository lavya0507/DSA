#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // We can use an array as our "stack" to store N integers
    int *stack = (int *)malloc(n * sizeof(int));

    // 1. Read input and push onto the stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }

    // 2. Pop from the stack (print from end to start)
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    free(stack);
    return 0;
}
