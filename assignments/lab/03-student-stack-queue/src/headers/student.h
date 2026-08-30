#ifndef STUDENT_H
#define STUDENT_H

#define CAPACITY 5
#define NAME_LENGTH 50
#define BRANCH_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int rollNumber;
    char branch[BRANCH_LENGTH];
    float grade;
} Student;

void init(void);
int isEmpty(void);
int isFull(void);

/* push for a stack, enqueue for a queue */
int insertStudent(Student student);
/* pop for a stack, dequeue for a queue */
int removeStudent(Student *student);
void display(void);
void printStudent(const Student *student);

#endif
