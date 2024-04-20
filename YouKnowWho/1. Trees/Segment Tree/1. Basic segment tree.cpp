#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
#define ll long long

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
    int l = 2 * node;
    int r = 2 * node + 1;
    int mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    t[node] = t[l] + t[r];
}


int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    //1 2 3 4 5
    build(1, 1, n);
    cout << t[1] << "\n";
    cout << query(1, 1, n, 2, 4) << "\n";
    update(1, 1, n, 3, 10);
    //1 2 10 4 5
    cout << query(1, 1, n, 2, 4) << "\n";
}