#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

/* check if stack is full */
int isFull() {
return top == MAX - 1;
}

/* check if stack is empty */
int isEmpty() {

return top == -1;
}
/* push an element onto the stack */
void push(int val) {
if (isFull()) {
printf("Stack Overflow\n");
return;
}
stack[++top] = val;
printf("Pushed %d\n", val);
}
/* pop an element from the stack */
void pop() {
if (isEmpty()) {
printf("Stack Underflow\n");
return;
}
printf("Popped %d\n", stack[top--]);
}
/* view the top element without removing it */
void peek() {
if (isEmpty()) {
printf("Stack is empty\n");
return;
}
printf("Top element: %d\n", stack[top]);
}
/* print all elements of the stack */
void display() {
if (isEmpty()) {
printf("Stack is empty\n");
return;
}
printf("Stack (bottom -> top): ");
for (int i = 0; i <= top; i++)
printf("%d ", stack[i]);
printf("\n");
}
int main() {
int choice, val;
while (1) {
printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to push: ");
scanf("%d", &val);
push(val);
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}