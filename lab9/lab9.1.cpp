#include<iostream>
#include<vector>
using namespace std;

int main(){
    int tcases;
    cin >> tcases;
    while(tcases--){
        int k;
        cin >> k;
        int q;
        cin >> q;
        int i;
        vector<int> a(k);
        for(i=0;i<k;i++){
            cin >> a[i];
        }
        for(i=0;i<q;i++){
            int n;
            cin >> n;
            if(n == 0){
                cout << 0 << " ";
            }
            else if(n < a[0]){
                cout << n << " ";
            }
            else{
                cout << a[0]-1 << " ";
            }
        }
    }
}