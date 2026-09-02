#include "../headers/data_element.h"
#include <stdio.h>

static dataElement items[CAPACITY];
static int top;

void init_261100690032() { top = -1; }

int isEmpty_261100690032() { return top == -1; }

int isFull_261100690032() { return top == CAPACITY - 1; }

/* push operation */
int push_261100690032(dataElement data) {
  if (isFull_261100690032()) {
    return FAILURE;
  }
  top = top + 1;
  items[top] = data;
  return 1;
}

/* pop operation */
dataElement pop_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }
  dataElement *data = items[top];
  top = top - 1;
  return data;
}

dataElement peak_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }
  return items[top];
}

void display_261100690032(void (*printFunc)(dataElement)) {
  if (isEmpty_261100690032()) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements (top to bottom): ");
  for (int i = top; i >= 0; i--) {
    printFunc(items[i]);
  }
  printf("\n");
}
