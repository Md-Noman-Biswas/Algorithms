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
int wt[105], val[105];

ll dp[105][N];

ll func(int ind, int wt_left){
    //wt finished
    if(wt_left == 0) return 0;

    //took all but still wt left
    if(ind < 0) return 0;

    if(dp[ind][wt_left] != -1) return dp[ind][wt_left];

    //not take
    ll ans = func(ind - 1, wt_left);
    //take
    if(wt_left - wt[ind] >= 0)
        ans = max(func(ind - 1, wt_left - wt[ind]) + val[ind], ans);

    return dp[ind][wt_left] = ans;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    cout << func(n - 1, w) << nl;
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