/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 * Assignment 03: Student Database using Stack (Array & LinkedList) and Queue (Array * LinkedList)
 */

#include <stdio.h>
#include "./headers/student.h"

#define NAME_FORMAT " %49[^\n]"
#define BRANCH_FORMAT " %19[^\n]"

static int readStudent(Student *student) {
    printf("Enter name: ");
    if (scanf(NAME_FORMAT, student->name) != 1) {
        return 0;
    }
    printf("Enter roll number: ");
    if (scanf("%d", &student->rollNumber) != 1) {
        return 0;
    }
    printf("Enter branch: ");
    if (scanf(BRANCH_FORMAT, student->branch) != 1) {
        return 0;
    }
    printf("Enter grade: ");
    if (scanf("%f", &student->grade) != 1) {
        return 0;
    }
    return 1;
}

void printStudent(const Student *student) {
    printf("%-20s %-10d %-15s %.2f\n", student->name, student->rollNumber, student->branch, student->grade);
}

static void handleInsert(void) {
    Student student;
    if (!readStudent(&student)) {
        printf("Invalid input\n");
        return;
    }
    if (insertStudent(student)) {
        printf("Inserted:\n");
        printStudent(&student);
    } else {
        printf("Overflow\n");
    }
}

static void handleRemove(void) {
    Student student;
    if (removeStudent(&student)) {
        printf("Removed:\n");
        printStudent(&student);
    } else {
        printf("Underflow\n");
    }
}

static void showMenu(void) {
    printf("\n1. Insert\n2. Remove\n3. Display\n4. Exit\nChoice: ");
}

int main(void) {
    int choice;

    init();

    do {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            break;
        }
        switch (choice) {
            case 1:
                handleInsert();
                break;
            case 2:
                handleRemove();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Bye\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
