/*
Stack
by Ankit Verma
dated 10 June, 2020
*/

#include <stdio.h>
#include <stdlib.h>

// node structure for stack
struct Node {
  int val;
  struct Node *next;
};
int sizeOfStack;
struct Node *top = NULL;

// operations on stack
struct Node * createNode();
void push(int);
void pop();
void emptyStack();
void printStack();
int size();
int dataOnTop();

// test function 
void test();

// main function 
int main() {
  test();
  return 0;
}

// definitions of functions for operations on stack

struct Node * createNode() {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  return node;
}

void push(int val) {
  struct Node *newNode = createNode();
  newNode->val = val;
  newNode->next = NULL;
  if(top == NULL) {
    top = newNode;
  }
  else {
    newNode->next = top;
    top = newNode;
  }
  printf("Successfully pushed %d in stack!\n", top->val);
  ++sizeOfStack;
}

void pop() {
  if(top == NULL) {
    printf("The Stack is Empty! Can't pop from empty stack\n");
  }
  else {
    struct Node* nodeToDelete = top;
    top = top->next;
    free(nodeToDelete);
    printf("Successfully poped item from stack!\n");
    --sizeOfStack;
  }
}

void emptyStack() {
  while(top != NULL) {
    pop();
  }
  printf("Successfully emptied stack!\n");
}

void printStack() {
  struct Node *node = top;
  printf("Stack: ");
  while(node != NULL) {
    printf("%d ] ", node->val);
    node = node->next;
  }
  printf("\n");
}

int size() {
  return sizeOfStack;
}

int dataOnTop() {
  if(top == NULL) {
    printf("Stack is empty!\n");
    exit(0);
  }
  return top->val;
}

// test - definition
void test() {
  push(10);
  printStack();
  printf("The size of stack is %d\n", size());
  printf("The data on top of stack is %d\n", dataOnTop());
  push(0);
  printStack();
  printf("The data on top of stack is %d\n", dataOnTop());
  printf("The size of stack is %d\n", size());
  emptyStack();
  pop();
  printf("The size of stack is %d\n", size());
  printStack();
  printf("The data on top of stack is %d\n", dataOnTop());
  pop();
  printStack();
}

