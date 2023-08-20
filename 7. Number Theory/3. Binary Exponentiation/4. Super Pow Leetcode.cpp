#include<bits/stdc++.h>
using namespace std;
int binExpIter(int a, long long b, int m){
    a %= m;
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL *a) % m;
        b = b >> 1;
    }
    return ans;
}
int arrToNum(vector<int> &arr){
    int bmod = 0;
    for(int val: arr){
        bmod = (bmod * 10 + val) % 1140;
    }
    return bmod;
}
int main(){
    int a; cin >> a;
    int r; cin >> r;
    vector<int> b(r);
    for(int i=0; i<r; i++) cin >> b[i];
    cout << binExpIter(a, arrToNum(b), 1337);
}