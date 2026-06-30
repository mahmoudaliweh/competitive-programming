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

const int N = 2 * 1e5 + 1;
int n;

vector<int> adj[N];
int nOfNodes[N];
int height[N];

void setHeight(int v, int p) {

    for (auto u: adj[v]) {
        if (u == p) continue;
        setHeight(u, v);
        height[v] = max(height[v], height[u] + 1);
    }
}

void setNodesNumber(int v, int p) {
    nOfNodes[v] = 1;
    for (auto u: adj[v]) {
        if (u == p) continue;
        setNodesNumber(u, v);
        nOfNodes[v] += nOfNodes[u];
    }
}

int totalSteps = 0;

void dfs(int v, int p) {

    int maxChild;
    if(adj[v].size() == 1) {
        if(p == -1) {
            maxChild = adj[v][0];
        } else {
            return;
        }
    } else {
        maxChild = (adj[v][0] == p ? adj[v][1] : adj[v][0]);
    }

    for (auto u: adj[v]) {
        if (u == p || u == maxChild) continue;
        if (height[u] > height[maxChild]) {
            totalSteps += (nOfNodes[maxChild] - 1) * 2 + 2;
            maxChild = u;
        } else {
            totalSteps += (nOfNodes[u] - 1) * 2 + 2;
        }
    }
    totalSteps++;
    dfs(maxChild, v);
}

int target;
bool found = false;
vector<int> path;

void getPath(int v, int p) {
    if (found) return;
    if (v == target) {
        found = true;
        return;
    }
    if (p != -1) {
        path.push_back(v);
    }
    for (auto u: adj[v]) {
        if (u == p) continue;
        getPath(u, v);
        if (found) return;
    }
    path.pop_back();
}

void reset() {
    found = false;
    path.clear();
    totalSteps = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        nOfNodes[i] = 0;
        height[i] = 0;
    }
}

void solve() {
    cin >> n;
    int a, b;
    cin >> a >> b;
    int x, y;
    reset();
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    target = a;
    getPath(b, -1);
    int root;

    if (!path.empty()) {
        if (path.size() % 2 == 0) {
            root = path[path.size() / 2];
            totalSteps += (path.size() / 2) + 1;
        } else {
            root = path[path.size() / 2];
            totalSteps += (path.size() / 2) + 1;
        }
    } else {
        if (a == b) {
            root = a;
        } else {
            root = a;
            totalSteps += 1;
        }
    }
    setHeight(root, -1);
    setNodesNumber(root, -1);
    dfs(root, -1);
    cout << totalSteps << endl;
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
