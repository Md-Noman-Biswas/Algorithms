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

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, node});
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    ll n;
    cin >> n;
    vector<int> adj[n];
    int vis[n] = {0};
    for(int i = 0; i < n; i++){
        if(!vis[i]){//for connected components
            if(detect(i, adj, vis) == true){
                //contains cycle
            }  
        }
    }

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