#include <stdio.h>
#include <stdlib.h>

void findPair(int *array, int size, int target) {
    int found = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] + array[j] == target) {
                printf("[%d,%d]", i, j);
                found = 1;
                return;
            }
        }
    }
    if (!found) {
        printf("No pair found that sums to %d\n", target);
    }
}

int main() {
    int *array = NULL;
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- Two Sum Program ---\n");
        printf("1. Enter element into array\n");
        printf("2. Enter target and find pair\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int data;
            printf("Enter data to insert into array: ");
            scanf("%d", &data);

            int *temp = realloc(array, (size + 1) * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation failed.\n");
                free(array);
                return 1;
            }
            array = temp;
            array[size++] = data;

        } else if (choice == 2) {
            if (size == 0) {
                printf("Array is empty. Please insert elements first.\n");
                continue;
            }
            int target;
            printf("Enter target: ");
            scanf("%d", &target);
            findPair(array, size, target);

        } else if (choice == 3) {
            if (array != NULL) {
                free(array);
            }
            printf("Exiting...\n");
            break;

        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
