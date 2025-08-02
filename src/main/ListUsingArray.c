#include <stdio.h>
#define MAX_SIZE 10
int arr[MAX_SIZE];
int size = 0;
void insertAtIndex();
void deleteByIndex();
void deleteByValue();
void display();
void findMax();
void findMin();

int main() {
    arr[10] = 10,20,30,40;
   int choice;

    do {
        printf("\n-- Menu --\n");
        printf("1. Insert at Specific Index\n");
        printf("2. Delete by Index\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Max\n");
        printf("6. Min\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtIndex(); break;
            case 2: deleteByIndex(); break;
            case 3 : deleteByValue(); break;
            case 4: display(); break;
            case 5: findMax(); break;
            case 6: findMin(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}

void insertAtIndex() {
    if (size >= MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }
    int value, index;
    printf("Enter value and index: ");
    scanf("%d%d", &value, &index);
    if (index < 0 || index > size) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
    printf("%d inserted at index %d.\n", value, index);
}

void deleteByIndex() {
    int index;
    printf("Enter index to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }
    printf("Element at index %d deleted.\n", index);
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void deleteByValue() {
    int value, found = 0;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            printf("Element at index %d deleted.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value not found.\n");
    }
}

void display() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("Current list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findMax() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Max: %d\n", max);
}

void findMin() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Min: %d\n", min);
}
