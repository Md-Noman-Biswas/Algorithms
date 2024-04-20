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

vector<int> topoSort(int v, vector<int> adj[]){
    int indegree[v] = {0};
    for(int i = 0; i < v; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    //O(v + e)
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        //node was on the queue.
        //so remove the indegree of adjacents
        for(auto child: adj[node]){
            indegree[child]--;
            if(indegree[child] == 0) q.push(child);
        }
    }
    return ans;
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