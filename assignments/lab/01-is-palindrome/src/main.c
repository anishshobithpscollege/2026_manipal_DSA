/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 * Assignment 01: Check if array of numbers if a palindrome.
 */
#include <stdio.h>
#include "./headers/palindrome.h"

int main(void) {
    assertPalindrome();

    int arr[MAX_ARRAY_SIZE];
    int n = 0;
    int choice = 0;

    do {
        printf("\nArray Palindrome Menu\n");
        printf("1. Enter array\n");
        printf("2. Display array\n");
        printf("3. Check palindrome\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = read_size_of_array();
                if (n < 1 || n > MAX_ARRAY_SIZE) {
                    printf("Size must be between 1 and %d.\n", MAX_ARRAY_SIZE);
                    n = 0;
                    break;
                }
                enter_array_elements(arr, n);
                break;
            case 2:
                if (n <= 0)
                    printf("No array yet. Start from option 1.\n");
                else
                    display_array_elements(arr, n);
                break;
            case 3:
                if (n <= 0) {
                    printf("No array yet. Start from option 1.\n");
                    break;
                }
                if (is_palindrome(arr, n) == IS_A_PALINDROME)
                    printf("\nThe array is a palindrome.\n");
                else
                    printf("\nThe array is not a palindrome.\n");
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("\nInvalid choice. Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
