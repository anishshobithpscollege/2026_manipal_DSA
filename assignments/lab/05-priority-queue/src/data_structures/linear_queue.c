#include <stdio.h>
#include "../headers/queue.h"

static dataElement items[CAPACITY];
static int count;

void init_261100690032(void) {
    count = 0;
}

int isEmpty_261100690032(void) {
    return count == 0;
}

int isFull_261100690032(void) {
    return count == CAPACITY;
}

int enqueue_261100690032(dataElement data) {
    if (isFull_261100690032()) {
        printf("Queue Overflow\n");
        return FAILURE;
    }

    items[count] = data;
    count++;
    return SUCCESS;
}

dataElement dequeue_261100690032(void) {
    if (isEmpty_261100690032()) {
        return FAILURE;
    }
    dataElement data = items[0];
    for (int i = 1; i < count; i++) {
        items[i - 1] = items[i];
    }
    count -= 1;
    return data;
}

dataElement peak_261100690032(void) {
    if (isEmpty_261100690032()) {
        return FAILURE;
    }
    return items[0];
}

void display_261100690032(void (*printFunc)(dataElement)) {
    if (isEmpty_261100690032()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < count; i++) {
        printFunc(items[i]);
    }
    printf("\n");
}
