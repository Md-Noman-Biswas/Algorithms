#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000000];
void seive(){
    for(int i=2; i<=1000000; i++){
        if(arr[i] == 0){
            for(int j=2; i*j <= 1000000; j++){
                arr[i*j] = 1;
            }
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    ll xrr[n];
    for(ll i=0; i<n; i++){
        cin >> xrr[i];
    }
    seive();
    for(int i=0; i<n; i++){
        ll temp = sqrt(xrr[i]);
        if(xrr[i] == 1){
            cout << "NO" << "\n";
        }
        else if(temp*temp == xrr[i] && arr[temp] == 0){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}