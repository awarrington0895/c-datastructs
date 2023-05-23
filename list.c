#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* newNode(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = value;
  node->next = NULL;

  return node;
}

typedef struct {
  Node* head;
} LinkedList;

LinkedList* newList() {
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

  list->head = NULL;

  return list;
}

void push(int value, LinkedList* list) {
  Node* node = newNode(value);

  node->next = list->head;

  list->head = node;
}

void append(int value, LinkedList* list) {
  Node* node = newNode(value);

  Node* last = list->head;

  if (last == NULL) {
    list->head = node;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = node;
}

int pop(LinkedList* list) {
  if (list == NULL || list->head == NULL) {
    printf("Underflow!\nProgram Terminated\n");
    exit(EXIT_FAILURE);
  }

  Node* previousHead = list->head;
  int previousValue = previousHead->data;

  list->head = list->head->next;

  free(previousHead);

  return previousValue;
}

bool contains(int needle, const LinkedList* list) {
  if (list == NULL || list->head == NULL) {
    return false;
  }

  Node* current = list->head;
  
  while (current != NULL) {
    if (current->data == needle) {
      return true;
    }

    current = current->next;
  }

  return false;
}

Node* lastItem(const LinkedList* list) {
  if (list == NULL || list->head == NULL) {
    return NULL;
  }

  Node* last = list->head;
  Node* next = last->next;

  while (next != NULL) {
    last = next;

    next = last->next;
  }

  return last;
}

LinkedList* concat(LinkedList* a, LinkedList* b) {
  if (a == NULL || a->head == NULL) {
    if (b == NULL || b->head == NULL) {
      return NULL; 
    }

    return b;
  }

  Node* last = lastItem(a);

  last->next = b->head;

  return a;
}

void printList(const LinkedList* list) {
  Node* current = list->head;

  printf("[");

  while (current != NULL) {
    if (current->next == NULL) {
      printf("%d", current->data);
    } else {
      printf("%d, ", current->data);
    }

    current = current->next;
  }

  printf("]\n");
}

void printNode(const Node* node) {
  if (node == NULL) {
    printf("NULL\n");
  }

  printf("Node { ");
  printf("data = %d, ", node->data);
  printf("next = %p }\n", (void*)node->next);
}

int main(void) {
  LinkedList* list = newList();

  LinkedList* l2 = newList();

  push(10, list);
  push(20, list);
  push(30, list);

  push(1, list);

  push(2, list);

  push(5, list);

  printList(concat(list, l2));

  // printf("List contains 5? %d\n", contains(5, list));


  // printList(list);
  //
  // pop(list);
  //
  // printList(list);
  //
  // printf("List contains 5? %d\n", contains(5, list));
}
