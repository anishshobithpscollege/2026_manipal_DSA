#include <stdio.h>
#include "../headers/recursion.h"

void tower_of_hanoi_261100690032(const int n, char from, char to, char aux, int *count) {
    if (n >= 1) {
        tower_of_hanoi_261100690032(n - 1, from, aux, to, count);
        (*count)++; // de-reference first then increment as ur passing the address in the function call.
        printf("Moved disk from %c to %c\n", from, to);
        tower_of_hanoi_261100690032(n - 1, aux, to, from, count);
    }
}

int main() {
    int choice, no;
    do {
        printf("\n1. Solve tower of hanoi\n2. Exit");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of disks : ");
                scanf("%d", &no);
                int count = 0;
                tower_of_hanoi_261100690032(no, 'F', 'T', 'A', &count);
                printf("No of steps taken is : %d", count);
                break;
            case 2:
                break;
            default:
                printf("\nInvalid Input!");
        }
    } while (choice != 2);
}
