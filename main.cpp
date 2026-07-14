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
ll discount[N];
vector<pair<int, ll>> adj[N];

void dijkstra(int src) {

    for(int i = 1; i <= n; i ++) {
        dist[i] = LONG_LONG_MAX;
        discount[i] = LONG_LONG_MAX;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({0, src});
    dist[src] = 0;
    discount[src] = 0;

    while (!frontier.empty()) {
        ll d = frontier.top().first;
        int v = frontier.top().second;
        frontier.pop();

        if(d != dist[v]) continue;

        for(auto u : adj[v]) {
            bool pushed = false;
            if(u.second + dist[v] < dist[u.first]) {
                dist[u.first] = u.second + dist[v];
                frontier.push({dist[u.first], u.first});
                pushed = true;
            }
            if(u.second / 2 + dist[v] < discount[u.first] || discount[v] + u.second < discount[u.first]) {
                discount[u.first] = min(u.second / 2 + dist[v], discount[v] + u.second);
                if(!pushed) frontier.push({dist[u.first], u.first});

            }

        }
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

    dijkstra(1);
    cout << discount[n] << endl;

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
