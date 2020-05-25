#include <stdio.h>

//array must be sorted
int arr[] = {0, 6, 30};
int n;

int binarySearch(int *arr, int n, int key);
void test();

int main() {

  n = sizeof(arr) / sizeof(arr[0]);
  
  test();

  return 0;
}

int binarySearch(int *arr, int n, int key) {

  int l = 0, r = n - 1, m = 0;

  while(l <= r) {

    m = l + (r - l) / 2;

    if(arr[m] == key) {
      return m;
    }
    else if (arr[m] > key) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }

  }
  return -1;

}

void test() {

  printf("Test Cases: Started...\n");
  int bs = 0, i = 0;
  for(i = 0; i < n; ++i) {

    bs = binarySearch(arr, n, arr[i]);
    if(bs == i) {
      printf("Test %d: Passed!\n", i+1);
    }
    else {
      printf("Test %d: Failed! expected - %d, found - %d\n", i+1, i, bs);
    }

  }

  bs = binarySearch(arr, n, arr[n-1] + 56);
  if(bs == -1) {
    printf("Test %d: Passed!\n", i+1);
  }
  else {
    printf("Test %d: Failed! expected - %d, found - %d\n", i+1, -1, bs);
  }

  bs = binarySearch(arr, n, arr[0] - 56);
  if(bs == -1) {
    printf("Test %d: Passed!\n", i+2);
  }
  else {
    printf("Test %d: Failed! expected - %d, found - %d\n", i+2, -1, bs);
  }

  printf("Test Cases: Finished\n");

}