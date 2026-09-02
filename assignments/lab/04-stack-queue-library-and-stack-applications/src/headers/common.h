/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 */

#ifndef COMMON_H
#define COMMON_H

#include "../headers/data_element.h"

void runMenu_261100690032(const char *title, const char *action_label,
                          void (*action)(void));

void clearStack_261100690032();

int pushInt_261100690032(int value);
int popInt_261100690032(int *out);
int peekInt_261100690032(int *out);

int isOpening_261100690032(char c);
int isClosing_261100690032(char c);
int isMatchingPair_261100690032(char open, char close);

int isOperator_261100690032(char c);
int precedence_261100690032(char c);
int shouldPopOperator_261100690032(char top, char c);
int applyOperator_261100690032(char op, int a, int b, int *result);

#endif
