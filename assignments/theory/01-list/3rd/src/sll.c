#include <stdio.h>
#include <stdlib.h>
#include "../headers/student.h"

typedef struct Node {
    Student data;
    struct Node *next;
} Node;

static Node *head;
static Node *tail;
static int size;

static Node *find_node(int roll) {
    for (Node *current = head; current; current = current->next)
        if (current->data.roll == roll) return current;

    return NULL;
}

void store_init(void) {
    head = NULL;
    tail = NULL;
    size = 0;
}

void store_free(void) {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    store_init();
}

int store_get(int roll, Student *out) {
    Node *node = find_node(roll);
    if (!node) return STUDENT_FAIL;

    *out = node->data;
    return STUDENT_OK;
}

int store_add(Student s) {
    if (find_node(s.roll)) return STUDENT_FAIL;

    Node *node = malloc(sizeof(Node));
    if (!node) return STUDENT_FAIL;

    node->data = s;
    node->next = NULL;

    if (tail) tail->next = node;
    else head = node;

    tail = node;
    size++;
    return STUDENT_OK;
}

int store_remove(int roll) {
    Node *prev = NULL;
    Node *current = head;

    while (current && current->data.roll != roll) {
        prev = current;
        current = current->next;
    }

    if (!current) return STUDENT_FAIL;

    if (prev) prev->next = current->next;
    else head = current->next;

    if (tail == current) tail = prev;

    free(current);
    size--;
    return STUDENT_OK;
}

int store_update(int roll, Student s) {
    Node *node = find_node(roll);
    if (!node) return STUDENT_FAIL;
    if (s.roll != roll && find_node(s.roll)) return STUDENT_FAIL;

    node->data = s;
    return STUDENT_OK;
}

void store_display(void) {
    if (size == 0) {
        printf("No records.\n");
        return;
    }

    printf("Roll\tName\tMarks\n");
    for (Node *current = head; current; current = current->next)
        printf("%d\t%s\t%.2f\n", current->data.roll, current->data.name, current->data.marks);
}

int store_load(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) return STUDENT_FAIL;

    Student s;
    while (fscanf(file, "%d,%63[^,],%f\n", &s.roll, s.name, &s.marks) == 3)
        store_add(s);

    fclose(file);
    return STUDENT_OK;
}

int store_save(const char *path) {
    FILE *file = fopen(path, "w");
    if (!file) return STUDENT_FAIL;

    for (Node *current = head; current; current = current->next)
        fprintf(file, "%d,%s,%.2f\n", current->data.roll, current->data.name, current->data.marks);

    fclose(file);
    return STUDENT_OK;
}
