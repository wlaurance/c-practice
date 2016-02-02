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
  return 0;
}

void GetNthTest() {
  struct node* myList = BuildOneTwoThree();
  int lastNode = GetNth(myList, 2);
  assert(lastNode == 3);
}

int main() {
  CountTest();
  GetNthTest();
  return 0;
}
