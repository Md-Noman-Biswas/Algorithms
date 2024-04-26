#include <bits/stdc++.h>
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

vector<pair<int, int>> adj[N];
vector<int> dist(N, INF);
vector<int> vis(N, 0);

void dijkstra(int source, int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop(); // Pop the element from the priority queue
        for (auto child : adj[node]) {
            int wt = child.second;
            int adjnode = child.first;
            if (distance + wt < dist[adjnode]) {
                dist[adjnode] = distance + wt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
    }

    // Call Dijkstra's algorithm
    dijkstra(1, n);

    // Print the shortest distances
    for (int i = 1; i <= n; i++) {
        cout << "Shortest distance from node 1 to node " << i << " is " << dist[i] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
