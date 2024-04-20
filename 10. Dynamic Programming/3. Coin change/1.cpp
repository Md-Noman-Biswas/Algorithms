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

int dp[N];

int func(int amount, vector<int>& coins){
    int ans = INF;
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];
    for(int coin: coins){
        if(amount - coin >= 0)
            ans = min(ans, func(amount - coin, coins) + 1);
    }
    return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount) {
        int ans = func(amount, coins);
        return ans == INF ? -1 : ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << coinChange(arr, 11) << nl;
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