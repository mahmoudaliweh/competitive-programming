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

const int N = 2001;
int n, m;
int x, y;

vector<int> adj[N];
bool visited[N][N];
bool foundCycle;
int destination;

int vertex;
vector<int> path;

void dfs(int v, int p) {
    if(v == destination) {
        path.push_back(v);
        foundCycle = true;
        return;
    }
    if(foundCycle || visited[destination][v]) return;
    visited[destination][v] = true;

    path.push_back(v);
    for(int u : adj[v]) {
        if(u == p) continue;
        dfs(u, v);
        if(foundCycle) return;
    }
    path.pop_back();
}

void reset() {
    path.clear();
    foundCycle = false;
    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            visited[i][j] = false;
        }
    }
}

void solve() {

    reset();
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(adj[i].size() >= 4) {
            destination = i;
            for(auto u : adj[i]) {
                path.clear();
                visited[destination][i] = true;
                dfs(u, i);
                if(foundCycle) {
                    vertex = i;
                    break;
                }
            }
        }
        if(foundCycle) break;
    }

    if(foundCycle) {
        vector<int> cycleEdges;
        for(auto it : path) {
            if(find(adj[vertex].begin(), adj[vertex].end(), it) != adj[vertex].end()) {
                cycleEdges.push_back(it);
                if(cycleEdges.size() == 2) {
                    break;
                }
            }
        }

        for(int i = 1; i <= n; i ++) {
            visited[destination][i] = false;
        }
        path.clear();
        destination = vertex;
        foundCycle = false;
        vector<int> twoEdges;
        for(auto u : adj[vertex]) {
            if(u != cycleEdges[0] && u != cycleEdges[1]) {
                visited[destination][u] = true;
                if(twoEdges.size() != 2) {
                    twoEdges.push_back(u);
                }
            }
        }

        dfs(cycleEdges[0], vertex);

        cout << "YES" << endl;
        cout << path.size() + 2 << endl;
        for(int i = 0; i + 1< path.size(); i++) {
            cout << path[i] << ' ' << path[i + 1] << endl;
        }
        cout << path[0] << ' ' << path[path.size() - 1] << endl;
        cout << vertex << ' ' << twoEdges[0] << endl;
        cout << vertex << ' ' << twoEdges[1] << endl;

        return;
    }
    cout << "NO" << endl;
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
