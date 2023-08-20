#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prefixsum(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++){
        prefixsum[0] = arr[0];
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }
    int m;
    cin >> m;
    int worms;
    while(m--){
        cin >> worms;
        auto it = lower_bound(prefixsum.begin(), prefixsum.end(), worms);
        cout << (it - prefixsum.begin()) + 1 << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}