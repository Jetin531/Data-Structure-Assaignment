#include <stdio.h>
#include <string.h>
#define MAX 5
// Queue structure
char queue[MAX][50];
int front = -1, rear = -1;
// Add document
void enqueue(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue is FULL! Cannot add document.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    strcpy(queue[rear], doc);
    printf("Document added: %s\n", doc);
}
// Print document
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY! No documents to print.\n");
        return;
    }
    printf("Printing document: %s\n", queue[front]);
    front++;
}
// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents.\n");
        return;
    }
    printf("Pending Documents:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}
// Main function
int main() {
    int choice;
    char doc[50];
    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}