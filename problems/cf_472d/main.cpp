#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct DSU {
    vector<int> p, size;
    int cmp;
    DSU(int n) {
        p = size = vector<int> (n);
        cmp = n;
        for(int i = 0 ; i < n; i ++) p[i] = i;
        for(int i = 0 ; i < n; i ++) size[i] = 1;
    }

    int find(int x) {
        if (p[x] != x) return p[x] = find(p[x]);
        return x;
    }

    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        cmp--;
        if(size[x] < size[y]) swap(x, y);
        p[y] = x;
        size[x] += size[y];
    }
};

#define ll long long
const int N = 2e3 + 2;
const int MOD = 1e9;

int adjMat[N][N];
vector<pair<int, int>> adj[N];


// !! AI GENERATED UTILITY FUNCITON !!
// DFS to check distances from root 'u' to all other nodes
bool dfs_validate(int u, int p, int current_dist, int root) {
    // If the tree path distance doesn't match the original matrix, it's invalid
    if (current_dist != adjMat[root][u]) {
        return false;
    }

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;

        // Don't traverse back to the parent node
        if (v != p) {
            if (!dfs_validate(v, u, current_dist + weight, root)) {
                return false;
            }
        }
    }
    return true;
}

void solve() {

    int n;
    cin >> n;

    for(int i = 0 ; i < n; i ++) {
        for(int j = 0 ; j < n; j ++) {
            cin >> adjMat[i][j];
        }
    }

    DSU dsu = DSU(n);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    bool yes = true;
    for(int i = 0; i < n ; i++) {
        for(int j = 0 ; j <= i; j++) {
            if((i == j && adjMat[i][j] != 0) || (i != j && (adjMat[i][j] != adjMat[j][i] || adjMat[i][j] <= 0))) yes = false;
            if(i != j) pq.push({adjMat[i][j], {i, j}});
        }
    }

    if(!yes) return void(cout << "NO");
    while (dsu.cmp != 1) {
        auto top = pq.top();
        pq.pop();
        int weight = top.first;
        int a = top.second.first;
        int b = top.second.second;

        if(dsu.find(a) != dsu.find(b)) {
            dsu.uni(a, b);
            adj[a].push_back({b, weight});
            adj[b].push_back({a, weight});
        }
    }

    if (yes) {
        for (int i = 0; i < n; i++) {
            if (!dfs_validate(i, -1, 0, i)) {
                yes = false;
                break;
            }
        }
    }
    cout << (yes ? "YES" : "NO") << endl;


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