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
const int N = 1e5 + 1;


int n, m;
ll dist[N];

vector<pair<int, ll>> adj[N];
vector<int> parent[N];


void dijkstra(int src, int dest) {

    for(int i = 1; i <= n; i ++) {
        dist[i] = LONG_LONG_MAX;
    }

    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({0, src});

    while (!frontier.empty()) {

        ll d = frontier.top().first;
        int v = frontier.top().second;
        frontier.pop();

        if(dist[v] != d || v == dest) continue;

        for(auto u : adj[v]) {
            if(u.second + d < dist[u.first]) {
                dist[u.first] = u.second + d;
                parent[u.first].clear();
                parent[u.first].push_back(v);
                frontier.push({dist[u.first], u.first});

            } else if(u.second + d == dist[u.first]) {
                parent[u.first].push_back(v);
            }

        }

    }
}


ll minFlight[N];
ll maxFlight[N];
int totalRoutes[N];

void dfs(int v) {


    if(totalRoutes[v]) return;
    if(v == 1) {
        minFlight[v] = 0;
        maxFlight[v] = 0;
        totalRoutes[v] = 1;
        return;
    }

    for(auto u : parent[v]) {
        dfs(u);
        totalRoutes[v] = (totalRoutes[v] + totalRoutes[u]) % 1000000007;
        minFlight[v] = min(minFlight[v], minFlight[u] + 1);
        maxFlight[v] = max(maxFlight[v], maxFlight[u] + 1);
    }
}

void solve() {

    cin >> n >> m;
    for(int i = 1; i <= m ; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra(1, n);

    for(int i = 1; i <= n; i ++) {
        minFlight[i] = LONG_LONG_MAX;
        maxFlight[i] = LONG_LONG_MIN;
    }
    dfs(n);
    cout << dist[n] << ' ' << totalRoutes[n] << ' ';
    cout << minFlight[n] << ' ' << maxFlight[n] << endl;

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
