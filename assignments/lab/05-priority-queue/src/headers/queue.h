/**
 * Name: Anish Shobith P S
 * Reg No: 261100690032
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

#define SUCCESS 1
#define FAILURE 0

#define CAPACITY 5

typedef void *dataElement;

void init_261100690032(void);
int isEmpty_261100690032(void);
int isFull_261100690032(void);
int enqueue_261100690032(dataElement data);
dataElement dequeue_261100690032(void);
dataElement peak_261100690032(void);
void display_261100690032(void (*printFunc)(dataElement));

#endif
