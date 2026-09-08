#include <stdio.h>
#include "../headers/recursion.h"

int gcd_261100690032(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int gcd_recursive_261100690032(const int a, const int b) {
    if (b == 0) return a;
    else return gcd_recursive_261100690032(b, a % b);
}

int main() {
    int choice, a , b;
    do {
        printf("\n1.GCD Iterative\n2.GCD Recursive\n3.Exit");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                    printf("Enter value for A and B : ");
                    scanf("%d %d", &a, &b);
                    printf("\nGCD of %d and %d is : %d\n", a, b, gcd_261100690032(a, b));
                    break;
            case 2:
                printf("Enter value for A and B : ");
                scanf("%d %d", &a, &b);
                printf("\nGCD of %d and %d is : %d\n", a, b, gcd_recursive_261100690032(a, b));
                break;
            case 3:
                break;
            default:
                printf("\nInvalid Input!");
        }
    } while (choice != 3);
}
