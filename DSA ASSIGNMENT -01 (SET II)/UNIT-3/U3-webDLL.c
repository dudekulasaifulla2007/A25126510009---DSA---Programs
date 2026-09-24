#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

// Insert a new page
void insertPage(char page[]) {
    struct Node *newNode = malloc(sizeof(struct Node));

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    }
    else {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Page inserted: %s\n", page);
}

// Move forward
void moveForward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->next == NULL) {
        printf("Already at the last page.\n");
    }
    else {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

// Move backward
void moveBackward() {
    if (current == NULL) {
        printf("No pages available.\n");
    }
    else if (current->prev == NULL) {
        printf("Already at the first page.\n");
    }
    else {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

// Delete a specified page
void deletePage(char page[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Page not found.\n");
        return;
    }

    // If deleting the first node
    if (temp == head) {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    // If current page is deleted
    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);

    printf("Page deleted: %s\n", page);
}

// Display first to last
void displayForward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages in history.\n");
        return;
    }

    printf("Pages (First to Last): ");

    while (temp != NULL) {
        printf("%s ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

// Display last to first
void displayBackward() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("No pages in history.\n");
        return;
    }

    // Go to last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("Pages (Last to First): ");

    while (temp != NULL) {
        printf("%s ", temp->page);
        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    int choice;
    char page[50];

    while (1) {
        printf("\n--- Browser History ---\n");
        printf("1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter page name: ");
                scanf("%s", page);

                insertPage(page);
                break;

            case 2:
                moveForward();
                break;

            case 3:
                moveBackward();
                break;

            case 4:
                printf("Enter page to delete: ");
                scanf("%s", page);

                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}