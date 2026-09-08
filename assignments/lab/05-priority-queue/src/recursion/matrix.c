#include <stdio.h>
#include "../headers/recursion.h"

static void print_matrix_261100690032(int rows, int cols, const int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%-5d", mat[i][j]);
        }
        printf("\n");
    }
}

void matrix_addition_261100690032(int rows, int cols, const int matA[rows][cols], const int matB[rows][cols]) {
    int matC[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }

    printf("\nMatrix Addition is : \n");
    print_matrix_261100690032(rows, cols, matC);
}

static void showMenu_261100690032(void) {
    printf("\n1. Start Matrix Addition\n2. Exit\nChoice: ");
}

int main(void) {
    int choice, rows, cols;

    do {
        showMenu_261100690032();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter the number of rows and columns : ");
                scanf("%d %d", &rows, &cols);
                int matA[rows][cols];
                int matB[rows][cols];

                printf("Enter the values for Matrix A :\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Matrix A[%d][%d]: ", i, j);
                        scanf("%d", &matA[i][j]);
                    }
                }

                printf("\nValues of Matrix A are :\n");
                print_matrix_261100690032(rows, cols, matA);

                printf("\nEnter the values for Matrix B :\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Matrix B[%d][%d]: ", i, j);
                        scanf("%d", &matB[i][j]);
                    }
                }

                printf("\nValues of Matrix B are :\n");
                print_matrix_261100690032(rows, cols, matB);

                matrix_addition_261100690032(rows, cols, matA, matB);
                break;
            }
            case 2: printf("Bye\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 2);

    return 0;
}
