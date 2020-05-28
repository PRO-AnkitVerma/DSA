/*
Singley Linked List
by Ankit Verma
dated 29 May, 2020
*/

#include <stdio.h>
#include <stdlib.h>

//node - basic element of linked list
struct Node {
  int val;
  struct Node *next;
};

//linked list attributes
struct Node *head, *lastNode, *newNode;
int n;

//linked list methods
void elementsInLinkedList();
void insertAtBeginning(int num);
void insertAtEnd(int num);
void insertAtnthPos(int num, int pos);
void deleteAtBeginning(); 
void deleteAtEnd(); 
void deleteAtnthPos(int pos); 
void deleteNode(int num); 
void deleteLinkedList();
void printLinkedList();

//test method
void test();

//main function
int main() {

  test();
  return 0;

}

//definition - linked list methods

void deleteLinkedList() {
  printf("Deleting Linked List...\n");
  struct Node *node = NULL, *deleteNode = NULL;
  node = head;
  while(node != NULL) {
    deleteNode = node;
    node = node->next;
    printf("Deleted %d from Linked List!\n", deleteNode->val);
    free(deleteNode);
  }
  head = NULL;
  lastNode = NULL;
  newNode = NULL;
  n = 0;
  printf("Successfully deleted Linked List!\n");
}

void insertAtEnd(int num) {
  newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->val = num;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
    printf("Successfully created Linked List!\n");
  }
  else {
    lastNode->next = newNode;
  }
  lastNode = newNode;
  printf("Successfully added %d! (end)\n", lastNode->val);
  ++n;
}

void insertAtBeginning(int num) {
  newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->val = num;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
    lastNode = newNode;
    printf("Successfully created Linked List!\n");
  }
  else {
    newNode->next = head;
    head = newNode;
  }
  printf("Successfully added %d! (beginning)\n", head->val);
  ++n;
}

void insertAtnthPos(int num, int pos) {
  
  if(pos < 1 || pos > n + 1) {
    printf("Can't insert %d at %d position - (1 to max posn possible is %d)!\n", num, pos, n + 1);
    deleteLinkedList();
    exit(0);
  }
  else if(pos == 1) {
    insertAtBeginning(num);
  }
  else if(pos == n + 1) {
    insertAtEnd(num);
  }
  else {
    
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->val = num;
    newNode->next = NULL;

    struct Node *node = head; 
    for(int i = 1; i < pos-1; ++i) {
      node = node->next;
    }
    newNode->next = node->next;
    node->next = newNode;

    printf("Successfully added %d at position %d!\n", newNode->val, pos);

    ++n;
  }

}

void printLinkedList() {
  printf("List: ");
  struct Node *node = NULL;
  node = head;
  while(node != NULL) {
    printf("%d -> ", node->val);
    node = node->next;
  }
  printf("\n");
}

void elementsInLinkedList() {
  printf("Numbers in List: %d\n", n);
}

void deleteAtBeginning() {
  struct Node *deleteNode = head;
  head = head->next;
  free(deleteNode);
  --n;
  
  printf("Successfully deleted first element!\n");

}

void deleteAtEnd() {

  struct Node *deleteNode = lastNode;
  lastNode = head;
  for(int i = 1; i < n - 1; ++i) {
    lastNode = lastNode->next;
  }
  lastNode->next = NULL;
  free(deleteNode);
  --n;

  printf("Successfully deleted last element!\n");

}

void deleteAtnthPos(int pos) {
  
  if(pos < 1 || pos > n) {
    printf("Can't delete at %d position : Invalid Input!\n", pos);
    deleteLinkedList();
    exit(0);
  }
  else if(pos == 1) {
    deleteAtBeginning();
  }
  else if(pos == n) {
    deleteAtEnd();
  }
  else {

    struct Node *prevNode = head;
    for(int i = 1; i < pos - 1; ++i) {
      prevNode = prevNode->next;
    }

    struct Node *deleteNode = prevNode->next;
    prevNode->next = prevNode->next->next;
    free(deleteNode);
    --n;
    printf("Successfully deleted %dth node!\n", pos);
  }

}

void deleteNode(int num) {

  struct Node *node = head;
  for(int i = 1; node != NULL; ++i) {
    if(node->val == num) {
      deleteAtnthPos(i);
      return;
    }
    node = node->next;
  }
  printf("Error: No such number found in list!\n");
}

// definition - test

void test() {
  // printf("%d %d %d %d", head, lastNode, newNode, sizeof(struct Node));
  
  printLinkedList();
  elementsInLinkedList();

  insertAtEnd(5);
  printLinkedList();
  elementsInLinkedList();

  insertAtEnd(9);
  printLinkedList();
  elementsInLinkedList();

  insertAtEnd(7);
  printLinkedList();
  elementsInLinkedList();

  insertAtnthPos(8, 3);
  printLinkedList();
  elementsInLinkedList();

  // printf(" %d \n", head->next->next->val);

  deleteAtBeginning();
  printLinkedList();
  elementsInLinkedList();

  deleteAtEnd();
  printLinkedList();
  elementsInLinkedList();

  insertAtnthPos(15, 1);
  printLinkedList();
  elementsInLinkedList();

  insertAtnthPos(4, 1);
  printLinkedList();
  elementsInLinkedList();

  insertAtBeginning(1);
  printLinkedList();
  elementsInLinkedList();

  insertAtBeginning(8);
  printLinkedList();
  elementsInLinkedList();

  deleteAtnthPos(5);
  printLinkedList();
  elementsInLinkedList();

  deleteAtnthPos(1);
  printLinkedList();
  elementsInLinkedList();

  deleteAtnthPos(4);
  printLinkedList();
  elementsInLinkedList();

  deleteNode(4);
  printLinkedList();
  elementsInLinkedList();

  deleteLinkedList();
  printLinkedList();
  elementsInLinkedList();
}