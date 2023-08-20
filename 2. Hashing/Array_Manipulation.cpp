#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+10;
ll int arr[N];
void solve(){
    ll n, q;
    cin >> n >> q;
    while(q--){
        int l,r,v;
        cin >> l >> r >> v;
        arr[l] += v;
        arr[r+1] -= v;
    }
    for(int i=1; i<=n; i++){
        arr[i] += arr[i-1];
    }
    long long mx = -1;
    for(int i=1; i<=n; i++){
        if(mx < arr[i]){
            mx = arr[i];
        }
    }
    cout << mx << "\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}