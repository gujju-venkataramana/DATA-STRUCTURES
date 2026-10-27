#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
/* push a value onto the stack */
void push(int val) {
if (top == MAX - 1)
printf("Stack Overflow\n");
else
stack[++top] = val;
}
/* pop a value from the stack */
int pop() {
if (top == -1) {
printf("Stack Underflow\n");
exit(1);
}
return stack[top--];
}
/* apply an operator to two operands */
int applyOperator(char op, int a, int b) {
switch (op) {
case '+': return a + b;
case '-': return a - b;
case '*': return a * b;
case '/': return a / b;
case '^': {
int result = 1, i;
for (i = 0; i < b; i++)
result = result * a;
return result;
}
default:
printf("Invalid operator\n");
exit(1);
}
}

/* evaluate a postfix expression */
int evaluatePostfix(char postfix[]) {
int i, a, b, result;
char ch;
for (i = 0; postfix[i] != '\0'; i++) {
ch = postfix[i];
if (isspace(ch))
continue;
if (isdigit(ch)) {
/* single-digit operand */
push(ch - '0');
}
else {
b = pop(); /* second operand popped first */
a = pop(); /* first operand */
result = applyOperator(ch, a, b);
push(result);
}
}
return pop();
}
int main() {
char postfix[MAX];
printf("Enter postfix expression (single digit operands): ");
scanf("%s", postfix);
printf("Result = %d\n", evaluatePostfix(postfix));
return 0;
}