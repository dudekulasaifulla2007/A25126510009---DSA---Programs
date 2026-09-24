#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

// Create / Insert at end
void create(int roll) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

// Insert at beginning
void insertBeginning(int roll) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int roll) {
    create(roll);
}

// Search
void search(int roll) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d found\n", roll);
            return;
        }

        temp = temp->next;
    }

    printf("Roll number %d not found\n", roll);
}

// Delete
void deleteRoll(int roll) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Delete first node
    if (head->roll == roll) {
        head = head->next;
        free(temp);
        printf("Roll number %d deleted\n", roll);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    // Roll number not found
    if (temp == NULL) {
        printf("Roll number %d not found\n", roll);
        return;
    }

    // Delete node
    prev->next = temp->next;
    free(temp);

    printf("Roll number %d deleted\n", roll);
}

// Display
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Student roll numbers: ");

    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, roll, n, i;

    while (1) {
        printf("\n--- Student Roll Number List ---\n");
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Search\n");
        printf("5. Delete\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);

                printf("Enter roll numbers:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &roll);
                    create(roll);
                }

                display();
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);

                insertBeginning(roll);
                display();
                break;

            case 3:
                printf("Enter roll number: ");
                scanf("%d", &roll);

                insertEnd(roll);
                display();
                break;

            case 4:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);

                search(roll);
                display();
                break;

            case 5:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);

                deleteRoll(roll);
                display();
                break;

            case 6:
                display();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}