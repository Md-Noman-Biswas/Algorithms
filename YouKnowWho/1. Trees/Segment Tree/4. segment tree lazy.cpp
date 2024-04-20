#include<bits/stdc++.h>
using namespace std;

const int N = 3e5;

int a[N];//populate it in main function
long long t[4 * N], lazy[4 * N];
#define lc (n << 1)//2n
#define rc ((n << 1) | 1)//2n + 1

inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if (b != e) {
    lazy[lc] = lazy[lc] + lazy[n];
    lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
}

inline long long combine(long long a,long long b) {
    return a + b;
}

inline void pull(int n) {
    t[n] = t[lc] + t[rc];
}

void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
        t[n] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
}

void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
        lazy[n] += v; //set lazy
        push(n, b, e);
        return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
}

long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
}

/*  //example:
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cout << query(1, 1, n, 2, 4) << "\n";
    upd(1, 1, n, 2, 4, 2);
    cout << query(1, 1, n, 2, 4) << "\n";
*/

int32_t main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cout << query(1, 1, n, 2, 4) << "\n";
    upd(1, 1, n, 2, 4, 2);
    cout << query(1, 1, n, 2, 4) << "\n";
}