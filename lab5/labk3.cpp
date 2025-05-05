#include <stdio.h>
#include <stdlib.h>

class Node {
    int data;
    Node* next;
    friend class CircularLinkedList; // Allow CircularLinkedList to access private members
};

class CircularLinkedList {
    Node* tail;

public:
    CircularLinkedList() {
        tail = NULL;
    }

    int insertBeginning(int);
    int insertEnd(int);
    int insertPosition(int, int);
    int deleteBeginning();
    int deleteEnd();
    int deletePosition(int);
    int search(int);
    void display();
};

int main() {
    CircularLinkedList list;
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            list.insertBeginning(value);
            break;

        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            list.insertEnd(value);
            break;

        case 3:
            printf("Enter the value: ");
            scanf("%d", &value);
            printf("Enter the index: ");
            scanf("%d", &position);
            list.insertPosition(value, position);
            break;

        case 4:
            value = list.deleteBeginning();
            if (value != -1) printf("Deleted element: %d\n", value);
            else printf("List is empty. Cannot delete element.\n");
            break;

        case 5:
            value = list.deleteEnd();
            if (value != -1) printf("Deleted element: %d\n", value);
            else printf("List is empty. Cannot delete element.\n");
            break;

        case 6:
            printf("Enter the index: ");
            scanf("%d", &position);
            value = list.deletePosition(position);
            if (value != -1) printf("Deleted element: %d\n", value);
            else printf("Invalid position.\n");
            break;

        case 7:
            printf("Enter the element to search: ");
            scanf("%d", &value);
            list.search(value);
            break;

        case 8:
            list.display();
            break;

        case 9:
            printf("Exiting the program...\n");
            return -1;

        default:
            printf("Invalid choice\n");
        }
    }
}

// Function to insert an element at the beginning
int CircularLinkedList::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;

    newNode->data = value;

    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    return 0;
}

// Function to insert an element at the end
int CircularLinkedList::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;

    newNode->data = value;

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

// Function to insert an element at a specific position
int CircularLinkedList::insertPosition(int value, int position) {
    if (position < 0) return -1;
    if (position == 0) return insertBeginning(value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;
    newNode->data = value;

    Node* temp = tail->next;
    int currentPos = 0;

    while (currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
        if (temp == tail->next) break;
    }

    if (temp == tail->next && currentPos != position - 1) {
        free(newNode);
        return -1;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) tail = newNode;
    return 0;
}

// Function to delete an element at the beginning
int CircularLinkedList::deleteBeginning() {
    if (tail == NULL) return -1;

    Node* head = tail->next;
    int data = head->data;

    if (head == tail) {
        free(head);
        tail = NULL;
    } else {
        tail->next = head->next;
        free(head);
    }
    return data;
}

// Function to delete an element at the end
int CircularLinkedList::deleteEnd() {
    if (tail == NULL) return -1;

    Node* head = tail->next;
    int data = tail->data;

    if (head == tail) {
        free(tail);
        tail = NULL;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
    return data;
}

// Function to delete an element at a specific position
int CircularLinkedList::deletePosition(int position) {
    if (tail == NULL || position < 0) return -1;
    if (position == 0) return deleteBeginning();

    Node* temp = tail->next;
    Node* prev = NULL;
    int currentPos = 0;

    while (currentPos < position) {
        prev = temp;
        temp = temp->next;
        currentPos++;
        if (temp == tail->next) break;
    }

    if (temp == tail->next) return -1;

    prev->next = temp->next;
    if (temp == tail) tail = prev;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to search for an element in the list
int CircularLinkedList::search(int value) {
    if (tail == NULL) {
        printf("List is empty. Cannot search element.\n");
        return -1;
    }

    Node* temp = tail->next;
    int position = 0;
    do {
        if (temp->data == value) {
            printf("Element %d found at index: %d\n", value, position);
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != tail->next);

    printf("Element %d not found\n", value);
    return -1;
}

// Function to display the list
void CircularLinkedList::display() {
    if (tail == NULL) {
        printf("List is empty. Cannot display elements.\n");
        return;
    }

    Node* temp = tail->next;
    printf("The elements in the list are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}