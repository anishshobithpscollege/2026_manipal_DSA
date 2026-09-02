#include "../headers/data_element.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  dataElement data;
  struct Node *next;
} Node;

Node *top;

void init_261100690032() { top = NULL; }

int isEmpty_261100690032() { return top == NULL; }

int isFull_261100690032() { return 0; }

/* push operation */
int push_261100690032(dataElement data) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL) {
    return FAILURE;
  }
  node->data = data;
  node->next = top;
  top = node;
  return 1;
}

/* pop operation */
dataElement pop_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }
  Node *node = top;
  dataElement *data = node->data;
  top = node->next;
  free(node);
  return data;
}

dataElement peak_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }

  return top->data;
}

void display_261100690032(void (*printFunc)(dataElement)) {
  if (isEmpty_261100690032()) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements (top to bottom): ");
  Node *current = top;
  while (current != NULL) {
    printFunc(current->data);
    current = current->next;
  }
  printf("\n");
}
