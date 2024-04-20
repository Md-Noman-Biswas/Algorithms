#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000;
vector<bool> isPrime(N+10, 1);
void solve(){
    isPrime[0] = false;
    isPrime[1] = true;
    for(int i=2; i<=N; i++){
        if(isPrime[i] == true){
            for(int j = 2*i; j<N; j+=i){
                isPrime[j] = false;
            }
        }
    }
    int x;
    cin >> x;
    for(int i=0; i<=x; i++){
        if(isPrime[i] == true){
            cout << i << "\n";
        }
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    solve();
    }
 
    return 0;
}