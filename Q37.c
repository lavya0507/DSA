#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap helper function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain heap property after insertion
void insert(int x) {
    heap[size] = x;
    int curr = size;
    size++;

    while (curr > 0 && heap[curr] < heap[(curr - 1) / 2]) {
        swap(&heap[curr], &heap[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

// Maintain heap property after deletion
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    
    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;

    int curr = 0;
    while (2 * curr + 1 < size) {
        int smallest = 2 * curr + 1;
        if (smallest + 1 < size && heap[smallest + 1] < heap[smallest]) {
            smallest++;
        }
        if (heap[curr] <= heap[smallest]) break;
        
        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n, val;
    char op[10];

    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
