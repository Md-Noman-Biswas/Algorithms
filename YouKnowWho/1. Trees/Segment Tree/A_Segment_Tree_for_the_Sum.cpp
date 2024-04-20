#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define llmx LONG_LONG_MAX
#define llmn LONG_LONG_MIN
#define mod 1000000007
const int N = 1e6 + 7;

ll arr[N];
ll t[N * 4];

void build(ll node, ll b, ll e){
    if(b == e){
        t[node] = arr[b];
        return;
    }
    ll l = 2 * node;
    ll r = 2 * node + 1;
    ll mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = t[l] + t[r];
}

ll query(ll node, ll b, ll e, ll i, ll j){
    if(e < i || b > j) return 0;
    if(b >= i && e <= j) return t[node];
    ll l = 2 * node;
    ll r = 2 * node + 1;
    ll mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

void update(ll node, ll b, ll e, ll i, ll x){
    if(b > i || e < i) return;
    if(i == b && i == e){
        t[node] = x;
        return;
    }
    ll l = 2 * node;
    ll r = 2 * node + 1;
    ll mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    t[node] = t[l] + t[r];
}

void solve(){
    ll n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while(q--){
        ll task;
        cin >> task;
        if(task == 1){
            ll i, x;
            cin >> i >> x;
            update(1, 1, n, i + 1, x);
        }else{
            ll i, j;
            cin >> i >> j;
            cout << query(1, 1, n, i + 1, j) << nl;
        }
    }
}

/* Hey you should check this out
    * int overflow, array bounds
    * reset global array and variable
    * look for special cases (n=1?)
    * do something instead of nothing and stay organized
    * bruteforce to find pattern
    * DON'T GET STUCK ON ONE APPROACH
    * Think the problem backwards
    * In practice time don't see failing test case
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}