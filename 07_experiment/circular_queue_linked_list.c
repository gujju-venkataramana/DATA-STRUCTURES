#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* Keep rear->next == front whenever the queue is not empty. */
void enqueue(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    node->data = value;
    if (front == NULL) {
        front = rear = node;
        node->next = front;
    } else {
        node->next = front;
        rear->next = node;
        rear = node;
    }
    printf("%d inserted.\n", value);
}

void dequeue(void) {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue underflow: queue is empty.\n");
        return;
    }

    temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display(void) {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front to rear: ");
    temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

void clearQueue(void) {
    while (front != NULL) {
        struct Node *temp = front;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
}

int main(void) {
    int choice, value;
    do {
        printf("\n--- Circular Queue (Linked List) ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            clearQueue();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Value: ");
                if (scanf("%d", &value) != 1) {
                    clearQueue();
                    return 1;
                }
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: clearQueue(); printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
