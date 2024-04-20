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

bool isBipartite(int v, vector<vector<int>>& adj){
    queue<int> q;
    q.push(0);
    vector<int> color(v, -1);
    color[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            //if adjacent node if not yet colored.
            //color it with oposite color
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            //if it has been colored
            //if it has the same color
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
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