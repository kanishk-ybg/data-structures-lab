#include "rrheader.h"

int main() {
    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    CircularQueue queue(quantum);
    int choice, time;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Process\n");
        printf("2. Execute\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter process time: ");
            scanf("%d", &time);
            queue.insertProcess(time);
            break;

        case 2:
            queue.execute();
            break;

        case 3:
            printf("Exiting the program...\n");
            return -1;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to insert a process into the circular queue
int CircularQueue::insertProcess(int time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;

    newNode->time = time;

    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    return 0;
}

// Function to execute a process for the fixed time quantum
void CircularQueue::execute() {
    if (tail == NULL) {
        printf("Queue is empty. No processes to execute.\n");
        return;
    }

    Node* front = tail->next;
    front->time -= quantum;
    printf("Process executed. Remaining time: %d\n", front->time);

    if (front->time <= 0) {
        printf("Process completed.\n");
        if (front == tail) {
            free(front);
            tail = NULL;
        } else {
            tail->next = front->next;
            free(front);
        }
    } else {
        tail = front;
    }
}