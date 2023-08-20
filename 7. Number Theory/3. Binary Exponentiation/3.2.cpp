#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;//M is prime here
int binExpIter(int a, long long b, int m){
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


int main(){
    //50^64^32
    cout << binExpIter(50, binExpIter(64,32,M-1), M);;
}