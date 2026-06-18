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

const int N = 2 * 1e5;
int maxCats;
bool hasCat[N];
vector<int> adj[N];
int paths = 0;

void dfs(int p, int v, int currentCats = 0, int maxConsecutive = 0) {
    if (hasCat[v]) {
        currentCats++;
        if(currentCats > maxConsecutive) maxConsecutive = currentCats;
    } else currentCats = 0;

    for (auto child: adj[v]) {
        if (child == p) continue;
        dfs(v, child, currentCats, maxConsecutive);
    }

    if (adj[v].size() == 1 && maxConsecutive <= maxCats && v != 1) {
        paths++;
    }
}

void solve() {
    int n;
    cin >> n >> maxCats;
    bool cat;
    for (int i = 1; i <= n; i++) {
        cin >> cat;
        hasCat[i] = cat;
    }

    int x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, 1);
    cout << paths;
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
