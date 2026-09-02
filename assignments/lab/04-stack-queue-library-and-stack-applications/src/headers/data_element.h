#ifndef DATA_ELEMENT_H
#define DATA_ELEMENT_H

#include <stddef.h>

#define SUCCESS 1
#define FAILURE 0

#define CAPACITY 100

typedef void *dataElement;

void init_261100690032();
int isEmpty_261100690032();
int isFull_261100690032();
void display_261100690032(void (*printFunc)(dataElement));
int push_261100690032(dataElement data);
dataElement pop_261100690032();
dataElement peak_261100690032();

#endif
