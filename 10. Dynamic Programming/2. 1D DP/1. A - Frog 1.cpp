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

//O(n)
int func(int i){
    if(i == 0) return 0;
    int cost = INT_MAX;
    if(dp[i] != -1) return dp[i];
    
    //way1
    cost = min(cost, func(i - 1) + abs(h[i] - h[i - 1]));
    //way2
    if(i > 1) cost = min(cost, func(i - 2) + abs(h[i] - h[i - 2]));
    return dp[i] = cost;
}


void solve(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
    cout << func(n - 1) << nl;
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