#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert
void insert(int value) {

    // Queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    // First element
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("%d inserted\n", value);
}

// Delete
void delete() {

    // Queue is empty
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", queue[front]);

    // Last element deleted
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    printf("Queue: ");

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    int choice, value;

    while (1) {

        printf("\n--- Circular Queue ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter request: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}