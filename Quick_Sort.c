#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

int main() {
  int arr[] = {8, 3, 7, 6, 2, 5, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Array Before Soritng : ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  quickSort(arr, 0, size - 1);
  printf("\nArray After Sorting : ");

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
