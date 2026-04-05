#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
// Push
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = ch;
}
// Pop
char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}
// Check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}
// Check balance
int isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        // If opening bracket, push
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        // If closing bracket
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) // no matching opening
                return 0;
            char popped = pop();
            if (!isMatchingPair(popped, exp[i]))
                return 0;
        }
    }
    // If stack empty → balanced
    return (top == -1);
}
int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);
    if (isBalanced(exp))
        printf("Balanced Expression\n");
    else
        printf("Not Balanced Expression\n");
    return 0;
}