#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int value) {
    struct Node *newNode = createNode(value);

    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int key, int value) {
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Given node not found.\n");
        return;
    }

    newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void displayForward(void) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayReverse(void) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(void) {
    int choice, value, key;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1.Insert Front  2.Insert End  3.Insert After Node  4.Forward  5.Reverse  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Insert after which node? ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertAfter(key, value);
                break;
            case 4:
                displayForward();
                break;
            case 5:
                displayReverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
