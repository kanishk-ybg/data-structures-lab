#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap{
    private:
    vector <int> heap;

    void heapifyUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[index]>heap[parent]){
                swap(heap[index],heap[parent]);
                index=parent;
            }
            else{
                break;
            }
        }
    }

    void heapifyDown(int index)
{
    int size=heap.size();
    while(index<size){
        int left=2*index+1;
        int right=2*index+2;
        int largest=index;
        if(left<size && heap[left]>heap[largest]){
            largest=left;
        }
        if(right<size && heap[right <heap[largest]]){
            largest=right;
        }
        if(largest!=index){
            swap(heap[index],heap[largest]);
            index=largest;
        }
        else{
            break;
        }
    }
}

public:
void insert(int value){
    heap.push_back(value);
    heapifyUp(heap.size()-1);
}

void deleteMax(){
    if(heap.empty()){
        cout << "HEAP IS EMPTY!" << endl;
        return;
    }

    swap(heap[0],heap.back());
        heap.pop_back();
        heapifyDown(0);
}

void display(){
    for(int val : heap){
        cout << val << " ";
    }
    cout << endl;
}

bool search(int value){
    return find(heap.begin(),heap.end(),value)!=heap.end();
}

void heapSort(){
    vector<int>temp=heap;
    sort(temp.begin(),temp.end(),greater<int>());
    cout << "SORTED ELEMENTS: ";
    for(int val:temp){
        cout<<val<<" ";
    }
    cout << endl;
}
};

int main(){
    MaxHeap pq;
    int choice,value;

    do{
        cout <<"1->INSERT 2->DELETE 3->DISPLAY 4->SEARCH 5->SORT 6->EXIT\n";
        cin >>choice;
        switch(choice){
            case 1: cout <<"enter value";
            cin >> value;
            pq.insert(value);
            break;

            case 2: pq.deleteMax();
            break;

            case 3:
            pq.display();
            break;

            case 4:
            cout << "enter value";
            cin >> value;
            cout <<(pq.search(value)?"FOUND! ":"NOT FOUND! ")<<endl;
            break;

            case 5:
            pq.heapSort();
            break;

            case 6:
            cout<<"EXITING...";
            break;

            default:
            cout<<"INVALID";
        }
        
    }while(choice!=6);
}
