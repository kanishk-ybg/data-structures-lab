#include <stdio.h>
#include <cstdlib>

void print_array(int*a , int siz);
void selection_sort(int* a , int siz);
void bubble_sort(int* a , int siz);
void insertion_sort(int* a , int siz);
void print_array(int*a , int siz);

int menu()
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




    while(1){
        printf("1   BUBBLE SORT \n2   SELECTION SORT\n3   INSERTION SORT\n4   EXIT\n");
        int choice;
        printf("enter choice    ");
        scanf("%d" , &choice) ;    

        switch (choice){
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

            
            case 4:
                return 0;
                break;
        }
        



}
}

/*
int main(){
    menu();
    return 0;
}
*/

    


void selection_sort(int*a , int siz)
{
    for(int i=0; i<siz ; i++)
    {
        int min_idx=i;
        for (int j=i+1 ; j<siz ; j++)
        {
            if (a[min_idx] > a[j])
            {
                min_idx=j;
            }
        }
        int temp=a[i];
        a[i]=a[min_idx];
        a[min_idx]=temp;
    }
}


void bubble_sort(int*a , int siz)
{
    for(int i=0; i<siz-1 ; i++)
    {
        for (int j=0;j<siz-1-i; j++)
        {
            if (a[j+1] <a[j]){
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
        }

    }


void insertion_sort(int*a , int siz)
{
    for(int i=1; i<siz ; i++)
    {
        int temp=a[i];
        int d=i-1;
        while(d>=0 && temp < a[d])
        {
              
            
            a[d+1]=a[d];

            d--;
        }
        a[d+1]=temp;
        }

    }



void print_array(int*a , int siz)
{
    for(int i=0; i<siz ; i++)
    {
        printf("%d   " , a[i]);
    }
    puts("");
}