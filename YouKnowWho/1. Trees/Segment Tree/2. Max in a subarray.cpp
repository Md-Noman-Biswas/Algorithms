#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int arr[N];
int t[N * 4];

void build(int node, int b, int e){
    if(b == e){
        t[node] = arr[b];
        return;
    }
    int l = 2 * node, r = 2 * node + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    //gcd can also be done like this
    //just use __gcd(t[l], t[r]) here
    //and in related places
    t[node] = max(t[l], t[r]);
}

int query(int node, int b, int e, int i, int j){
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return t[node];
    int l = 2 * node, r = 2 * node + 1; 
    int mid = (b + e) / 2;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void update(int node, int b, int e, int i, int x){
    if(b > i || e < i) return;
    if(b == e and b == i){
        t[node] = x;
        return;
    }
    int l = 2 * node, r = 2 * node + 1; 
    int mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    t[node] = max(t[l], t[r]);
}


int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    //1 2 3 4 5
    build(1, 1, n);
    cout << query(1, 1, n, 3, 4) << "\n";
    update(1, 1, n, 3, 10);
    cout << t[1] << "\n";
    //1 2 10 4 5
    cout << query(1, 1, n, 2, 4) << "\n";
}