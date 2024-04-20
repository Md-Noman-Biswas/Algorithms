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

vector<int> a(N);
int dp[N];


//O(N^2)
int lis(int i){
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = 0; j < i; j++){
        if(a[i] > a[j]){
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}

void solve(){
    memset(dp, -1, sizeof(dp)); 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, lis(i));
    }
    cout << ans << nl;
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