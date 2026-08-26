#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *top;

static int read_int(const char *prompt) {
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

static void push(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = top;
    top = node;
}

static void pop(void) {
    if (!top) {
        printf("Stack underflow.\n");
        return;
    }

    Node *node = top;
    printf("Popped %d\n", node->data);

    top = node->next;
    free(node);
}

static void peek(void) {
    if (!top) printf("Stack is empty.\n");
    else printf("Top is %d\n", top->data);
}

static void display(void) {
    if (!top) {
        printf("Stack is empty.\n");
        return;
    }

    for (Node *current = top; current; current = current->next)
        printf("%d ", current->data);

    printf("\n");
}

static void free_stack(void) {
    while (top) {
        Node *next = top->next;
        free(top);
        top = next;
    }
}

static void print_menu(void) {
    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
}

int main(void) {
    int choice;
    do {
        print_menu();
        choice = read_int("Choice: ");

        switch (choice) {
            case 1: push(read_int("Value: ")); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    free_stack();
    return 0;
}
