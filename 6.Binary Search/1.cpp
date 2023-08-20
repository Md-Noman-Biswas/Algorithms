//binary search only applicable on monotonic.
//on predicate function
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int to_find;
    cin >> to_find;
    int l=0, h=n-1;
    int mid;
    while(h-l > 1){
        int mid = (h+l)/2;
        if(arr[mid] < to_find){
            l = mid + 1;
        }else{
            h = mid;
        }
    }
    if(arr[l] == to_find){
        cout << l << "\n";
    }
    else if(arr[h] == to_find){
        cout << h << "\n";
    }else{
        cout << "not found" << "\n"; 
    }
}