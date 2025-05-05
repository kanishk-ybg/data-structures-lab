#include <iostream>
using namespace std;

class ListADT {
    int arr[5];
    int size;
public:
    ListADT() : size(0) {}
    void insertBeginning(int val);
    void insertEnd(int val);
    void insertPosition(int pos, int val);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int pos);
    void search(int val);
    void display();
    void rotate(int k);
};

void ListADT::insertBeginning(int val) {
    if (size == 5) { cout << "List is full!" << endl; return; }
    for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = val;
    size++;
}

void ListADT::insertEnd(int val) {
    if (size == 5) { cout << "List is full!" << endl; return; }
    arr[size++] = val;
}

void ListADT::insertPosition(int pos, int val) {
    if (size == 5 || pos < 0 || pos > size) { cout << "Invalid position!" << endl; return; }
    for (int i = size; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    size++;
}

void ListADT::deleteBeginning() {
    if (size == 0) { cout << "List is empty!" << endl; return; }
    for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
    size--;
}

void ListADT::deleteEnd() {
    if (size == 0) { cout << "List is empty!" << endl; return; }
    size--;
}

void ListADT::deletePosition(int pos) {
    if (size == 0 || pos < 0 || pos >= size) { cout << "Invalid position!" << endl; return; }
    for (int i = pos; i < size - 1; i++) arr[i] = arr[i + 1];
    size--;
}

void ListADT::search(int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) { cout << "Element found at index " << i << endl; return; }
    }
    cout << "Element not found" << endl;
}

void ListADT::display() {
    if (size == 0) { cout << "List is empty!" << endl; return; }
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void ListADT::rotate(int k) {
    k = k % size; // Handle large k values
    for (int i = 0; i < k; i++) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) arr[j] = arr[j - 1];
        arr[0] = temp;
    }
}

int main() {
    ListADT list;
    int choice, val, pos, k;
    while (true) {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertEnd(val); break;
            case 3: cout << "Enter position and value: "; cin >> pos >> val; list.insertPosition(pos, val); break;
            case 4: list.deleteBeginning(); break;
            case 5: list.deleteEnd(); break;
            case 6: cout << "Enter position: "; cin >> pos; list.deletePosition(pos); break;
            case 7: cout << "Enter value: "; cin >> val; list.search(val); break;
            case 8: list.display(); break;
            case 9: cout << "Enter k: "; cin >> k; list.rotate(k); break;
            case 10: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
