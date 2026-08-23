#include <stdlib.h>
#include "./headers/dll.h"

static DLLNode *create_node(void *data) {
    DLLNode *node = malloc(sizeof(DLLNode));

    if (node == NULL) {
        return NULL;
    }

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

DLL *dll_create(void) {
    DLL *list = malloc(sizeof(DLL));

    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

int dll_push_front(DLL *list, void *data) {
    DLLNode *node = create_node(data);

    if (node == NULL) {
        return DLL_FAIL;
    }

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->size++;

    return DLL_OK;
}

int dll_push_back(DLL *list, void *data) {
    DLLNode *node = create_node(data);

    if (node == NULL) {
        return DLL_FAIL;
    }

    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;

    return DLL_OK;
}

int dll_insert_at(DLL *list, size_t index, void *data) {
    if (index > list->size) {
        return DLL_FAIL;
    }

    if (index == 0) {
        return dll_push_front(list, data);
    }

    if (index == list->size) {
        return dll_push_back(list, data);
    }

    DLLNode *node = create_node(data);

    if (node == NULL) {
        return DLL_FAIL;
    }

    DLLNode *target = list->head;

    for (size_t i = 0; i < index; i++) {
        target = target->next;
    }

    node->prev = target->prev;
    node->next = target;

    target->prev->next = node;
    target->prev = node;

    list->size++;

    return DLL_OK;
}

void dll_swap(DLLNode *a, DLLNode *b) {
    void *temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void dll_unlink(DLL *list, DLLNode *node) {
    if (node->prev == NULL) {
        list->head = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == NULL) {
        list->tail = node->prev;
    } else {
        node->next->prev = node->prev;
    }

    list->size--;

    free(node);
}
