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

const int N = 1e5 + 1;
int n, m;
bool visited[N];
vector<int> adj[N];
vector<int> path;
bool found = false;
int stop = -1;

void dfs(int v, int p) {
    if (visited[v]) {
        path.push_back(v);
        found = true;
        stop = v;
        return;
    }
    visited[v] = true;
    for (auto u : adj[v]) {
        if (u != p) dfs(u, v);
        if (found && stop != -1) {
            if (v == stop) stop = -1;
            path.push_back(v);
            return;
        }
        if (found) return;
    }

}

void solve() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i, -1);
        if (found) break;
    }
    if (path.empty()) {
        cout << "IMPOSSIBLE" << endl;
    }
    else cout << path.size() << endl;
    for (auto n : path) {
        cout << n << ' ';
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
