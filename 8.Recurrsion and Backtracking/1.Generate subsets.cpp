#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define endl "\n"

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int k=1; k<=t; k++){
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int ans = 0;
        int len = 1;
        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1]){
                len++;
            }
            else{
                ans += len*(len+1)/2; len = 1;
            }
        }
        cout << "Case " << k << ": " << n*(n+1)/2 - ans - 1<< endl;
    }
}