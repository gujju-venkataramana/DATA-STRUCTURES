#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int value) {
    struct Node *newNode = createNode(value);

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void deleteBeginning(void) {
    struct Node *first;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    first = last->next;

    if (first == last)
        last = NULL;
    else
        last->next = first->next;

    free(first);
}

void display(void) {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;
    printf("Circular List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1.Insert Beginning  2.Insert End  3.Delete Beginning  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                deleteBeginning();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
