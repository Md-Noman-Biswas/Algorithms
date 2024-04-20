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
//dfs
bool dfs(int node, int col, int color[], vector<vector<int>>& adj){
    color[node] = col;
    for(auto it: adj[node]){
        if(color[it] == -1){
            dfs(it, !col, color, adj);
        }
        else if(color[it] == col){
            return false;
        }
    }
    return true;
}

void solve(){
    int v;
    vector<vector<int>> adj;
    //take input
    int color[v] = {-1};
    bool flag = true;
    for(int i = 0; i < v; i++){
        if(color[i] == -1){
            if(dfs(i, 0, color, adj) == false){
                flag = false;
                break;
            }
        }
    }
    if(!flag) NO;
    else YES;
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