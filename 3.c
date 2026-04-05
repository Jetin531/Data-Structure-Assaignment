#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
// Push
void push(int x) {
    stack[++top] = x;
}
// Pop
void pop() {
    if (top != -1)
        top--;
}
// Peek
int peek() {
    if (top == -1)
        return -1;
    return stack[top];
}
// Check empty
int isEmpty() {
    return top == -1;
}
int main() {
    int arr[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result[MAX];
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Remove smaller elements
        while (!isEmpty() && peek() <= arr[i]) {
            pop();
        }
        // Assign result
        if (isEmpty())
            result[i] = -1;
        else
            result[i] = peek();
        // Push current element
        push(arr[i]);
    }
    // Print result
    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d → %d\n", arr[i], result[i]);
    }
    return 0;
}