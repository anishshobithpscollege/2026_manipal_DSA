#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *head;

static Node *create(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

static int read_int(const char *prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

static void push_back(int data) {
    Node *node = create(data);

    if (!head) {
        head = node;
        return;
    }

    Node *current = head;
    while (current->next) current = current->next;

    current->next = node;
}

static void swap_adjacent(void) {
    Node dummy;
    dummy.next = head;
    Node *prev = &dummy;

    while (prev->next && prev->next->next) {
        Node *first = prev->next;
        Node *second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    head = dummy.next;
}

static void display(void) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    for (Node *current = head; current; current = current->next)
        printf("%d ", current->data);

    printf("\n");
}

static void free_list(void) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

static void print_menu(void) {
    printf("\n1. Insert\n2. Swap adjacent\n3. Display\n4. Exit\n");
}

int main(void) {
    int choice;
    do {
        print_menu();
        choice = read_int("Choice: ");

        switch (choice) {
            case 1: push_back(read_int("Value: ")); break;
            case 2:
                swap_adjacent();
                printf("Adjacent nodes swapped.\n");
                break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    free_list();
    return 0;
}
