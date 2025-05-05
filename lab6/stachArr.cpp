#include <iostream>
using namespace std;

#define SIZE 5

class Stack{
    private:
    char arr[SIZE];
    int top;

    public:
    Stack()           //constructor
    {
        top=-1;
    }

    void push(char ch)
    {
        if(top>=SIZE-1)
        {
            cout << "\nSTACK OVERFLOW";
            return;
        }
        arr[++top]=ch;
        cout<< "\n" <<ch<<" has been successfuly pushed!\n";
    }

    void pop()
    {
        if(top<0)
        {
            cout << "\nSTACK UNDERFLOW";
            return;
        }

        cout << "\n" << arr[top--] << " has been successfuly popped!\n";
    }

    void peek()
    {
        if(top<0)
        {
            cout << "\nStack is empty!";
            return;
        }

        cout << "\nTop element: " << arr[top] <<"\n";
    }


};

int main()
{
    Stack s;
    int choice;
    char ch;

    while(choice!=4){

        cout << "\nEnter \n1 -> PUSH \n2 -> POP \n3 -> PEEK\n4 -> EXIT";
        cin >> choice;

    switch(choice)
    {

        case 1:
        cout <<  "\nEnter character you would like to PUSH: ";
        cin >> ch;
        cout <<"\n";
        s.push(ch);
      
        break;

        case 2:
        s.pop();
        
        break;

        case 3:
        s.peek();
        break;

        case 4:
        cout << "\nEXITING...";
        break;

        default:
        cout << "\nINVALID PLEASE TRY AGAIN";
    }
    }

    return 0;
}
