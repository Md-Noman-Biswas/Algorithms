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

int h[N];
int dp[N];

//O(n * k)
int func(int i, int k){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(i - j < 0) break;
        cost = min(cost, func(i - j, k) + abs(h[i] - h[i - j])); 
    }
    return dp[i] = cost;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];
    cout << func(n - 1, k) << nl;
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