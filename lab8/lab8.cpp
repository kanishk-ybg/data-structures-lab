#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cout<<"\n enter number of test cases\n";
    cin>>t;
    while(t--){
    
        int n;
        cout <<"\n enter number of towers\n";
        cin >> n;
    
     vector <int> a(n);
     cout << "\n Enter number of blocks in wach tower\n";
     for(int i=0;i<n;i++)
     {
        cin >>a[i];
     }
    int x =a[0];

    vector<int> b(a.begin()+1,a.end());
    sort(b.begin(),b.end());

    for(int y:b){
        if(y>x)
        {

            
            if((x+y)%2==0)
                x=(x+y)/2;
            else
                x=((x+y)/2)+1;
        }
    }
    cout<< "\n Maximum number of blocks: "<<x;
}
}