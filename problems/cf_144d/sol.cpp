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

int n, m, s;
ll l;

vector<pair<int, int>> adj[N];
ll dist[N];
void dijkstra() {

    for(int i = 1; i <= n; i ++) {
        dist[i] = LONG_LONG_MAX;
    }
    dist[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({0, s});

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

    cin >> n >> m >> s;
    vector<pair<pair<int, int>, ll>> edges;
    for(int i = 1; i <= m ; i ++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        edges.push_back({{a, b}, w});
    }
    cin >> l;
    dijkstra();

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(dist[i] == l) cnt++;
    }

    for(auto it: edges) {
        int v = it.first.first;
        int u = it.first.second;
        ll dv = dist[v];
        ll du = dist[u];
        ll w = it.second;

        if(du > dv) swap(dv, du);

        if(du < l && du + w > l) {
            ll need = l - du;
            if(need + du == min(need + du, w - need + dv)) {
                cnt++;
            }

        }

        if(dv < l && dv + w > l) {
            ll need = l - dv;
            if(need + dv == min(need + dv, w - need + du)) {
                cnt++;
            }
            if(need + dv == w - need + du) {
                cnt--;
            }

        }
    }
    cout << cnt << endl;
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
