#include "../headers/priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  dataElement data;
  int priority;
  struct Node *next;
} Node;

static Node *head;

void init_261100690032(void) { head = NULL; }

int isEmpty_261100690032(void) { return head == NULL; }

int isFull_261100690032(void) { return 0; }

/* insert operation, keeps the list sorted by priority */
int insert_261100690032(dataElement data, int priority) {
  Node *node = malloc(sizeof(Node));
  if (node == NULL) {
    return FAILURE;
  }
  node->data = data;
  node->priority = priority;

  if (head == NULL || priority < head->priority) {
    node->next = head;
    head = node;
    return SUCCESS;
  }

  Node *current = head;
  while (current->next != NULL && current->next->priority <= priority) {
    current = current->next;
  }
  node->next = current->next;
  current->next = node;
  return SUCCESS;
}

/* remove operation, always the head */
dataElement removeHighest_261100690032(int *priority) {
  if (isEmpty_261100690032()) {
    return NULL;
  }

  Node *node = head;
  dataElement data = node->data;
  if (priority != NULL) {
    *priority = node->priority;
  }

  head = node->next;
  free(node);
  return data;
}

dataElement peak_261100690032(int *priority) {
  if (isEmpty_261100690032()) {
    return NULL;
  }
  if (priority != NULL) {
    *priority = head->priority;
  }
  return head->data;
}

void display_261100690032(void (*printFunc)(dataElement, int)) {
  if (isEmpty_261100690032()) {
    printf("Priority queue is empty\n");
    return;
  }
  printf("List from highest priority: ");
  for (Node *current = head; current != NULL; current = current->next) {
    printFunc(current->data, current->priority);
  }
  printf("\n");
}
