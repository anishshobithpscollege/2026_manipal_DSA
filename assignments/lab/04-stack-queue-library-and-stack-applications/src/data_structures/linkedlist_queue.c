#include "../headers/data_element.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  dataElement data;
  struct Node *next;
} Node;

Node *head;
Node *tail;

void init_261100690032() {
  head = NULL;
  tail = NULL;
}

int isEmpty_261100690032() { return head == NULL; }

int isFull_261100690032() { return 0; }

/* enqueue operation */
int push_261100690032(dataElement data) {
  Node *node = malloc(sizeof(Node));

  if (node == NULL) {
    return FAILURE;
  }

  node->data = data;
  node->next = NULL;

  if (isEmpty_261100690032()) {
    head = node;
  } else {
    tail->next = node;
  }
  tail = node;

  return SUCCESS;
}

/* dequeue operation */
dataElement pop_261100690032() {
  if (isEmpty_261100690032()) {
    return NULL;
  }

  Node *node = head;
  dataElement *data = node->data;
  head = node->next;

  if (head == NULL) {
    tail = NULL;
  }

  free(node);
  return data;
}

dataElement peak_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }
  return head->data;
}

void display_261100690032(void (*printFunc)(dataElement)) {
  if (isEmpty_261100690032()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  Node *current = head;
  while (current != NULL) {
    printFunc(current->data);
    current = current->next;
  }
  printf("\n");
}
