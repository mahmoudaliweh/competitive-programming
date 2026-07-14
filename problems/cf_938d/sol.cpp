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
const int N = 2 * 1e5 + 1;

int n, m;
vector<pair<int, ll>> adj[N];
ll dist[N];

void dijkstra() {

    for(int i = 1; i <= n; i ++) {
        dist[i] = LONG_LONG_MAX;
    }
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({0, 0});

    while (!frontier.empty()) {
        int v = frontier.top().second;
        ll d = frontier.top().first;
        frontier.pop();

        if(d != dist[v]) continue;

        for(auto u : adj[v]) {
            if(u.second + d < dist[u.first]) {
                dist[u.first] = u.second + d;
                frontier.push({dist[u.first], u.first});
            }
        }
    }

}







void solve() {

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        w *= 2;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    for(int i = 1; i <= n; i ++) {
        ll w;
        cin >> w;
        adj[0].push_back({i, w});
        adj[i].push_back({0, w});
    }

    dijkstra();

    for(int i = 1; i <= n; i ++) {
        cout << dist[i] << ' ';
    }


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
