// Program to implement queue using linkedlist 
#include <iostream>
using namespace std;

class Queue 
{
    private :

     struct Node
    {   
        int data ;
        struct Node *next ; 
        
    };
        Node *front ; 
        Node *rear ;
    public : 
      Queue()
      {
        front = NULL ;
        rear = NULL ;
      }
      void Enqueue(int ele);
      void Dequeue();
      void Peek();

};  


int main()
{
    Queue queue ;
    int  choice ;
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

// Functions defintions 

// 1.Enqueue 
void Queue::Enqueue(int ele)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = ele ;
    newnode->next = NULL ;
    if (rear==NULL) 
    {
        rear = front = newnode ;
    }
    else
    {
        rear->next = newnode ;
        rear = newnode ;
    }
}

// 2. Dequeue 
void Queue::Dequeue()
{   
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else 
    {
        Node *temp = front ; 
        printf("%d",front->data);
        front = front->next ;
        if (front == nullptr) 
        {
            rear = nullptr; 
        }
        delete temp;
    }
}

// 3. Peek 
void Queue::Peek()
{ 
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("%d",front->data);
    }
}