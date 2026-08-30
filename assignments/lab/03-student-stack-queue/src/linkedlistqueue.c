#include <stdio.h>
#include <stdlib.h>
#include "./headers/student.h"

typedef struct Node {
    Student student;
    struct Node *next;
} Node;

static Node *front;
static Node *tail;

void init(void) {
    front = NULL;
    tail = NULL;
}

int isEmpty(void) {
    return front == NULL;
}

int isFull(void) {
    return 0;
}

/* enqueue operation */
int insertStudent(Student student) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    node->student = student;
    node->next = NULL;
    if (isEmpty()) {
        front = node;
    } else {
        tail->next = node;
    }
    tail = node;
    return 1;
}

/* dequeue operation */
int removeStudent(Student *student) {
    Node *node;
    if (isEmpty()) {
        return 0;
    }
    node = front;
    *student = node->student;
    front = node->next;
    if (front == NULL) {
        tail = NULL;
    }
    free(node);
    return 1;
}

void display(void) {
    Node *current;
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Front of queue:\n");
    for (current = front; current != NULL; current = current->next) {
        printStudent(&current->student);
    }
}
