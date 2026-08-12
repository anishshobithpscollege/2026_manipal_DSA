#include "./headers/palindrome.h"
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

int read_size_of_array(void) {
    int n = 0;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    return n;
}

int enter_array_elements(int *arr, const int n) {
    if (arr == NULL || n <= 0) return FAILURE;

    for (int i = 0; i < n; i++) {
        printf("Array element arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    return SUCCESS;
}

void display_array_elements(const int *arr, int n) {
    if (arr == NULL) {
        printf("Invalid Array\n");
        return;
    }

    if (n <= 0) {
        printf("Array is empty. Enter an array first.\n");
        return;
    }

    printf("\nArray elements are : ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], i < n - 1 ? " " : "\n");
    }
}

/**
 * Checks whether an array is a palindrome, using the two pointer method.
 * @input arr - array to check.
 * @input n   - size of the array.
 * @return IS_A_PALINDROME, NOT_A_PALINDROME, or INVALID_INPUT.
 */
int is_palindrome(const int *arr, int n) {

    // Reject a null array or a non-positive size as invalid input.
    if (arr == NULL || n <= 0) return INVALID_INPUT;

    // Two indices walk inward from the ends of the array.
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // A single mismatched pair means it is not a palindrome.
        if (arr[left] != arr[right]) return NOT_A_PALINDROME;

        left++;
        right--;
    }

    return IS_A_PALINDROME;
}

void assertPalindrome(void) {
    int *null_arr = NULL;
    int single[1] = {7};
    int two_same[2] = {5, 5};
    int two_diff[2] = {5, 9};
    int odd_pal[5] = {1, 2, 3, 2, 1};
    int even_pal[4] = {4, 3, 3, 4};
    int not_pal[4] = {1, 2, 3, 4};
    int neg_pal[3] = {-1, 0, -1};
    int neg_not_pal[3] = {-1, 0, 1};
    int near_pal[5] = {1, 2, 3, 2, 9};

    assert(is_palindrome(null_arr, 0) == INVALID_INPUT);
    assert(is_palindrome(null_arr, 5) == INVALID_INPUT);
    assert(is_palindrome(single, 0) == INVALID_INPUT);
    assert(is_palindrome(single, -1) == INVALID_INPUT);

    assert(is_palindrome(single, 1) == IS_A_PALINDROME);
    assert(is_palindrome(two_same, 2) == IS_A_PALINDROME);
    assert(is_palindrome(odd_pal, 5) == IS_A_PALINDROME);
    assert(is_palindrome(even_pal, 4) == IS_A_PALINDROME);
    assert(is_palindrome(neg_pal, 3) == IS_A_PALINDROME);

    assert(is_palindrome(two_diff, 2) == NOT_A_PALINDROME);
    assert(is_palindrome(not_pal, 4) == NOT_A_PALINDROME);
    assert(is_palindrome(neg_not_pal, 3) == NOT_A_PALINDROME);
    assert(is_palindrome(near_pal, 5) == NOT_A_PALINDROME);
}
