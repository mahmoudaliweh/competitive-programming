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
int color[N];
vector<int> adj[N];
bool noSol = false;

void dfs(int v, int p, int c) {
    if (!color[v]) {
        color[v] = c;
    }
    else if (color[v] != c) {
        noSol = true;
        return;
    }
    else {
        return;
    }


    for (auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v, (c == 1 ? 2 : 1));
        if (noSol) {
            return;
        }
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
        if (!color[i]) {
            dfs(i, -1, 1);
        }
        if (noSol) break;
    }

    if (noSol) return void(cout << "IMPOSSIBLE");
    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
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
