// program to implement circular queue ADT
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace  std ;

#define size 5

class Queue 
{
    private:
       int arr[size] ;
       int front ;
       int rear ;

    public:

        Queue()
        {
            front = -1 ;
            rear = -1 ;
        }
        void Enqueue(int ele);
        void Dequeue();
        void Peek();
        
};

int main()
{
    Queue queue ;
    int n , choice ;
    int arr[size] ;
    do 
    {
        printf("\n    Menu    \n");
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Peek \n");
        printf("4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
        case 1:
        int ele ;
        printf("Enter the element : ");
        scanf("%d",&ele);
        queue.Enqueue(ele);
        break ;
        case 2 :
        queue.Dequeue();
        break ;
        case 3 :
        queue.Peek();
        break ;
        case 4 :
        printf("Exiting program");
        break ;
        default : 
        printf("Please enter valid input");
        }
    }
    while (choice!=4);
}
    


// functions 

//1.Enqueue
void Queue :: Enqueue(int ele)
{
    if (rear==size-1)
    {
        printf("queue is full");
    }
    else
    {   if (front== -1)
        front = 0 ;
        rear = (rear+1)%size ;
        arr[rear] = ele ;
    }
}

//2.Dequeue 
void Queue::Dequeue()
{
    if (rear == -1 || front == -1)
    {
        printf("Queue is empty") ;
    }
    else 
    {
        printf("%d",arr[front]);
        if (front==rear)
        {
            front = rear = -1 ;
        }
        else
        {
            front = (front+1)%size ; 
        }
        
    }
}

//3.Peek 
void Queue::Peek()
{
    if (rear == -1 || front == -1)
    {
        printf("Queue is empty") ;
    }
    else 
    {
        printf("%d",arr[front]);
    }
}
