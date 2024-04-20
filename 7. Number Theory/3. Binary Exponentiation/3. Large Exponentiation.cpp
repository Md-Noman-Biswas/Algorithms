#include<bits/stdc++.h>
using namespace std;
const long long M = 1e18 + 7;
long long binMultiply(long long a, long  long b){
    long long ans = 0;
    while(b){
        if(b&1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b = b >> 1; 
    }
    return ans;
}
long long binExpIter(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b&1){
            ans = binMultiply(ans,a);
        }
        a = binMultiply(a,a);
        b = b >> 1;
    }
    return ans;
}
//TC Log^2(n) cause 2 log(n) loops
int main(){
    long long a, b;
    cin >> a >> b;
    cout << binExpIter(a,b);
}