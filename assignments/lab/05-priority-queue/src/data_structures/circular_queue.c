#include <stdio.h>
#include "../headers/queue.h"

static dataElement items[CAPACITY];
static int front;
static int count;

static int indexAt_261100690032(int offset) {
    return (front + offset) % CAPACITY;
}

void init_261100690032(void) {
    front = 0;
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

    int index = indexAt_261100690032(count);
    items[index] = data;
    count = count + 1;
    return SUCCESS;
}

dataElement dequeue_261100690032(void) {
    if (isEmpty_261100690032()) {
        return FAILURE;
    }

    dataElement data = items[front];
    front = indexAt_261100690032(1);
    count = count - 1;
    return data;
}

dataElement peak_261100690032(void) {
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
