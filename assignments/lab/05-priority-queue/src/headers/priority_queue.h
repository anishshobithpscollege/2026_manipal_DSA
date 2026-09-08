/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stddef.h>

#define SUCCESS 1
#define FAILURE 0

#define CAPACITY 100

typedef void *dataElement;

/* A smaller priority number means the element leaves first. */
void init_261100690032(void);
int isEmpty_261100690032(void);
int isFull_261100690032(void);
int insert_261100690032(dataElement data, int priority);
dataElement removeHighest_261100690032(int *priority);
dataElement peak_261100690032(int *priority);
void display_261100690032(void (*printFunc)(dataElement, int));

#endif
