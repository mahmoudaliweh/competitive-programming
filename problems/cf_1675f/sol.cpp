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
vector<int> adj[N];
int dist[N];
bool isHouse[N];
int block = -1;
int n, k;


bool dfs(int v, int p) {
    int total = 0;
    bool toReturn = isHouse[v];
    for (auto u: adj[v]) {
        if (u == p || u == block) continue;
        if (dfs(u, v)) {
            total += (2 + dist[u]);
            toReturn = true;
        }
    }
    dist[v] = total;
    return toReturn;
}

int target;
bool found = false;
deque<int> path;

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

    block = -1;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        isHouse[i] = false;
        dist[i] = 0;
    }
}
void solve() {
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    int house;
    reset();
    for (int i = 1; i <= k; i++) {
        cin >> house;
        isHouse[house] = true;
    }
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    target = y;
    found = false;
    path.push_front(x);
    getPath(x, -1);

    if (x != y) {
        path.push_back(y);
    }
    int totalDistance = 0;
    int currentLocation;

    while (path.size()) {
        currentLocation = path.front();
        path.pop_front();
        dfs(currentLocation, (path.empty() ? -1 : path.front()));
        block = currentLocation;
        totalDistance += dist[currentLocation] + 1;
    }
    cout << totalDistance - 1 << endl;
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
