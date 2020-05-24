/*
Dynamic Array
by Ankit Verma
dated 24 May, 2020
*/

#include <stdio.h>
#include <stdlib.h>

//array properties
int *arr = NULL;
int n = 0;
int last = -1;

//array methods
void createArray();
void deleteArray();
void showArray();
void resizeArray();
void updateNum(int num, int idx);
void addNum(int num, int idx);
void deleteNum(int num_idx, int isChoiceNum);

//test method
void test();

//interactive user mode play
void play();

//main function
int main() {

  // test();
  play();
  return 0;
  
}

//definitions - methods

void createArray() {
  arr = (int *)calloc(n, sizeof(int));
  if(arr) {
    printf("Successfully Created! Array with size %d\n", n);
  }
}

void deleteArray() {
  free(arr);
  printf("Successfully Deleted Array!\n");
}

void updateNum(int num, int idx) {
  
  if(idx >= n || idx < 0) {
    printf("Can't update to invalid idx: %d!\n", idx);
    deleteArray();
    exit(0);
  }
  else if(idx > last) {
    *(arr + ++last) = num;
     printf("Successfully added! %d at index %d: (last) - instead of %d\n", *(arr + last), last, idx);
  }
  else {
    *(arr + idx) = num;
    printf("Successfully updated! %d at index %d\n", *(arr + idx), idx);
  }

}

void addNum(int num, int idx) {
  
  if(last + 1 == n) {
    printf("Array is full!\n");
    resizeArray();
  }
  
  if(idx < 0 || idx >= n) {
    printf("Can't add to invalid idx: %d!\n", idx);
    deleteArray();
    exit(0);
  }
  else if(idx > last) {
    *(arr + ++last) = num;
     printf("Successfully added! %d at index %d: (last) - instead of %d\n", *(arr + last), last, idx);
  }
  else {
    for(int i = last; i >= idx; --i) {
      *(arr + i + 1) = *(arr + i);
    }
    *(arr + idx) = num;
    printf("Successfully added! %d at index %d\n", *(arr + idx), idx);
    ++last;
  }

}

void deleteNum(int num_idx, int isChoiceNum) {
  
  int idx = 0;
  
  if(isChoiceNum) {
    for(idx = 0; idx <= last; ++idx) {
      if(*(arr + idx) == num_idx) {
        break;
      }
    }
  }
  else {
    idx = num_idx;
  }

  if(idx >= n || idx < 0) {
    printf("Can't delete: invalid idx: %d!\n", idx);
    deleteArray();
    exit(0);
  }
  else if(idx > last) {
    printf("Can't delete: invalid idx: %d! (no num there)\n", idx);
    deleteArray();
    exit(0);
  }
  else {
    for(int i = idx; i <= last; ++i) {
      *(arr + i) = *(arr + i + 1);
    }
    printf("Successfully deleted! number from index: %d\n", idx);
    --last;
  }

}

void showArray() {
  printf("Array: ");
  for(int i = 0; i <= last; ++i) {
    printf("%d, ", *(arr + i));
  }
  printf("\n");
}

void resizeArray() {

  printf("Resizing Array...\n");
  n = 2 * n;
  arr = (int *)realloc(arr, n * sizeof(int));

  if(arr) {
    printf("Successfully resized array!\n");
  }
  else {
    printf("Resizeing array failed!\n");
    deleteArray();
    exit(0);
  }

}

//definition - test

void test() {

  printf("Test is executing...\n");
  n = 3;
  createArray();
  addNum(4, 2);
  showArray();
  updateNum(1, 0);
  showArray();
  addNum(7, 2);
  showArray();
  addNum(5, 0);
  showArray();
  deleteNum(7, 1);
  showArray();
  addNum(3, 1);
  showArray();
  addNum(9, 1);
  showArray();
  deleteArray();
  printf("Test finished!\n");

}

//definition - play

void play() {

  system("cls");
  printf("Let's play with arrays :)\n");

  printf("Let's start by creating our array\n");
  n = 1;
  createArray();

  int choice = 0;
  int num = 0, idx = 0;
  do {
    fflush(stdin);
    /*--- Interactive Logic ---*/

    printf("----------------------------------------------------------------------------\n");

    printf("1. Add number\n");
    printf("2. Update number\n");
    printf("3. Delete number\n");
    printf("4. Show Array\n");
    printf("5. Show details of array\n");
    printf("6. Quit \n");
    printf("What do you want to do? : ");

    while(!scanf("%d", &choice)) fflush(stdin);

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    switch(choice) {
      case 1:

        printf("Enter num: ");
        while(!scanf("%d", &num)) fflush(stdin);
        printf("Enter idx: ");
        while(!scanf("%d", &idx)) fflush(stdin);
        
        addNum(num, idx);
        break;

      case 2:
        
        printf("Enter num: ");
        while(!scanf("%d", &num)) fflush(stdin);
        printf("Enter idx: ");
        while(!scanf("%d", &idx)) fflush(stdin);
        
        updateNum(num, idx);
        break;

      case 3:
        
        printf("Enter num or idx: ");
        while(!scanf("%d", &num)) fflush(stdin);
        printf("Enter choice(0 - idx/1 - num): ");
        while(!scanf("%d", &idx)) fflush(stdin);
        
        deleteNum(num, idx);
        break;

      case 4:

        showArray();
        break;

      case 5:

        printf("Array Filled: %d out of %d size\n", last + 1, n);
        break;

      default:

        printf("Bye Bye!!\n");
        break;

    }

    /*--- Interactive Logic Ends ---*/
  } while(choice < 6 && choice > 0);

  deleteArray();
  printf("Thanks for playing! :)");
}
