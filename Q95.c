#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

// Function to sort a single bucket (Insertion Sort)
struct Node* insertionSort(struct Node* list) {
    if (!list || !list->next) return list;
    struct Node* sorted = NULL;
    struct Node* curr = list;
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // 2. Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }

    // 3. Sort each bucket and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Memory cleanup
        }
    }
    free(buckets);
}
