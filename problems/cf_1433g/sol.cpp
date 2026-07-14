#include <bits/stdc++.h>

using namespace std;

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define ll long long
const int N = 1e3 + 1;

int n, m, k;
vector<pair<int, int>> adj[N];
int dist[N][N];

void dijkstra(int src) {

    for(int i = 1; i <= n; i ++) {
        dist[src][i] = INT_MAX;
    }
    dist[src][src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> frontier;
    frontier.push({0, src});

    while (!frontier.empty()) {
        int v = frontier.top().second;
        int d = frontier.top().first;
        frontier.pop();

        if(dist[src][v] != d) continue;
        for(auto u : adj[v]) {
            if(u.second + d < dist[src][u.first]) {
                dist[src][u.first] = u.second + d;
                frontier.push({dist[src][u.first], u.first});
            }
        }
    }

}



void solve() {

    cin >> n >> m >> k;
    vector<pair<int, int>> edges;

    for(int i = 1; i <= m ; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b});
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<pair<int, int>> routes;
    for(int i = 1; i <= k ; i++) {
        int u, v;
        cin >> u >> v;
        routes.push_back({u, v});
    }

    for(int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    ll currentMax = INT_MAX;
    for(auto edge : edges) {
        ll total = 0;
        for(auto route : routes) {
            int shortestPath = INT_MAX;
            shortestPath = min(dist[route.first][route.second], dist[route.first][edge.first] + dist[edge.second][route.second]);
            shortestPath = min(shortestPath, dist[route.first][edge.second] + dist[edge.first][route.second]);
            total += shortestPath;
        }
        currentMax = min(currentMax, total);
    }
    cout << currentMax << endl;

}

int main() {
    setup_io();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
