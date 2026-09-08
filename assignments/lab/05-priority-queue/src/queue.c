#include <stdio.h>
#include <stdlib.h>
#include "./headers/queue.h"

void printInteger_261100690032(dataElement ele) {
    int *val = (int *)ele;
    printf("%d ", *val);
}

static void handleInsert_261100690032(void) {
    int *data = malloc(sizeof(int));
    if (data == NULL) return;

    printf("Enter integer to insert: ");
    if (scanf("%d", data) != 1) {
        printf("Invalid input\n");
        free(data);
        return;
    }

    if (enqueue_261100690032(data) == SUCCESS) {
        printf("Inserted: %d\n", *data);
    } else {
        printf("Overflow\n");
        free(data);
    }
}

static void handleRemove_261100690032(void) {
    dataElement raw = dequeue_261100690032();
    if (raw != NULL) {
        int *data = (int *)raw;
        printf("Removed: %d\n", *data);
        free(data);
    } else {
        printf("Underflow\n");
    }
}

static void handlePeak_261100690032(void) {
    dataElement raw = peak_261100690032();
    if (raw != NULL) {
        int *data = (int *)raw;
        printf("Value at peak is : %d\n", *data);
    } else {
        printf("Queue is empty\n");
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
