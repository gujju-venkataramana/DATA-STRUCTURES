#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define EMPTY -1

int table[MAX];
int size;

/* ---------- Linear Probing ---------- */
void initialize(void) {
    int i;
    for (i = 0; i < size; i++)
        table[i] = EMPTY;
}

void linearInsert(int key) {
    int h = key % size;
    int i, index;

    for (i = 0; i < size; i++) {
        index = (h + i) % size;

        if (table[index] == EMPTY) {
            table[index] = key;
            printf("Inserted %d at index %d; probes = %d\n",
                   key, index, i + 1);
            return;
        }
    }

    printf("Hash table is full.\n");
}

int linearSearch(int key) {
    int h = key % size;
    int i, index;

    for (i = 0; i < size; i++) {
        index = (h + i) % size;

        if (table[index] == EMPTY)
            return -1;

        if (table[index] == key)
            return index;
    }

    return -1;
}

void displayTable(void) {
    int i;

    for (i = 0; i < size; i++) {
        if (table[i] == EMPTY)
            printf("[%d] EMPTY\n", i);
        else
            printf("[%d] %d\n", i, table[i]);
    }
}

/* ---------- Quadratic Probing ---------- */
void quadraticInsert(int key) {
    int h = key % size;
    int i, index;

    for (i = 0; i < size; i++) {
        index = (h + i * i) % size;

        if (table[index] == EMPTY) {
            table[index] = key;
            printf("Inserted %d at index %d; probes = %d\n",
                   key, index, i + 1);
            return;
        }
    }

    printf("Could not insert using quadratic probing.\n");
}

/* ---------- Separate Chaining ---------- */
struct Node {
    int key;
    struct Node *next;
};

struct Node *chain[MAX];

void chainInitialize(void) {
    int i;
    for (i = 0; i < size; i++)
        chain[i] = NULL;
}

void chainInsert(int key) {
    int index = key % size;
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;
    int probes = 1;

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL;

    if (chain[index] == NULL) {
        chain[index] = newNode;
    } else {
        temp = chain[index];
        probes = 2;
        while (temp->next != NULL) {
            temp = temp->next;
            probes++;
        }
        temp->next = newNode;
    }

    printf("Inserted %d in bucket %d; probes = %d\n",
           key, index, probes);
}

void chainDisplay(void) {
    int i;
    struct Node *temp;

    for (i = 0; i < size; i++) {
        printf("[%d] ", i);
        temp = chain[i];

        if (temp == NULL) {
            printf("EMPTY");
        } else {
            while (temp != NULL) {
                printf("%d", temp->key);
                if (temp->next != NULL)
                    printf(" -> ");
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

int main(void) {
    int method, choice, key, pos;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("\nChoose collision resolution:\n");
    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Separate Chaining\n");
    printf("Choice: ");
    scanf("%d", &method);

    if (method == 3)
        chainInitialize();
    else
        initialize();

    while (1) {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key: ");
            scanf("%d", &key);

            if (method == 1)
                linearInsert(key);
            else if (method == 2)
                quadraticInsert(key);
            else
                chainInsert(key);

        } else if (choice == 2) {
            if (method != 1) {
                printf("Search is demonstrated here for linear probing.\n");
            } else {
                printf("Enter key: ");
                scanf("%d", &key);
                pos = linearSearch(key);

                if (pos == -1)
                    printf("Key not found.\n");
                else
                    printf("Key found at index %d.\n", pos);
            }

        } else if (choice == 3) {
            if (method == 3)
                chainDisplay();
            else
                displayTable();

        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
