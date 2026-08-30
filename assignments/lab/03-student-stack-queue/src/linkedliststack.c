#include <stdio.h>
#include <stdlib.h>
#include "./headers/student.h"

typedef struct Node {
    Student student;
    struct Node *next;
} Node;

static Node *top;

void init(void) {
    top = NULL;
}

int isEmpty(void) {
    return top == NULL;
}

int isFull(void) {
    return 0;
}

/* push operation */
int insertStudent(Student student) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    node->student = student;
    node->next = top;
    top = node;
    return 1;
}

/* pop operation */
int removeStudent(Student *student) {
    Node *node;
    if (isEmpty()) {
        return 0;
    }
    node = top;
    *student = node->student;
    top = node->next;
    free(node);
    return 1;
}

void display(void) {
    Node *current;
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    printf("Top of stack:\n");
    for (current = top; current != NULL; current = current->next) {
        printStudent(&current->student);
    }
}
