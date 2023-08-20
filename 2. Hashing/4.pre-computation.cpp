#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> arr(n+10,0);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    vector<ll> forward(n+10,0);
    vector<ll> backward(n+10,0);
    for(int i=1; i<=n; i++){
        forward[i] = __gcd(forward[i-1], arr[i]);
    }
    for(int i=n; i>=1; i--){
        backward[i] = __gcd(backward[i+1], arr[i]);
    }
    while(q--){
        ll l,r;
        cin >> l;
        cin >> r;
        cout << __gcd(forward[l-1], backward[r+1]) << "\n";

    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}