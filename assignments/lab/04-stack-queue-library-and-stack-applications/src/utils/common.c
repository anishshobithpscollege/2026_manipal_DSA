/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 */

#include "../headers/common.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void runMenu_261100690032(const char *title, const char *action_label,
                          void (*action)(void)) {
  int choice;
  do {
    printf("\n%s\n", title);
    printf("1. %s\n", action_label);
    printf("2. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input\n");
      break;
    }

    if (choice == 1) {
      action();
    } else if (choice == 2) {
      printf("Bye\n");
    } else {
      printf("Invalid choice\n");
    }
  } while (choice != 2);
}

void clearStack_261100690032(void) {
  dataElement box;
  while ((box = pop_261100690032()) != NULL) {
    free(box);
  }
}

int pushInt_261100690032(int value) {
  int *box = malloc(sizeof(int));
  if (box == NULL) {
    return FAILURE;
  }
  *box = value;
  if (push_261100690032(box) == FAILURE) {
    free(box);
    return FAILURE;
  }
  return SUCCESS;
}

int popInt_261100690032(int *out) {
  int *box = pop_261100690032();
  if (box == NULL) {
    return FAILURE;
  }
  *out = *box;
  free(box);
  return SUCCESS;
}

int peekInt_261100690032(int *out) {
  int *box = peak_261100690032();
  if (box == NULL) {
    return FAILURE;
  }
  *out = *box;
  return SUCCESS;
}

int isOpening_261100690032(char c) { return c == '(' || c == '{' || c == '['; }

int isClosing_261100690032(char c) { return c == ')' || c == '}' || c == ']'; }

int isMatchingPair_261100690032(char open, char close) {
  return (open == '(' && close == ')') || (open == '{' && close == '}') ||
         (open == '[' && close == ']');
}

int isOperator_261100690032(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence_261100690032(char c) {
  if (c == '^') {
    return 3;
  }
  if (c == '*' || c == '/') {
    return 2;
  }
  if (c == '+' || c == '-') {
    return 1;
  }
  return 0;
}

int shouldPopOperator_261100690032(char top, char c) {
  if (top == '(') {
    return 0;
  }
  if (precedence_261100690032(top) > precedence_261100690032(c)) {
    return 1;
  }
  if (precedence_261100690032(top) == precedence_261100690032(c) && c != '^') {
    return 1;
  }
  return 0;
}

int applyOperator_261100690032(char op, int a, int b, int *result) {
  if (op == '+') {
    *result = a + b;
    return SUCCESS;
  }
  if (op == '-') {
    *result = a - b;
    return SUCCESS;
  }
  if (op == '*') {
    *result = a * b;
    return SUCCESS;
  }
  if (op == '/') {
    if (b == 0) {
      printf("Error: division by zero\n");
      return FAILURE;
    }
    *result = a / b;
    return SUCCESS;
  }
  if (op == '^') {
    *result = (int)round(pow(a, b));
    return SUCCESS;
  }
  return FAILURE;
}
