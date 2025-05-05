#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    int tcases;
    cin >> tcases;
    while(tcases--){
        int n;
        cin >> n;
        int i;
        vector<int> a(n);
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max_count = 0;
        for(i=0;i<n;i++){
            if(a[i] > max1){
                max2 = max1;
                max1 = a[i];
                max_count = 1;
            }
            else if(a[i] == max1){
                max_count += 1;
            }
            else if(a[i] > max2){
                max2 = a[i];
            }
        }
        for(i=0;i<n;i++){
            if(a[i] == max1 && max_count == 1){
                cout << max1-max2 << " ";
            }
            else{
                cout << a[i]-max1 << " ";
            }
        }
    }
}