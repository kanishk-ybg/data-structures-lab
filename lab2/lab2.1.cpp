#include <iostream>

using namespace std;

class Shape {
private:
    double *length, *width, *height;
    
public:
    Shape() {
        length = new double;
        width = new double;
        height = new double;
    }

    ~Shape() {
        delete length;
        delete width;
        delete height;
    }

    void areaSquare() {
        cout << "Enter side length: ";
        cin >> *length;
        if (*length <= 0) {
            cout << "Invalid input! Length must be positive.\n";
            return;
        }
        cout << "Area of Square: " << (*length) * (*length) << endl;
    }

    void areaCube() {
        cout << "Enter side length: ";
        cin >> *length;
        if (*length <= 0) {
            cout << "Invalid input! Length must be positive.\n";
            return;
        }
        cout << "Surface Area of Cube: " << 6 * (*length) * (*length) << endl;
    }

    void areaRectangle() {
        cout << "Enter length: ";
        cin >> *length;
        cout << "Enter width: ";
        cin >> *width;
        if (*length <= 0 || *width <= 0) {
            cout << "Invalid input! Length and width must be positive.\n";
            return;
        }
        cout << "Area of Rectangle: " << (*length) * (*width) << endl;
    }

    void areaCuboid() {
        cout << "Enter length: ";
        cin >> *length;
        cout << "Enter width: ";
        cin >> *width;
        cout << "Enter height: ";
        cin >> *height;
        if (*length <= 0 || *width <= 0 || *height <= 0) {
            cout << "Invalid input! Length, width, and height must be positive.\n";
            return;
        }
        cout << "Surface Area of Cuboid: " << 2 * ((*length * *width) + (*width * *height) + (*length * *height)) << endl;
    }
};

int main() {
    Shape obj;
    char choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "a) Square\n";
        cout << "b) Cube\n";
        cout << "c) Rectangle\n";
        cout << "d) Cuboid\n";
        cout << "e) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 'e' || choice == 'E') {
            cout << "Exiting program...\n";
            break;
        }

        switch (choice) {
            case 'a': case 'A': obj.areaSquare(); break;
            case 'b': case 'B': obj.areaCube(); break;
            case 'c': case 'C': obj.areaRectangle(); break;
            case 'd': case 'D': obj.areaCuboid(); break;
            default: cout << "Invalid choice! Please select a valid option.\n";
        }
    }

    return 0;
}
