#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node * next;

    Node(char ch)
    {
        data=ch;
        next=nullptr;
    }
};

class Stack{
    private:
    Node * top;
    public:
    Stack()
    {
        top=nullptr;
    }

    void push(char ch)
    {
        Node* newNode = new Node(ch);
        newNode-> next=top;
        top=newNode;
        cout << ch;
    }

    void pop()
    {
        if(!top){
            cout << "Stack underflow";
            return;
        }

        cout << "\n" << top->data << " popped";
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    void peek()
    {
        if(!top)
        {
            cout << "Stack is empty";
            return;
        }

        cout << "\nTop element: " << top->data;
    }
};

int main()
{

    Stack s;
    int choice;
    char ch;

    while(choice!=4){

        cout << "\n \nMENU \n1 -> PUSH \n2 -> POP \n3 -> PEEK\n4 -> EXIT";
        cin >> choice;

    switch(choice)
    {

        case 1:
        cout <<  "\nEnter character you would like to PUSH: ";
        cin >> ch;
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
}