#include <stdbool.h>
#include <stdio.h>

int BinarySearch(int list[], int min, int max, int key) {
  int mid;
  mid = (min + max) / 2;
  if (max < min) {
    return -1;
  } else if (key < list[mid]) {
    return BinarySearch(list, min, mid - 1, key);
  } else if (key > list[mid]) {
    return BinarySearch(list, mid + 1, max, key);
  } else {
    return mid;
  }
}

int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int min = 0;
  int max = 9;
  int key = 9;

  int result = BinarySearch(list, min, max, key);

  if (result != -1) {
    printf("Found at index %d in array.\n", result);
  } else {
    printf("Not found in array.\n");
  }

  return 0;
}