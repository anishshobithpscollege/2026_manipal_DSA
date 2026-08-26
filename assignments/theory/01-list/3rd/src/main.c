#include <stdio.h>
#include <string.h>
#include "../headers/student.h"

#define DATA_FILE "students.csv"

static int read_roll(const char *prompt) {
    int roll;
    printf("%s", prompt);
    scanf("%d", &roll);
    return roll;
}

static Student read_student(int roll) {
    Student s;
    s.roll = roll;

    printf("Name: ");
    getchar();
    fgets(s.name, STUDENT_NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Marks: ");
    scanf("%f", &s.marks);

    return s;
}

static void handle_add(void) {
    Student s = read_student(read_roll("Roll number: "));

    if (store_add(s)) printf("Student added.\n");
    else printf("Roll number already exists.\n");
}

static void handle_remove(void) {
    if (store_remove(read_roll("Roll number to remove: "))) printf("Student removed.\n");
    else printf("Student not found.\n");
}

static void handle_update(void) {
    int roll = read_roll("Roll number to update: ");
    Student existing;

    if (!store_get(roll, &existing)) {
        printf("Student not found.\n");
        return;
    }

    printf("Current: %d\t%s\t%.2f\n", existing.roll, existing.name, existing.marks);
    Student updated = read_student(read_roll("New roll number: "));

    if (store_update(roll, updated)) printf("Student updated.\n");
    else printf("New roll number already exists.\n");
}

static void handle_find(void) {
    Student s;

    if (store_get(read_roll("Roll number to find: "), &s))
        printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
    else
        printf("Student not found.\n");
}

static void print_menu(void) {
    printf("\n1. Add\n2. Remove\n3. Update\n4. Find\n5. Display all\n6. Save\n7. Exit\n");
}

int main(void) {
    store_init();

    if (store_load(DATA_FILE)) printf("Records loaded from %s\n", DATA_FILE);
    else printf("No existing records found.\n");

    int choice;
    do {
        print_menu();
        choice = read_roll("Choice: ");

        switch (choice) {
            case 1: handle_add(); break;
            case 2: handle_remove(); break;
            case 3: handle_update(); break;
            case 4: handle_find(); break;
            case 5: store_display(); break;
            case 6:
                if (store_save(DATA_FILE)) printf("Saved to %s\n", DATA_FILE);
                else printf("Save failed.\n");
                break;
            case 7:
                if (store_save(DATA_FILE)) printf("Saved to %s\n", DATA_FILE);
                else printf("Save failed.\n");
                break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    store_save(DATA_FILE);
    store_free();
    return 0;
}
