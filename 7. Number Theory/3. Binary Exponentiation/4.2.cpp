#include<bits/stdc++.h>
using namespace std;
long long arrToNum(vector<int> &arr){
    long long bmod = 0;
    for(int val: arr){
        bmod = (bmod * 10 + val);
    }
    return bmod;
}
void div(long long n){
    n /= 2;
}
int binExpIter(int a, long long b, int m){
    a %= m;
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL *a) % m;
        b = b/2;
    }
    return ans;
}
int main(){
    int a; cin >> a;
    int r; cin >> r;
    vector<int> b(r);
    for(int i=0; i<r; i++) cin >> b[i];
    long long p = arrToNum(b);
    cout << binExpIter(a, p, 1337) << "\n";
}