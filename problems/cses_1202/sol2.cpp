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
const int MOD = 1e9 + 7;

int n, m;
ll dist[N];
vector<pair<int, ll>> adj[N];
ll minFlight[N];
ll maxFlight[N];
int totalRoutes[N];


void dijkstra(int src, int dest) {

    for (int i = 1; i <= n; i++) {
        dist[i] = LONG_LONG_MAX;
    }

    dist[src] = 0;
    totalRoutes[src] = 1;
    minFlight[src] = 0;
    maxFlight[src] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({ 0, src });

    while (!frontier.empty()) {

        ll d = frontier.top().first;
        int v = frontier.top().second;
        frontier.pop();

        if (dist[v] != d) continue;

        for (auto u : adj[v]) {
            if (u.second + d < dist[u.first]) {

                dist[u.first] = u.second + d;
                frontier.push({ dist[u.first], u.first });

                minFlight[u.first] = minFlight[v] + 1;
                maxFlight[u.first] = maxFlight[v] + 1;
                totalRoutes[u.first] = totalRoutes[v];
            }
            else if (u.second + d == dist[u.first]) {
                minFlight[u.first] = min(minFlight[u.first], minFlight[v] + 1);
                maxFlight[u.first] = max(maxFlight[u.first], maxFlight[v] + 1);
                totalRoutes[u.first] = (totalRoutes[u.first] + totalRoutes[v]) % MOD;

            }

        }

    }
}



void solve() {

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    dijkstra(1, n);
    cout << dist[n] << ' ' << totalRoutes[n] << ' ' << minFlight[n] << ' ' << maxFlight[n] << endl;


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
