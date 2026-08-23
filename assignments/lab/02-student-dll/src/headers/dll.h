#ifndef DLL_H
#define DLL_H

#include <stddef.h>

#define DLL_OK 1
#define DLL_FAIL 0

typedef struct DLLNode {
    void *data;
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

typedef struct DLL {
    DLLNode *head;
    DLLNode *tail;
    size_t size;
} DLL;

DLL *dll_create(void);

int dll_push_front(DLL *list, void *data);
int dll_push_back(DLL *list, void *data);
int dll_insert_at(DLL *list, size_t index, void *data);

void dll_swap(DLLNode *a, DLLNode *b);
void dll_unlink(DLL *list, DLLNode *node);

#endif
