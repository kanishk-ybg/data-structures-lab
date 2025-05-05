#include <iostream>
#include <cmath>

using namespace std;

void checkPalindrome(int *num) {
    int temp = *num, rev = 0, rem;
    while (temp > 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }
    if (rev == *num)
        cout << "It is a Palindrome.\n";
    else
        cout << "Not a Palindrome.\n";
}

void checkArmstrong(int *num) {
    int temp = *num, sum = 0, digits = 0, rem;
    while (temp) {
        temp /= 10;
        digits++;
    }
    temp = *num;
    while (temp) {
        rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }
    if (sum == *num)
        cout << "It is an Armstrong Number.\n";
    else
        cout << "Not an Armstrong Number.\n";
}

void checkPerfect(int *num) {
    int sum = 0;
    for (int i = 1; i <= *num / 2; i++) {
        if (*num % i == 0) sum += i;
    }
    if (sum == *num)
        cout << "It is a Perfect Number.\n";
    else
        cout << "Not a Perfect Number.\n";
}

int main() {
    char ch;
    
    while (true) {
        cout << "\nMenu:\n";
        cout << "a. Palindrome\n";
        cout << "b. Armstrong Number\n";
        cout << "c. Perfect Number\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 'd' || ch == 'D') {
            cout << "Exiting program...\n";
            break;
        }

        int *num = new int;
        cout << "Enter a positive number: ";
        cin >> *num;

        if (*num < 0) {
            cout << "Invalid input! Enter a positive number.\n";
            delete num;
            continue;
        }

        if (ch == 'a' || ch == 'A') checkPalindrome(num);
        else if (ch == 'b' || ch == 'B') checkArmstrong(num);
        else if (ch == 'c' || ch == 'C') checkPerfect(num);
        else cout << "Invalid choice! Please select a valid option.\n";

        delete num;
    }

    return 0;
}
