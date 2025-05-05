#include <stdio.h>
#include <stdlib.h>

class Node {
        int data;
        Node* next;
        Node* prev;
    
        // Allow DoublyLinkedList to access private members
        friend class DoublyLinkedList;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
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
    DoublyLinkedList list;
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
        printf("\nEnter your choice: ");
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

    return 0;
}

// Function to insert an element at the beginning
int DoublyLinkedList::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;  
    
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
    
    return 0;
    
}

// Function to insert an element at the end
int DoublyLinkedList::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == NULL) {
        head = newNode;
    }
    return 0;    
}

// Function to insert an element at a specific position
int DoublyLinkedList::insertPosition(int value, int position) {
    if (position <= 0) return insertBeginning(value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1; 
    newNode->data = value;

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return -1;
    }

    if (temp->next == NULL) {
        return insertEnd(value);
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return 0;
}


// Function to delete an element at the beginning
int DoublyLinkedList::deleteBeginning() {
    if (head == NULL) return -1;

    Node* temp = head;
    int data = temp->data;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    free(temp);
    return data;
}

// Function to delete an element at the end
int DoublyLinkedList::deleteEnd() {
    if (tail == NULL) return -1;
    Node* temp = tail;
    int data = temp->data;
    tail = tail->prev;

    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    
    free(temp);
    return data;
}

// Function to delete an element at a specific position
int DoublyLinkedList::deletePosition(int position) {
    if (position <= 0) return deleteBeginning();

    Node* temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return -1;
    if (temp == tail) return deleteEnd();

    int data = temp->data;
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    return data;
}

// Function to search for an element in the list
int DoublyLinkedList::search(int value) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at index: %d\n", value, position);
            return position;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found\n", value);
    return -1;  
}

// Function to display the list
void DoublyLinkedList::display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty. Cannot display the elements.\n");
        return;
    }
    printf("The elements in the list are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
