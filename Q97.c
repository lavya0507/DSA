#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
} Meeting;

int compareMeetings(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void push(int heap[], int* size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
}

int minMeetingRooms(int start[], int end[], int n) {
    if (n == 0) return 0;
    Meeting* meetings = malloc(n * sizeof(Meeting));
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }
    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int* heap = malloc(n * sizeof(int));
    int heapSize = 0;
    push(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= heap[0]) {
            pop(heap, &heapSize);
        }
        push(heap, &heapSize, meetings[i].end);
    }

    int result = heapSize;
    free(meetings);
    free(heap);
    return result;
}
