#include <bits/stdc++.h>
#include <iomanip>

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
int n, m, k;

vector<pair<int, ll>> adj[N];

ll dist[N];
bool train[N];

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
void dijkstra() {

    while (!frontier.empty()) {
        int v = frontier.top().second;
        ll d = frontier.top().first;
        frontier.pop();

        if(d != dist[v]) continue;
        for(auto u : adj[v]) {
            if(u.second + d < dist[u.first]) {
                dist[u.first] = u.second + d;
                train[u.first] = false;
                frontier.push({dist[u.first], u.first});
            } else if(u.second + d == dist[u.first]) {
                train[u.first] = false;
            }
        }
    }


}


void solve() {

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    for(int i = 1; i <= n; i ++) {
        dist[i] = LONG_LONG_MAX;
    }

    for(int i = 0; i < k; i++) {
        int b;
        ll w;
        cin >> b >> w;
        if(w < dist[b]) {
            dist[b] = w;
            train[b] = true;
        }
    }
    dist[1] = 0;
    for(int i = 1; i <= n; i ++) {
        if(train[i]) {
          frontier.push({dist[i], i});
        }
    }
    frontier.push({0, 1});
    dijkstra();

    int needed = 0;
    for(int i = 1; i <= n; i ++) {
        if(train[i]) needed++;
    }
    cout << k - needed << endl;
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
