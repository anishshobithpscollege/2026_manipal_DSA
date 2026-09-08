#include "./headers/priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

void printInteger_261100690032(dataElement ele, int priority) {
  int *val = (int *)ele;
  printf("%d(p%d) ", *val, priority);
}

static void handleInsert_261100690032(void) {
  int priority;
  int *data = malloc(sizeof(int));
  if (data == NULL) return;

  printf("Enter integer to insert: ");
  if (scanf("%d", data) != 1) {
    printf("Invalid input\n");
    free(data);
    return;
  }

  printf("Enter its priority (lower leaves first): ");
  if (scanf("%d", &priority) != 1) {
    printf("Invalid input\n");
    free(data);
    return;
  }

  if (insert_261100690032(data, priority) == SUCCESS) {
    printf("Inserted: %d with priority %d\n", *data, priority);
  } else {
    printf("Overflow\n");
    free(data);
  }
}

static void handleRemove_261100690032(void) {
  int priority;
  dataElement raw = removeHighest_261100690032(&priority);
  if (raw != NULL) {
    int *data = (int *)raw;
    printf("Removed: %d with priority %d\n", *data, priority);
    free(data);
  } else {
    printf("Underflow\n");
  }
}

static void handlePeak_261100690032(void) {
  int priority;
  dataElement raw = peak_261100690032(&priority);
  if (raw != NULL) {
    int *data = (int *)raw;
    printf("Value at peak is : %d with priority %d\n", *data, priority);
  } else {
    printf("Priority queue is empty\n");
  }
}

static void showMenu_261100690032(void) {
  printf("\n1. Insert\n2. Remove\n3. Peak\n4. Display\n5. Exit\nChoice: ");
}

int main(void) {
  int choice;
  init_261100690032();

  do {
    showMenu_261100690032();
    scanf("%d", &choice);
    switch (choice) {
      case 1: handleInsert_261100690032(); break;
      case 2: handleRemove_261100690032(); break;
      case 3: handlePeak_261100690032(); break;
      case 4:
        display_261100690032(printInteger_261100690032);
        break;
      case 5: printf("Bye\n"); break;
      default: printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}
