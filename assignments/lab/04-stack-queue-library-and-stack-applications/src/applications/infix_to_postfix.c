/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 * Assignment 04 - Application 2: Infix to Postfix
 */

#include "../headers/common.h"
#include <ctype.h>
#include <stdio.h>

static void convertToPostfix_261100690032() {
  char infix[100];
  char postfix[100];
  int p = 0;

  printf("Enter an infix expression: ");
  if (scanf("%99s", infix) != 1) {
    printf("Error: could not read input\n");
    return;
  }

  init_261100690032();

  int ok = 1;
  for (int i = 0; infix[i] != '\0'; i++) {
    char c = infix[i];

    if (isalnum((unsigned char)c)) {
      postfix[p++] = c;
    } else if (c == '(') {
      pushInt_261100690032(c);
    } else if (c == ')') {
      int top;
      while (popInt_261100690032(&top) == SUCCESS && top != '(') {
        postfix[p++] = top;
      }
    } else if (isOperator_261100690032(c)) {
      int top;
      while (peekInt_261100690032(&top) == SUCCESS &&
             shouldPopOperator_261100690032(top, c)) {
        popInt_261100690032(&top);
        postfix[p++] = top;
      }
      pushInt_261100690032(c);
    } else {
      printf("Error: invalid character '%c'\n", c);
      ok = 0;
      break;
    }
  }

  if (ok) {
    int top;
    while (popInt_261100690032(&top) == SUCCESS) {
      postfix[p++] = top;
    }
    postfix[p] = '\0';
    printf("Postfix expression: %s\n", postfix);
  }

  clearStack_261100690032();
}

int main() {
  runMenu_261100690032("Infix to Postfix", "Convert an expression",
                       convertToPostfix_261100690032);
  return 0;
}
