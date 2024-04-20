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

bool dfs(int node, vector<int> adj[], int vis[], int path_vis[]){
    vis[node] = 1;
    path_vis[node] = 1;
    for(auto child: adj[node]){
        if(!vis[child]){
            if(dfs(child, adj, vis, path_vis) == true){
                return true;
            }
        }
        //if previously visited
        else if(path_vis[child]){
            return true;
        }
    }
    path_vis[node] = 0;
    return false;
}

bool isCyclic(int v, vector<int> adj[]){
    int vis[v] = {0};
    int path_vis[v] = {0};
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, path_vis) == true){
                return true;
            }
        }
    }
    return false;
}


void solve(){
    
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