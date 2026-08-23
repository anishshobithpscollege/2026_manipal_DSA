#include <assert.h>
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

void assertDLL(void) {
    int a = 10, b = 20, c = 30, d = 40;
    DLL *list = dll_create();

    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->size == 0);

    assert(dll_push_back(list, &a) == DLL_OK);
    assert(list->head == list->tail);
    assert(list->head->data == &a);
    assert(list->head->prev == NULL);
    assert(list->head->next == NULL);
    assert(list->size == 1);

    assert(dll_push_back(list, &b) == DLL_OK);
    assert(list->head->next == list->tail);
    assert(list->tail->prev == list->head);
    assert(list->tail->data == &b);
    assert(list->size == 2);

    assert(dll_push_front(list, &c) == DLL_OK);
    assert(list->head->data == &c);
    assert(list->head->prev == NULL);
    assert(list->head->next->data == &a);
    assert(list->size == 3);

    assert(dll_insert_at(list, 1, &d) == DLL_OK);
    assert(list->head->next->data == &d);
    assert(list->head->next->prev == list->head);
    assert(list->head->next->next->data == &a);
    assert(list->size == 4);

    assert(dll_insert_at(list, 99, &d) == DLL_FAIL);
    assert(list->size == 4);

    dll_swap(list->head, list->tail);
    assert(list->head->data == &b);
    assert(list->tail->data == &c);
    assert(list->size == 4);

    dll_unlink(list, list->head->next);
    assert(list->head->next->data == &a);
    assert(list->head->next->prev == list->head);
    assert(list->size == 3);

    dll_unlink(list, list->head);
    assert(list->head->data == &a);
    assert(list->head->prev == NULL);
    assert(list->size == 2);

    dll_unlink(list, list->tail);
    assert(list->head == list->tail);
    assert(list->tail->next == NULL);
    assert(list->size == 1);

    dll_unlink(list, list->head);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->size == 0);

    assert(dll_push_front(list, &a) == DLL_OK);
    assert(list->head == list->tail);
    assert(list->size == 1);

    dll_unlink(list, list->head);
    free(list);
}
