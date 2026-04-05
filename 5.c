#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
// Enqueue operation
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is FULL!\n");
        return;
    }
    if (front == -1) // first element
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}
// Dequeue operation
void dequeue() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Removed: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // reset queue
    } else {
        front = (front + 1) % MAX;
    }
}
// Peek operation
void peek() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}
// Display operation
void display() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}