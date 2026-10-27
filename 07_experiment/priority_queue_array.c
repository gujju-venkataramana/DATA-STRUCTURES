#include <stdio.h>

#define MAX 100

struct Item {
    int data;
    int priority;
};

struct Item queue[MAX];
int size = 0;

/* Smaller priority value means higher priority; 1 is highest. */
void insert(int data, int priority) {
    int i;
    if (size == MAX) {
        printf("Priority queue overflow.\n");
        return;
    }

    /* Keep same-priority items in their insertion order. */
    i = size - 1;
    while (i >= 0 && queue[i].priority > priority) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1].data = data;
    queue[i + 1].priority = priority;
    size++;
    printf("Inserted %d with priority %d.\n", data, priority);
}

void deleteHighestPriority(void) {
    int i;
    if (size == 0) {
        printf("Priority queue underflow.\n");
        return;
    }

    printf("Deleted: %d (priority %d)\n", queue[0].data, queue[0].priority);
    for (i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    size--;
}

void display(void) {
    int i;
    if (size == 0) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Data\tPriority\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\n", queue[i].data, queue[i].priority);
    }
}

int main(void) {
    int choice, data, priority;
    do {
        printf("\n--- Priority Queue (Array) ---\n");
        printf("1. Insert\n2. Delete highest-priority item\n3. Display\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;

        switch (choice) {
            case 1:
                printf("Data: ");
                if (scanf("%d", &data) != 1) return 1;
                printf("Priority (smaller number = higher priority): ");
                if (scanf("%d", &priority) != 1) return 1;
                insert(data, priority);
                break;
            case 2: deleteHighestPriority(); break;
            case 3: display(); break;
            case 0: printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
