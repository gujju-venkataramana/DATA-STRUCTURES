#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* ---------- INSERTION OPERATIONS ---------- */

void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Inserted %d as the first node.\n", value);
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", value, pos);
        return;
    }

    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", pos);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, pos);
}

/* ---------- DELETION OPERATIONS ---------- */

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Case: only one node in the list
    if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Traverse to the second-last node
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    // Case: delete first node
    if (pos == 1) {
        struct Node *temp = head;
        head = head->next;
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }

    // Traverse to the node just before the target position
    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // Validate position
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of range.\n", pos);
        return;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted %d from position %d.\n", toDelete->data, pos);
    free(toDelete);
}

/* ---------- DISPLAY ---------- */

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- MAIN MENU ---------- */

int main() {
    int choice, value, pos;

    do{
        printf("\n===== LINKED LIST OPERATIONS =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}

