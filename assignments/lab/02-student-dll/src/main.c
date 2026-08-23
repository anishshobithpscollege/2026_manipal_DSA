/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 * Assignment 02: Student Database using Double Linked List.
 */

#include <stdio.h>
#include "./headers/student.h"

static void print_menu(void) {
    printf("\n===== STUDENT DATABASE =====\n");
    printf("1. Insert student at front\n");
    printf("2. Insert student at end\n");
    printf("3. Insert student at a given position\n");
    printf("4. Update student\n");
    printf("5. Delete student\n");
    printf("6. Find student\n");
    printf("7. Swap two students\n");
    printf("8. Print all students\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    assertDLL(); // Run assertions before we begin
    DLL *list = dll_create();

    if (list == NULL) {
        printf("Failed to create the list.\n");
        return 1;
    }

    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: student_insert_front(list); break;
            case 2: student_insert_back(list); break;
            case 3: student_insert_at(list); break;
            case 4: student_update(list); break;
            case 5: student_delete(list); break;
            case 6: student_find(list); break;
            case 7: student_swap(list); break;
            case 8: student_print_all(list); break;
            case 9: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}
