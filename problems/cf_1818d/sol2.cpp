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

const int INF = INT_MAX;

const int N = 2001;
vector<int> adj[N];
int n, m;
int parent[N];
bool visited[N];
bool cycle = false;
int special;
deque<int> path;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void bfs(int v) {

    for(int i = 1; i <= n; i ++) {
        parent[i] = 0;
    }
    cycle = false;

    special = v;
    parent[v] = -1;

    queue<int> frontier;
    frontier.push(v);

    while (!frontier.empty()) {
        int current = frontier.front();
        frontier.pop();

        for (auto u: adj[current]) {
            if (u == parent[current]) continue;
            if (!parent[u]) {
                parent[u] = current;
                frontier.push(u);
                continue;
            }
            if (parent[u]) {
                int v1 = current;
                int v2 = u;

                for (int i = 1; i <= n; i++) {
                    visited[i] = false;
                }

                path.clear();
                while (v1 != special) {
                    path.push_front(v1);
                    visited[v1] = true;
                    v1 = parent[v1];
                }

                cycle = true;
                while (v2 != special) {
                    if (visited[v2]) {
                        cycle = false;
                        break;
                    }
                    path.push_back(v2);
                    v2 = parent[v2];
                }

                path.push_front(special);
                if (!cycle) continue;

                return;
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    cycle = false;
    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= 4) {
            bfs(i);
            if (cycle) {
                break;
            }
        }
    }

    if (cycle) {
        cout << "YES" << endl;
        cout << path.size() + 2 << endl;
        for (int i = 1; i < path.size(); i++) {
            cout << path[i] << ' ' << path[i - 1] << endl;
        }
        cout << path[path.size() - 1] << ' ' << path[0] << endl;

        int cnt = 2;
        for (auto u: adj[special]) {
            if (find(path.begin(), path.end(), u) == path.end()) {
                cout << special << ' ' << u << endl;
                cnt--;
            }
            if(!cnt) {
                break;
            }
        }
    } else cout << "NO" << endl;
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
