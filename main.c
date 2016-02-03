#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node {
  int data;
  struct node* next;
};

int Length(struct node* head) {
  int count = 0;
  struct node* current = head;
  while (current != NULL) {
    count++;
    current=current->next;
  }
  return(count);
}
// Given a reference (pointer to pointer) to the head
// of a list and an int, push a new node on the front of the list.
// Creates a new node with the int, links the list off the .next of the
// new node, and finally changes the head to point to the new node.
void Push(struct node** headRef, int newData) {
  struct node* newNode = (struct node*) malloc(sizeof(struct node)); // allocate node
  newNode->data = newData;// put in the data
  newNode->next = (*headRef);// link the old list off the new node
  (*headRef) = newNode;// move the head to point to the new node
}
// Build and return the list {1, 2, 3}
struct node* BuildOneTwoThree() {
  struct node* head = NULL;// Start with the empty list
  Push(&head, 3);// Use Push() to add all the data
  Push(&head, 2);
  Push(&head, 1);
  return(head);
}

// Visualize Linked List
void Visualize(struct node* head) {
  struct node* current = head;
  while (current != NULL) {
    printf("%d-->", current->data);
    current=current->next;
  }
  printf("NULL\n");
}

//1 - Count()
//Builds a list and counts the number of times a given int occurs
int Count(struct node* head, int search) {
  int count = 0;
  struct node* current = head;
  while(current != NULL) {
    if (current->data == search) { count++; }
    current = current->next;
  }
  return count;
}

void CountTest() {
  struct node* list;
  list = BuildOneTwoThree();
  int count = Count(list, 2);
  assert(count == 1);
}
//2 -GetNth()
//Write a GetNth() function that takes a linked list and an integer index and
//returns the data value stored in the node at that index position.
int GetNth(struct node* head, int index) {
  assert(index < Length(head));
  struct node* current = head;
  while(current != NULL && index-- != 0) {
    current = current->next;
  }
  return current->data;
}

void GetNthTest() {
  struct node* myList = BuildOneTwoThree();
  int lastNode = GetNth(myList, 2);
  assert(lastNode == 3);
}
//3 - DeleteList()
//Write a func that takes a list, deallocates all of its memory and sets its head
//pointer to NULL
void DeleteList(struct node** headRef) {
  struct node* current = *headRef;
  struct node* next;
  while(current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *headRef = NULL;
}
void DeleteListTest() {
  struct node* myList = BuildOneTwoThree();
  DeleteList(&myList);
  assert(myList == NULL);
}

//4 - Pop()
//function is inverse of pop. pop takes a non empty list, deletes the head node,
//and returns the head node's data.
int Pop(struct node** headRef) {
  assert(Length(*headRef) > 0);
  struct node* current = *headRef;
  assert(current != NULL);
  int value = current->data;
  *headRef = current->next;
  free(current);
  return value;
}

void PopTest() {
  struct node* head = BuildOneTwoThree();// build {1, 2, 3}
  int a = Pop(&head);// deletes "1" node and returns 1
  assert(a==1);
  int b = Pop(&head);// deletes "2" node and returns 2
  assert(b==2);
  int c = Pop(&head);// deletes "3" node and returns 3
  assert(c==3);
  int len = Length(head);// the list is now empty, so len == 0
  assert(len == 0);
}

//5 - InserNth()
//insert a new node at any index within a list. Push() is similar,
//but can only insert a node at the head of a list.
void InsertNth(struct node** headRef, int index, int value) {
  assert(index < Length(*headRef) + 1);
  struct node* curr = *headRef;
  int i = 0;
  while (++i < index) {
    curr = curr->next;
  }
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = value;
  if (curr == NULL) {
    *headRef = newNode;
  } else {
    newNode->next = curr->next;
    curr->next = newNode;
  }
}
void InsertNthTest() {
  struct node* head = NULL;
  Visualize(head);
  InsertNth(&head, 0, 13);
  Visualize(head);
  InsertNth(&head, 1, 42);
  Visualize(head);
  InsertNth(&head, 1, 5);
  assert(Length(head) == 3);
  Visualize(head);
  DeleteList(&head);
}
int main() {
  CountTest();
  GetNthTest();
  DeleteListTest();
  PopTest();
  InsertNthTest();
  return 0;
}
