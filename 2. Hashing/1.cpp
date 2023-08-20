/*
Given q queries, count no. of n in an array
1 <= N <= 10^5
a <= a[i] <= 10^7
1 <= Q <= 10^*5
*/
// maximum array size in global 10^7
// so we can do hash here
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int hsh[N];
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        hsh[arr[i]]++;//pre-computation
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << hsh[x] << "\n";
    }
}