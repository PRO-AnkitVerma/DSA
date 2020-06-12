/*
Queue
by Ankit Verma
dated 12 June, 2020
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for Queue
struct Node {
  int val;
  struct Node *next;
};
struct Node *front, *last;

// Basic Queue Operations
void enque(int val);
void deque();
int peek();
void emptyQueue();

// Utility Functions
void printQueue();
struct Node * createNode();

// Tests
void test();

// Main Function
int main() {
  test();
  return 0;
}

// Definitions Start Here

struct Node * createNode() {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  return node;
}

void enque(int val) {
  struct Node *newNode = createNode();
  newNode->val = val;
  newNode->next = NULL;
  if(front == NULL) {
    front = last = newNode;
  }
  else {
    last->next = newNode;
    last = newNode;
  }
  printf("Successfully Enqued!\n");
}

void deque() {
  if(front == NULL) {
    printf("The Queue is already Empty!\n");
    return;
  }
  else {
    struct Node *nodeToDelete = front;
    if(front == last) {
      last = NULL;
    }
    front = front->next;
    free(nodeToDelete);
  }
  printf("Successfully Dequed!\n");
}

int peek() {
  if(front == NULL) {
    printf("The Queue is Empty! Don't have value to display\n");
    exit(0);
  }
  return front->val;
}

void printQueue() {
  struct Node *node = front;
  printf("Queue: ");
  while(node != NULL) {
    printf("%d <- ", node->val);
    node = node->next;
  }
  printf("\n");
}

void emptyQueue() {
  while(front != NULL) {
    deque();
  }
  printf("Successfully Emptied Queue!\n");
}

// Tests
void test() {
  enque(3); printQueue();
  enque(5); printQueue();

  printf("The data on front is %d!\n", peek());
  
  enque(8); printQueue();
  deque();  printQueue();

  printf("The data on front is %d!\n", peek());

  emptyQueue(); printQueue();

  enque(3); printQueue();
  deque();  printQueue();

  printf("The data on front is %d!\n", peek());
  
  emptyQueue(); printQueue();
}