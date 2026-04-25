#include<stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n - 1; i++)
    { min_idx = i;
      for(j = i + 1; j < n; j++)
      { if (arr[j] < arr[min_idx])
        { min_idx = j; }
      }
      if(min_idx != i)
      { temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
      }
    }
}

int main() {
    int n, i;
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];
    for(i = 0; i < n; i++)
    { if (scanf("%d", &arr[i]) != 1) break; }
    selectionSort(arr, n);
    for(i = 0; i < n; i++)
    { printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' '); }
    return 0;
}
