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
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> edges;
    for(int i = 0 ; i < m ; i ++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges.push({w, {a, b}});
    }

    ll totalCost = 0;
    DSU dsu = DSU(n);
    while (!edges.empty()) {
        auto edg = edges.top();
        auto w = edg.first;
        auto a = edg.second.first;
        auto b = edg.second.second;
        edges.pop();

        if(dsu.find(a) != dsu.find(b)) {
            totalCost += w;
            dsu.uni(a, b);
        }
    }

    if(dsu.cmp == 1) {
        cout << totalCost;
    } else cout << "IMPOSSIBLE";
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