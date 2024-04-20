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
const int N = 510;
const int INF = 1e9 + 10;

int dist[N][N];

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void solve(){
    init();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF){
                cout << "I ";
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << nl;
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