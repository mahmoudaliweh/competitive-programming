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


#define INF INT_MAX
const int N = 1e5 + 1;

vector<pair<int, int>> adj[N];
int dist[N];
int n, m;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};



void dijkstra(int src, int dest) {

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> frontier;
    frontier.push({dist[src], src});

    while (!frontier.empty()) {
        int v = frontier.top().second;
        int d = frontier.top().first;
        frontier.pop();

        if(d != dist[v]) continue;
        if(v == dest) return;

        for(auto u : adj[v]) {

            if(d + u.second < dist[u.first]) {
                dist[u.first] = d + u.second;
                frontier.push({dist[u.first], u.first});
            }
        }
    }

}

void solve() {

    cin >> n >> m;
    int src, dest;
    cin >> src >> dest;

    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }

    for(int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra(src, dest);

    if(dist[dest] == INF) {
        cout << "NONE";

    } else cout << dist[dest];
    cout << endl;


}

int main() {
    setup_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
