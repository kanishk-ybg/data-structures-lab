#include "ListADT.h"

int main() {
    ListADT list1, list2, list3;
    int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert into List1\n";
        std::cout << "2. Insert into List2\n";
        std::cout << "3. Merge into List3\n";
        std::cout << "4. Display Lists\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert in List1: ";
                std::cin >> value;
                list1.insertAscending(value);
                break;

            case 2:
                std::cout << "Enter value to insert in List2: ";
                std::cin >> value;
                list2.insertAscending(value);
                break;

            case 3:
                list3 = ListADT::mergeLists(list1, list2);
                std::cout << "Lists merged successfully.\n";
                break;

            case 4:
                std::cout << "List1: ";
                list1.display();
                std::cout << "List2: ";
                list2.display();
                std::cout << "List3: ";
                list3.display();
                break;

            case 5:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}


#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>

class ListADT {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

    Node* gethead() { return head; } // Private function to return head

public:
    ListADT() : head(nullptr) {}

    void insertAscending(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    static ListADT mergeLists(const ListADT& list1, const ListADT& list2) {
        ListADT mergedList;
        Node* ptr1 = list1.head;
        Node* ptr2 = list2.head;

        while (ptr1 || ptr2) {
            if (!ptr2 || (ptr1 && ptr1->data <= ptr2->data)) {
                mergedList.insertAscending(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                mergedList.insertAscending(ptr2->data);
                ptr2 = ptr2->next;
            }
        }
        return mergedList;
    }

    void display() const {
        Node* temp = head;
        if (!temp) {
            std::cout << "List is empty.\n";
            return;
        }
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    ~ListADT() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif // LISTADT_H
