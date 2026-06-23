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
int x, y;

vector<int> adj[N];
bool visited[N];
bool pathContains[N];
vector<int> cycle;
bool foundCycle = false;
vector<int> path;

void dfs(int v, int p) {
    if(foundCycle) return;
    if(visited[v] && pathContains[v]) {
        foundCycle = true;
        cycle.push_back(v);
        for(int i = path.size() - 1; i >= 0; i--) {
            cycle.push_back(path[i]);
            if(path[i] == v) {
                return;
            }
        }
    }
    if(visited[v]) return;
    visited[v] = true;
    path.push_back(v);
    pathContains[v] = true;
    for(auto u : adj[v]) {
        if(u == p) {
            cycle.push_back(p);
            cycle.push_back(v);
            cycle.push_back(p);
            foundCycle = true;
            return;
        }
        dfs(u, v);
        if(foundCycle) return;
    }
    path.pop_back();
    pathContains[v] = false;

}

void solve() {

    cin >> n >> m;
    for(int i = 1 ; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for(int i = 1; i <= n; i ++) {
        if(foundCycle) break;
        if(!visited[i]) dfs(i, -1);

    }

    if(foundCycle) {
        cout << cycle.size() << endl;
        for(int i = cycle.size() - 1; i >= 0; i--) {
            cout << cycle[i] << ' ';
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
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
