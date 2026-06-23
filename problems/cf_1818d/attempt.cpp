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
bool visited[N];
vector<int> path;
vector<int> cycle;
unordered_map<int, int> pathContains;
set<vector<int> > cycles;

std::vector<std::vector<int> > uniqueCycles;
std::set<std::multiset<int> > seenCycles;

void reset() {
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        visited[i] = false;
    }

    path.clear();
    cycle.clear();
    pathContains.clear();
    cycles.clear();
    uniqueCycles.clear();
    seenCycles.clear();
}

void dfs(int v, int p) {
    visited[v] = true;
    if (pathContains[v]) {
        cycle.clear();
        cycle.push_back(v);
        for (int i = path.size() - 1; i >= 0; i--) {
            if (path[i] == v) {
                break;
            }
            cycle.push_back(path[i]);
        }
        cycles.insert(cycle);
        return;
    }

    path.push_back(v);
    pathContains[v] = true;
    for (auto u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    path.pop_back();
    pathContains[v] = false;
}

std::stringstream outputBuffer;
bool hasTwoEdges(int v, vector<int> cycle) {
    vector<int> edges;
    for (auto u : adj[v]) {
        if (find(cycle.begin(), cycle.end(), u) != cycle.end()) continue;
        edges.push_back(u);
        if (edges.size() == 2) {
            break;
        }
    }
    if (edges.size() == 2) {
        outputBuffer << "YES\n";
        outputBuffer << 2 + cycle.size() << endl;

        for (int i = 0; i + 1 < cycle.size(); i++) {
            outputBuffer << cycle[i] << ' ' << cycle[i + 1] << endl;
        }
        outputBuffer << cycle[0] << ' ' << cycle[cycle.size() - 1] << endl;

        for (auto e : edges) {
            outputBuffer << v << ' ' << e << endl;
        }
        return true;
    }
    return false;
}

void solve() {
    reset();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && adj[i].size() >= 4) {
            dfs(i, -1);
        }
    }

    for (const auto& vec : cycles) {
        std::multiset<int> normalized(vec.begin(), vec.end());
        if (seenCycles.insert(normalized).second) {
            uniqueCycles.push_back(vec);
        }
    }


    // for(auto it : uniqueCycles) {
    //     for(auto v : it) {
    //         cout << v << ' ';
    //     }
    //     cout << endl;
    // }

    for (auto cycle : uniqueCycles) {
        outputBuffer.str("");
        for (auto v : cycle) {
            if (hasTwoEdges(v, cycle)) {
                cout << outputBuffer.str();
                return;
            }
        }

    }
    cout << "NO\n";
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
