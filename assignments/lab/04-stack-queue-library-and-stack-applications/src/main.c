#include <stdio.h>
#include <stdlib.h>
#include "./headers/data_element.h"

void printInteger_261100690032(dataElement ele) {
    int *val = (int *)ele;
    printf("%d ", *val);
}

static void handleInsert_261100690032() {
    int *data = malloc(sizeof(int));
    if (data == NULL) return;

    printf("Enter integer to insert: ");
    if (scanf("%d", data) != 1) {
        printf("Invalid input\n");
        free(data);
        return;
    }

    if (push_261100690032(data) == SUCCESS) {
        printf("Inserted: %d\n", *data);
    } else {
        printf("Overflow\n");
        free(data);
    }
}

static void handleRemove_261100690032() {
    dataElement raw = pop_261100690032();
    if (raw != NULL) {
        int *data = (int *)raw;
        printf("Removed: %d\n", *data);
        free(data);
    } else {
        printf("Underflow\n");
    }
}

static void showMenu_261100690032(void) {
    printf("\n1. Insert\n2. Remove\n3. Display\n4. Exit\nChoice: ");
}

int main() {
    int choice;
    init_261100690032();

    do {
        showMenu_261100690032();
        scanf("%d", &choice);
        switch (choice) {
            case 1: handleInsert_261100690032(); break;
            case 2: handleRemove_261100690032(); break;
            case 3:
                display_261100690032(printInteger_261100690032);
                break;
            case 4: printf("Bye\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
