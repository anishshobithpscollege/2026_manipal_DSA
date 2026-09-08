#include "../headers/priority_queue.h"
#include <stdio.h>

typedef struct Entry {
  dataElement data;
  int priority;
} Entry;

static Entry items[CAPACITY];
static int count;

static int parentOf_261100690032(int i) { return (i - 1) / 2; }

static int leftOf_261100690032(int i) { return 2 * i + 1; }

static int rightOf_261100690032(int i) { return 2 * i + 2; }

static void swap_261100690032(int a, int b) {
  Entry temp = items[a];
  items[a] = items[b];
  items[b] = temp;
}

/* Walk a new entry up until its parent is at least as urgent. */
static void heapifyUp_261100690032(int index) {
  while (index > 0) {
    int parent = parentOf_261100690032(index);
    if (items[parent].priority <= items[index].priority) {
      break;
    }
    swap_261100690032(parent, index);
    index = parent;
  }
}

/* Walk the moved last entry down until both children are less urgent. */
static void heapifyDown_261100690032(int index) {
  while (1) {
    int smallest = index;
    int left = leftOf_261100690032(index);
    int right = rightOf_261100690032(index);

    if (left < count && items[left].priority < items[smallest].priority) {
      smallest = left;
    }
    if (right < count && items[right].priority < items[smallest].priority) {
      smallest = right;
    }
    if (smallest == index) {
      break;
    }

    swap_261100690032(index, smallest);
    index = smallest;
  }
}

void init_261100690032(void) { count = 0; }

int isEmpty_261100690032(void) { return count == 0; }

int isFull_261100690032(void) { return count == CAPACITY; }

/* insert operation */
int insert_261100690032(dataElement data, int priority) {
  if (isFull_261100690032()) {
    return FAILURE;
  }

  items[count].data = data;
  items[count].priority = priority;
  heapifyUp_261100690032(count);
  count = count + 1;
  return SUCCESS;
}

/* remove operation, always the root */
dataElement removeHighest_261100690032(int *priority) {
  if (isEmpty_261100690032()) {
    return NULL;
  }

  dataElement data = items[0].data;
  if (priority != NULL) {
    *priority = items[0].priority;
  }

  count = count - 1;
  items[0] = items[count];
  heapifyDown_261100690032(0);
  return data;
}

dataElement peak_261100690032(int *priority) {
  if (isEmpty_261100690032()) {
    return NULL;
  }
  if (priority != NULL) {
    *priority = items[0].priority;
  }
  return items[0].data;
}

void display_261100690032(void (*printFunc)(dataElement, int)) {
  if (isEmpty_261100690032()) {
    printf("Priority queue is empty\n");
    return;
  }
  printf("Heap in level order: ");
  for (int i = 0; i < count; i++) {
    printFunc(items[i].data, items[i].priority);
  }
  printf("\n");
}
