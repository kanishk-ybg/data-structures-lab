#include<stdio.h>
//programming to sort the elements 
#include"header.h"


int main() 
{  
   int arr[] = {45,32,44,2,4,5};
   int n = sizeof(arr)/sizeof(arr[0]);

    int number;
    printf("Choose the number from the following menu :\n");
    printf("1.Bubblesort\n2.Selectionsort\n3.Insertionsort\n4.Exit\n");
    scanf("%d", &number);

    if(number == 1)
    {
        bubblesort(arr,n);  //bubblesort function from the header file 
        for(int i = 0 ; i< n ; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    if(number == 2)
    {
        selectionsort(arr,n);  // selectionsort function from the header file
        for(int i=0 ; i<n ; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

   if(number == 3)
   {
     insertionsort(arr,n);  //insertion sort function from the header file 
     for( int i=0 ; i<n ; i++)
     {
        printf("%d ", arr[i]);
     }
     printf("\n");

   }

   if(number == 4)
   {
    printf("Exiting the program.....\n");
    return 0;
   }


    return 0;
}
