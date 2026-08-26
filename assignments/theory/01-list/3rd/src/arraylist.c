#include <stdio.h>
#include <stdlib.h>
#include "../headers/student.h"

#define INITIAL_CAPACITY 8

static Student *items;
static int size;
static int capacity;

static int find_index(int roll) {
    for (int i = 0; i < size; i++)
        if (items[i].roll == roll) return i;

    return -1;
}

static int grow(void) {
    if (size < capacity) return STUDENT_OK;

    int expanded = capacity * 2;
    Student *resized = realloc(items, expanded * sizeof(Student));
    if (!resized) return STUDENT_FAIL;

    items = resized;
    capacity = expanded;
    return STUDENT_OK;
}

void store_init(void) {
    items = malloc(INITIAL_CAPACITY * sizeof(Student));
    size = 0;
    capacity = INITIAL_CAPACITY;
}

void store_free(void) {
    free(items);
    items = NULL;
    size = 0;
    capacity = 0;
}

int store_get(int roll, Student *out) {
    int index = find_index(roll);
    if (index < 0) return STUDENT_FAIL;

    *out = items[index];
    return STUDENT_OK;
}

int store_add(Student s) {
    if (find_index(s.roll) >= 0) return STUDENT_FAIL;
    if (!grow()) return STUDENT_FAIL;

    items[size++] = s;
    return STUDENT_OK;
}

int store_remove(int roll) {
    int index = find_index(roll);
    if (index < 0) return STUDENT_FAIL;

    for (int i = index; i < size - 1; i++)
        items[i] = items[i + 1];

    size--;
    return STUDENT_OK;
}

int store_update(int roll, Student s) {
    int index = find_index(roll);
    if (index < 0) return STUDENT_FAIL;
    if (s.roll != roll && find_index(s.roll) >= 0) return STUDENT_FAIL;

    items[index] = s;
    return STUDENT_OK;
}

void store_display(void) {
    if (size == 0) {
        printf("No records.\n");
        return;
    }

    printf("Roll\tName\tMarks\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%s\t%.2f\n", items[i].roll, items[i].name, items[i].marks);
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

    for (int i = 0; i < size; i++)
        fprintf(file, "%d,%s,%.2f\n", items[i].roll, items[i].name, items[i].marks);

    fclose(file);
    return STUDENT_OK;
}
