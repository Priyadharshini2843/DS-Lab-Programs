#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int linearQueue[SIZE];
int circularQueue[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
void linearInsert(int value) {
    if (rear1 == SIZE - 1) {
        printf("Linear Queue is Full\n");
    } else {
        if (front1 == -1)
            front1 = 0;
        rear1++;
        linearQueue[rear1] = value;
        printf("Inserted in Linear Queue: %d\n", value);
    }
}
void linearDelete() {
    if (front1 == -1 || front1 > rear1) {
        printf("Linear Queue is Empty\n");
    } else {
        printf("Deleted from Linear Queue: %d\n", linearQueue[front1]);
        front1++;
    }
}
void linearDisplay() {
    if (front1 == -1 || front1 > rear1) {
        printf("Linear Queue is Empty\n");
    } else {
        printf("Linear Queue Elements: ");
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", linearQueue[i]);
        }
        printf("\n");
    }
}
void circularInsert(int value) {
    if ((front2 == 0 && rear2 == SIZE - 1) || (rear2 + 1) % SIZE == front2) {
        printf("Circular Queue is Full\n");
    } else {
        if (front2 == -1)
            front2 = rear2 = 0;
        else
            rear2 = (rear2 + 1) % SIZE;
        circularQueue[rear2] = value;
        printf("Inserted in Circular Queue: %d\n", value);
    }
}
void circularDelete() {
    if (front2 == -1) {
        printf("Circular Queue is Empty\n");
    } else {
        printf("Deleted from Circular Queue: %d\n", circularQueue[front2]);
        if (front2 == rear2)
            front2 = rear2 = -1;
        else
            front2 = (front2 + 1) % SIZE;
    }
}
void circularDisplay() {
    if (front2 == -1) {
        printf("Circular Queue is Empty\n");
    } else {
        printf("Circular Queue Elements: ");
        int i = front2;
        while (1) {
            printf("%d ", circularQueue[i]);
            if (i == rear2)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}
int main() {
    int choice, queueType, value;
    while (1) {
        printf("\n========= MENU =========\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }

        printf("Choose Queue Type:\n1. Linear Queue\n2. Circular Queue\nEnter your choice: ");
        scanf("%d", &queueType);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (queueType == 1)
                    linearInsert(value);
                else if (queueType == 2)
                    circularInsert(value);
                else
                    printf("Invalid Queue Type\n");
                break;

            case 2:
                if (queueType == 1)
                    linearDelete();
                else if (queueType == 2)
                    circularDelete();
                else
                    printf("Invalid Queue Type\n");
                break;

            case 3:
                if (queueType == 1)
                    linearDisplay();
                else if (queueType == 2)
                    circularDisplay();
                else
                    printf("Invalid Queue Type\n");
                break;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
