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
long long INF = LONG_LONG_MAX;
const int N = 1e5 + 1;

vector<pair<int, ll>> adj[N];
ll dist[N];
int n, m;
int parent[N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};



void dijkstra(int src, int dest) {

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({dist[src], src});

    while (!frontier.empty()) {
        int v = frontier.top().second;
        ll d = frontier.top().first;
        frontier.pop();

        if(d != dist[v]) continue;
        if(v == dest) return;

        for(auto u : adj[v]) {

            if(d + u.second < dist[u.first]) {
                dist[u.first] = d + u.second;
                frontier.push({dist[u.first], u.first});
                parent[u.first] = v;
            }
        }
    }

}

void solve() {

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }

    for(int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int src = 1, dest = n;
    dijkstra(src, dest);

    if(dist[dest] == INF) {
        cout << -1;

    } else {

        stack<int> path;
        int current = dest;
        while (current != -1) {
            path.push(current);
            current = parent[current];
        }

        while (!path.empty()) {
            cout << path.top() << ' ';
            path.pop();
        }
    }
    cout << endl;


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
