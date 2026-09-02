/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 * Assignment 04 - Application 3: Postfix Evaluation
 */

#include "../headers/common.h"
#include <ctype.h>
#include <stdio.h>

static void evaluatePostfix_261100690032() {
  char expr[100];

  printf("Enter a postfix expression (single digits, e.g. 23+4*): ");
  if (scanf("%99s", expr) != 1) {
    printf("Error: could not read input\n");
    return;
  }

  init_261100690032();

  int valid = 1;
  for (int i = 0; expr[i] != '\0'; i++) {
    char c = expr[i];

    if (isdigit((unsigned char)c)) {
      pushInt_261100690032(c - '0');
    } else if (isOperator_261100690032(c)) {
      int a, b, result;
      if (popInt_261100690032(&b) == FAILURE ||
          popInt_261100690032(&a) == FAILURE) {
        printf("Error: not enough operands\n");
        valid = 0;
        break;
      }
      if (applyOperator_261100690032(c, a, b, &result) == FAILURE) {
        valid = 0;
        break;
      }
      pushInt_261100690032(result);
    } else {
      printf("Error: invalid character '%c'\n", c);
      valid = 0;
      break;
    }
  }

  if (valid) {
    int result;
    if (popInt_261100690032(&result) == FAILURE) {
      printf("Error: empty expression\n");
    } else if (!isEmpty_261100690032()) {
      printf("Error: too many operands\n");
    } else {
      printf("Result = %d\n", result);
    }
  }

  clearStack_261100690032();
}

int main() {
  runMenu_261100690032("Postfix Evaluation", "Evaluate an expression",
                       evaluatePostfix_261100690032);
  return 0;
}
