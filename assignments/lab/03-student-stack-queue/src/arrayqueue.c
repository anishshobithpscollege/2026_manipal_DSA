#include <stdio.h>
#include "./headers/student.h"

static Student items[CAPACITY];
static int front;
static int count;

static int indexAt(int offset) {
    return (front + offset) % CAPACITY;
}

void init(void) {
    front = 0;
    count = 0;
}

int isEmpty(void) {
    return count == 0;
}

int isFull(void) {
    return count == CAPACITY;
}

/* enqueue operation */
int insertStudent(Student student) {
    if (isFull()) {
        return 0;
    }
    items[indexAt(count)] = student;
    count = count + 1;
    return 1;
}

/* dequeue operation */
int removeStudent(Student *student) {
    if (isEmpty()) {
        return 0;
    }
    *student = items[front];
    front = indexAt(1);
    count = count - 1;
    return 1;
}

void display(void) {
    int i;
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Front of queue:\n");
    for (i = 0; i < count; i++) {
        printStudent(&items[indexAt(i)]);
    }
}
