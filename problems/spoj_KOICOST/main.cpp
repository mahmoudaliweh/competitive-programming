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
    DSU(int n) {
        p = size = vector<int> (n);
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
        if(size[x] < size[y]) swap(x, y);
        p[y] = x;
        size[x] += size[y];
    }
};

#define ll long long
const int N = 1e5 + 2;
const int MOD = 1e9;
ll pre[N];

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>> edges;
    for(int i = 0 ; i < m ; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges.push({w, {a, b}});
        pre[w] = w;
    }

    for(int i = 1; i < N; i ++) {
        pre[i] += pre[i - 1];
    }

    ll totalSum = 0;
    DSU dsu = DSU(n);
    while (!edges.empty()) {
        auto edg = edges.top();
        auto a = edg.second.first;
        auto b = edg.second.second;
        auto w = edg.first;
        edges.pop();

        if(dsu.find(a) != dsu.find(b)) {
            long long weight_sum = pre[w] % MOD;
            long long pairs = (1LL * dsu.size[dsu.find(a)] * dsu.size[dsu.find(b)]) % MOD;
            totalSum = (totalSum + pairs * weight_sum) % MOD;
            dsu.uni(a, b);
        }
    }

    cout << totalSum << endl;
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