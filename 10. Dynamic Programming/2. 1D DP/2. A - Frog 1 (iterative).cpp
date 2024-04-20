#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define llmx LONG_LONG_MAX
#define llmn LONG_LONG_MIN
#define mod 1000000007
const int N = 1e5 + 7;
const int INF = 1e9 + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) cin >> h[i];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int cost = dp[i - 1] + abs(h[i - 1] - h[i]);
        if(i > 1) cost = min(cost, dp[i - 2] + abs(h[i - 2] - h[i]));
        dp[i] = cost;
    }   
    cout << dp[n - 1] << nl;
}

/* Hey you should check this out
    * int overflow, array bounds
    * reset global array and variable
    * look for special cases (n=1?)
    * do something instead of nothing and stay organized
    * bruteforce to find pattern
    * DON'T GET STUCK ON ONE APPROACH
    * Think the problem backwards
    * In practice time don't see failing test case
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}