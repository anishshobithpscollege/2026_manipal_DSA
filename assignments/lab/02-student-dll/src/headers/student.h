#ifndef STUDENT_H
#define STUDENT_H

#include "./dll.h"

#define STUDENT_NAME_LEN 50
#define STUDENT_COURSE_LEN 30

typedef struct Student {
    int id;
    char name[STUDENT_NAME_LEN];
    int age;
    char course[STUDENT_COURSE_LEN];
    float marks;
} Student;

void student_insert_front(DLL *list);
void student_insert_back(DLL *list);
void student_insert_at(DLL *list);
void student_update(DLL *list);
void student_delete(DLL *list);
void student_find(DLL *list);
void student_swap(DLL *list);
void student_print_all(const DLL *list);

#endif
