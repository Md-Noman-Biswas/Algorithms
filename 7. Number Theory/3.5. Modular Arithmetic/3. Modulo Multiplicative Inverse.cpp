 #include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

//b^-1 = binExp(b,m-2,m);
int binExp(int a, int b, int m){
    int result = 1;
    while(b){
        if(b&1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
/*
There are N children and k toffees. k<N.
count the number of ways to distribute toffee
among N students such that each students get 
1 toffee only 
--> nCk, % M, M = 10^9 + 7
N < 10^6, K < N < 10^6
Q = 10^5
n ! / ((n-r)! * r!)
*/
const int N = 1e6 + 10;
int fact[N];
int main(){
    fact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = (fact[i-1] * 1LL * i) % M;
    }
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        int ans = fact[n];
        int den = (fact[n-k] * 1LL * fact[k]) % M;
        ans = ans * binExp(den, M-2, M);
        cout << ans << "\n";
    }
    //modulo inverse is necessary here to avoid tle
    //due to large num of queries.
    //also precomputation of factorial
}