// program to find the number of deletions needed to make a list of numbers have only unique elements


#include <iostream>
#include <unordered_map>
using namespace std;

int solve()
{
    int n;
    cout <<"Enter number of elements:   ";
    cin>>n;
    int temparrsize=n;
    int arr[n];

    unordered_map<int ,int> freq;


    for (int i=0; i<n ; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int i=0;
    while (freq.size() != n )
    {
        freq[arr[i]]--;
        if (freq[arr[i]]==0)
        {
            freq.erase(arr[i]);
        }
        i++;
        n--;

    }

    cout<< temparrsize - n<<endl <<endl ;
    return 0;
}


int main()
{
    int tc;
    cout<<"Enter Number of Testcases:   ";
    cin >>tc;

    for (int i=0; i<tc ; i++)
    {
        cout<<"******* Test Case " << i+1 << " *******"<<endl<<endl ;
        solve();
    }

}