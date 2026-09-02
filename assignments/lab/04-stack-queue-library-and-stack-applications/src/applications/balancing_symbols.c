/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 * Assignment 04 - Application 1: Balancing of Symbols
 */

#include "../headers/common.h"
#include <stdio.h>

static void checkBalancing_261100690032() {
  char expr[100];

  printf("Enter an expression: ");
  if (scanf("%99s", expr) != 1) {
    printf("Error: could not read input\n");
    return;
  }

  init_261100690032();

  int balanced = 1;
  for (int i = 0; expr[i] != '\0'; i++) {
    char c = expr[i];

    if (isOpening_261100690032(c)) {
      if (pushInt_261100690032(c) == FAILURE) {
        printf("Not balanced: stack is full (expression too long)\n");
        balanced = 0;
        break;
      }
    } else if (isClosing_261100690032(c)) {
      int open;
      if (popInt_261100690032(&open) == FAILURE) {
        printf("Not balanced: extra '%c'\n", c);
        balanced = 0;
        break;
      }
      if (!isMatchingPair_261100690032(open, c)) {
        printf("Not balanced: '%c' does not match '%c'\n", open, c);
        balanced = 0;
        break;
      }
    }
  }

  if (balanced) {
    if (isEmpty_261100690032()) {
      printf("Balanced\n");
    } else {
      printf("Not balanced: some opening symbols are not closed\n");
    }
  }

  clearStack_261100690032();
}

int main() {
  runMenu_261100690032("Balancing of Symbols", "Check an expression",
                       checkBalancing_261100690032);
  return 0;
}
