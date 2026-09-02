#include "../headers/data_element.h"
#include <stdio.h>

static dataElement items[CAPACITY];
static int front;
static int count;

static int indexAt_261100690032(int offset) {
  return (front + offset) % CAPACITY;
}

void init_261100690032() {
  front = 0;
  count = 0;
}

int isEmpty_261100690032() { return count == 0; }

int isFull_261100690032() { return count == CAPACITY; }

/* enqueue operation */
int push_261100690032(dataElement data) {
  if (isFull_261100690032()) {
    return FAILURE;
  }
  int index = indexAt_261100690032(count);
  items[index] = data;
  count = count + 1;
  return SUCCESS;
}

/* dequeue operation */
dataElement pop_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }
  dataElement data = items[front];
  front = indexAt_261100690032(1);
  count = count - 1;
  return data;
}

dataElement peak_261100690032() {
  if (isEmpty_261100690032()) {
    return FAILURE;
  }
  return items[front];
}

void display_261100690032(void (*printFunc)(dataElement)) {
  if (isEmpty_261100690032()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  for (int i = 0; i < count; i++) {
    int index = indexAt_261100690032(i);
    printFunc(items[index]);
  }
  printf("\n");
}
