#ifndef STUDENT_H
#define STUDENT_H

#define STUDENT_OK 1
#define STUDENT_FAIL 0
#define STUDENT_NAME_LEN 64

typedef struct Student {
    int roll;
    char name[STUDENT_NAME_LEN];
    float marks;
} Student;

void store_init(void);
void store_free(void);

int store_add(Student s);
int store_remove(int roll);
int store_update(int roll, Student s);
int store_get(int roll, Student *out);
void store_display(void);

int store_load(const char *path);
int store_save(const char *path);

#endif
