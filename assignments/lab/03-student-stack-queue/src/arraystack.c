#include <stdio.h>
#include "./headers/student.h"

static Student items[CAPACITY];
static int top;

void init(void) {
    top = -1;
}

int isEmpty(void) {
    return top == -1;
}

int isFull(void) {
    return top == CAPACITY - 1;
}

/* push operation */
int insertStudent(Student student) {
    if (isFull()) {
        return 0;
    }
    top = top + 1;
    items[top] = student;
    return 1;
}

/* pop operation */
int removeStudent(Student *student) {
    if (isEmpty()) {
        return 0;
    }
    *student = items[top];
    top = top - 1;
    return 1;
}

void display(void) {
    int i;
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Top of stack:\n");
    for (i = top; i >= 0; i--) {
        printStudent(&items[i]);
    }
}
