#ifndef PALINDROME_H
#define PALINDROME_H

#define SUCCESS 1
#define FAILURE 0

#define INVALID_INPUT -1
#define NOT_A_PALINDROME 0
#define IS_A_PALINDROME 1

#define MAX_ARRAY_SIZE 50

int read_size_of_array(void);
int enter_array_elements(int *arr, const int size_of_the_array);
void display_array_elements(const int *arr, int size_of_the_array);
int is_palindrome(const int *arr, int n);
void assertPalindrome(void);

#endif
