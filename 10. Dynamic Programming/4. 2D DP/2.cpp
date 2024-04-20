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

int dp[300][10010];

int func(int ind, int amount, vector<int>& coins){
    int ways = 0;
    if(amount == 0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][amount] != -1) return dp[ind][amount];
    for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]){
            ways += func(ind - 1, amount - coin_amount, coins);
    }
    return dp[ind][amount] = ways;
}

int coinChange(vector<int>& coins, int amount) {
        int ans = func(coins.size() - 1, amount, coins);
        return ans;
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