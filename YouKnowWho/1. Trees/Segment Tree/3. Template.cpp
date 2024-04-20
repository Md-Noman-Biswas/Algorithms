#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int a[N];//populate it in main function
long long t[4 * N];
#define lc (n << 1)//2n
#define rc ((n << 1) | 1)//2n + 1

inline long long combine(long long a,long long b) {
    return a + b;
}

inline void pull(int n) {
    t[n] = t[lc] + t[rc];
}

void build(int n, int b, int e) {
    if (b == e) {
        t[n] = a[b];
    return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
}

// void update(ll node, ll b, ll e, ll i, ll x){
//     if(b > i || e < i) return;
//     if(i == b && i == e){
//         t[node] = x;
//         return;
//     }
//     int l = 2 * node;
//     int r = 2 * node + 1;
//     int mid = (b + e) / 2;
//     update(l, b, mid, i, x);
//     update(r, mid + 1, e, i, x);
//     t[node] = t[l] + t[r];
// }

void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (i == b && e == i) {
        t[n] = x;
        return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, x);
    upd(rc, mid + 1, e, i, x);
    pull(n);
}

long long query(int n, int b, int e, int i, int j) {
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
}

/*  //example:
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    cout << query(1, 1, n, 1, 5) << "\n";

    upd(1, 1, n, 1, 0);
    cout << query(1, 1, n, 1, 5) << "\n";
*/

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    cout << query(1, 1, n, 1, 5) << "\n";

    upd(1, 1, n, 1, 0);
    cout << query(1, 1, n, 1, 5) << "\n";
}
