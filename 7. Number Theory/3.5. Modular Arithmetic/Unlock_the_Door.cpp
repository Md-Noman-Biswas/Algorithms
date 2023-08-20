#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int binExp(int a, int b, int m){
    int result = 1;
    while(b>0){
        if(b&1){
        result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
/*
alphabate = k
symbols = n
k > n
suppose n letters has been picked
up form n = a,b,c --> 3*2*1 --> n!
from k we can pick up n in kCn ways;
so answer = n! * kCn
kCn = k!/(k-n)!*n!
*/
const int N = 1e5+10;
int fact[N];
int main(){
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1] * 1LL * i) % M;
    }
    while(t--){
        int n,k;
        cin >> n >> k;
        int ans = fact[n];
        ans = (ans *1LL * fact[k]) % M;
        int den = (fact[k-n] *1LL * fact[n]) % M;
        int denInverse = binExp(den, M-2, M);
        ans = (ans * 1LL * denInverse) % M;
        cout << ans << "\n";
    }
    //TC = T*O(log(n)) + O(n)

}