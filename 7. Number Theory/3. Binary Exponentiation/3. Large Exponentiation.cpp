#include<bits/stdc++.h>
using namespace std;
const int M = 1e18 + 7;
int binMultiply(long long a, long  long b){
    int ans = 0;
    while(b){
        if(b&1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b = b >> 1; 
    }
    return ans;
}
int binExpIter(int a, int b){
    int ans = 1;
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
    int a, b;
    cin >> a >> b;
    cout << binExpIter(a,b);
}