#include <iostream>
using namespace std;
#define SIZE 5

class queue
{
    private:
    int front;
    int rear;
    int arr[SIZE];

    public:
    queue()
    {
        front=-1;
        rear=-1;
    }

    void enqueue(int val)
    {
        if(rear==SIZE-1)
        {
            cout <<"\nQUEUE IS FULL!";
            return;
        }

        if(front=-1)
        front=0;

        arr[++rear]=val;

        cout<<"\n"<<val<<" HAS BEEN SUCCESFULY ENQUEUED!";
    }

    void dequeue()
    {
        if(front == -1 & rear == -1)
        {
            cout <<"\nQUEUE IS EMPTY!";
            return;
        }

        cout << arr[front] <<" HAS BEEN DEQUEUED!\n";
        front++;
        if(front>rear)
        front=rear=-1;
    }

    void peak()
    {
        if(front == -1 & rear == -1)
        {
            cout <<"\nQUEUE IS EMPTY!";
            return;
        }

        cout << "\nPEAK: "<< arr[front];

    }


};

int main()
{
    queue Q;
    int choice;
    int val;

    do
    {
        cout << "\n\nENTER\n1-->ENQUEUE\n2-->DEQUEUE\n3-->PEAK\n4-->EXIT\n";
        cin >> choice;

        switch(choice)
        {
            case 1: 
            cout << "\nENTER VALUE TO ENQUEUE: ";
            cin >> val;
            Q.enqueue(val);
            break;

            case 2:
            Q.dequeue();
            break;

            case 3:
            Q.peak();
            break;

            case 4:
            cout <<"\nEXITING...\n";
            break;

            default:
            cout << "\nINVALID INPUT!";
        }
    }while(choice!=4);
    return 0;
}