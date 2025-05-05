#include <stdio.h>
#include <cstdlib>
#include "sorting.h"


void bin_search(int* a , int siz , int data)
{
    int ub=siz-1;
    int lb=0;
    int mid=(ub+lb)/2;
    while (ub>=lb)
    {
        if (data >a[mid]) 
        {
            lb=mid+1;
        }
        else if (data <a[mid]) 
        {
            ub=mid-1;
        }
        else{
            printf("data found at %d index\n\n" , mid);
            return;
        }   
        mid=(ub+lb)/2;
    }
    printf("data not found ");
    return;
}

void linear_search(int *arr, int size, int target) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("found at %d \n",i);
            return; 
    }

}
    printf("not found\n"); 
    return;
}


int main()
{
    int siz;
    printf("enter array size:  ");
    scanf("%d" , &siz);
    int arr[siz];

    for (int i=0 ; i<siz ; i++)
    {
        int tmp;
        printf("enter array contents :");
        scanf("%d" , arr+i);
        
    }

    printf("SEARCHING  \n");
    printf("enter data to search:   ");
    int data;
    scanf("%d",&data);



    while(1){
        printf("1- Linear Search \n 2- Binary Search\n3- Exit\n\n");
        printf("enter choice:   ");
        int choic;
        scanf("%d",&choic);


            switch (choic)
            {
                case 1:
                    print_array(arr,siz);
                    linear_search(arr ,siz ,data );
                    break;


                case 2: 


                    printf("choose a sorting method");


                    printf("1   BUBBLE SORT \n2   SELECTION SORT\n3   INSERTION SORT\n4   EXIT\n");
                    int choice;
                    printf("enter choice    ");
                    scanf("%d" , &choice);
                    switch (choice)
                    {
                        case 1:
                            printf("sorting with bubble sort         ");
                            bubble_sort(arr,siz);
                            print_array(arr,siz);
                            break;
                        case 2:
                            printf("sorting with selection sort      ");
                            selection_sort(arr,siz);
                            print_array(arr,siz);

                            break;
                        case 3:
                            printf("sorting with insertion sort      ");
                            insertion_sort(arr,siz);
                            print_array(arr,siz);
                            break;

                    }

                    bin_search(arr,siz,data);
                    break;

                case 3:
                    return 0;
                    break;







            }
}}