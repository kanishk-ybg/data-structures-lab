#include <iostream>
}

void LinkedList::deletePosition(int pos) {
    if (!head || pos < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < pos - 1; ++i)
        temp = temp->next;
    if (!temp->next) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

void LinkedList::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found!" << endl;
}

void LinkedList::display() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::displayReverse(Node* node) {
    if (!node) return;
    displayReverse(node->next);
    cout << node->data << " <- ";
}

void LinkedList::reverseDisplay() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    displayReverse(head);
    cout << "NULL" << endl;
}

void LinkedList::reverseLink() {
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

LinkedList::~LinkedList() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    LinkedList list;
    int choice, value, pos;
    while (true) {

