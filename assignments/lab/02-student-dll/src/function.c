#include <stdio.h>
#include <stdlib.h>
#include "./headers/student.h"

static DLLNode *find_node(const DLL *list, int id) {
    for (DLLNode *node = list->head; node != NULL; node = node->next) {
        Student *student = node->data;

        if (student->id == id) {
            return node;
        }
    }

    return NULL;
}

static int read_id(const char *prompt) {
    int id;

    printf("%s", prompt);
    scanf("%d", &id);

    return id;
}

static Student *prepare_student(const DLL *list) {
    int id = read_id("Enter Student ID: ");

    if (find_node(list, id) != NULL) {
        printf("Student with ID %d already exists.\n", id);
        return NULL;
    }

    Student *student = malloc(sizeof(Student));

    if (student == NULL) {
        printf("Out of memory.\n");
        return NULL;
    }

    student->id = id;

    printf("Enter Name: ");
    scanf(" %[^\n]", student->name);

    printf("Enter Age: ");
    scanf("%d", &student->age);

    printf("Enter Course: ");
    scanf(" %[^\n]", student->course);

    printf("Enter Marks: ");
    scanf("%f", &student->marks);

    return student;
}

static void finish_insert(Student *student, int result, const char *where) {
    if (result == DLL_FAIL) {
        printf("Out of memory. Could not insert student.\n");
        free(student);
        return;
    }

    printf("Student %d inserted %s.\n", student->id, where);
}

static void print_header(void) {
    printf("\n%-8s%-20s%-6s%-15s%-8s\n", "ID", "Name", "Age", "Course", "Marks");
    printf("--------------------------------------------------------\n");
}

static void print_row(const Student *student) {
    printf("%-8d%-20s%-6d%-15s%-8.2f\n", student->id, student->name,
           student->age, student->course, student->marks);
}

void student_insert_front(DLL *list) {
    Student *student = prepare_student(list);

    if (student == NULL) {
        return;
    }

    finish_insert(student, dll_push_front(list, student), "at the front");
}

void student_insert_back(DLL *list) {
    Student *student = prepare_student(list);

    if (student == NULL) {
        return;
    }

    finish_insert(student, dll_push_back(list, student), "at the end");
}

void student_insert_at(DLL *list) {
    int position;

    printf("Enter the position (1 = start): ");
    scanf("%d", &position);

    if (position < 1 || (size_t)position > list->size + 1) {
        printf("Invalid position.\n");
        return;
    }

    Student *student = prepare_student(list);

    if (student == NULL) {
        return;
    }

    finish_insert(student, dll_insert_at(list, position - 1, student), "successfully");
}

void student_update(DLL *list) {
    DLLNode *node = find_node(list, read_id("Enter the student id to modify: "));

    if (node == NULL) {
        printf("Student not found.\n");
        return;
    }

    Student *student = node->data;
    int choice;

    do {
        printf("\n1. Name\n2. Age\n3. Course\n4. Marks\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new name: ");
                scanf(" %[^\n]", student->name);
                break;
            case 2:
                printf("Enter the new age: ");
                scanf("%d", &student->age);
                break;
            case 3:
                printf("Enter the new course: ");
                scanf(" %[^\n]", student->course);
                break;
            case 4:
                printf("Enter the new marks: ");
                scanf("%f", &student->marks);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

void student_delete(DLL *list) {
    DLLNode *node = find_node(list, read_id("Enter Student ID to delete: "));

    if (node == NULL) {
        printf("Student not found.\n");
        return;
    }

    Student *student = node->data;

    dll_unlink(list, node);
    free(student);

    printf("Student record deleted successfully.\n");
}

void student_find(DLL *list) {
    DLLNode *node = find_node(list, read_id("Enter Student ID to search: "));

    if (node == NULL) {
        printf("Student not found.\n");
        return;
    }

    print_header();
    print_row(node->data);
}

void student_swap(DLL *list) {
    int first_id = read_id("Enter the first student id: ");
    int second_id = read_id("Enter the second student id: ");

    if (first_id == second_id) {
        printf("Both ids are the same. Nothing to swap.\n");
        return;
    }

    DLLNode *first = find_node(list, first_id);
    DLLNode *second = find_node(list, second_id);

    if (first == NULL || second == NULL) {
        printf("One or both students were not found.\n");
        return;
    }

    dll_swap(first, second);

    printf("Swapped students %d and %d.\n", first_id, second_id);
}

void student_print_all(const DLL *list) {
    if (list->size == 0) {
        printf("The list is empty.\n");
        return;
    }

    print_header();

    for (DLLNode *node = list->head; node != NULL; node = node->next) {
        print_row(node->data);
    }
}
