#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

using namespace std;

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef CLION
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
#endif
}

struct DSU {
    vector<int> p, size;
    DSU(int n) {
        p = size = vector<int> (n);
        for(int i = 0 ; i < n; i ++) p[i] = -1;
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
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;


vector<int> adj[N];
void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DSU dsu = DSU(n);
    stack<int> input;
    for(int i = 0 ; i < n; i ++) {
        int x;
        cin >> x;
        x--;
        input.push(x);
    }
    vector<bool> ans(n);
    for(int i = 1 ; i <= n; i ++) {
        int x = input.top();
        input.pop();
        dsu.p[x] = x;

        for(auto y : adj[x]) {
            if(dsu.p[y] != -1) {
                dsu.uni(x, y);
            }
        }
        int p = dsu.find(x);
        ans[i - 1] = (dsu.size[p] == i);
    }

    for(int i = n - 1; i >= 0 ; i--) {
        cout << (ans[i] ? "YES" : "NO") << endl;
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