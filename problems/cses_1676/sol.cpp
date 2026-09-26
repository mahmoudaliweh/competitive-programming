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
        if(size[x] < size[y]) swap(x, y);
        p[y] = x;
        size[x] += size[y];
    }
};

#define ll long long
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;



void solve() {
    int n, m;
    cin >> n >> m;
    int maxSize = 1;
    int components = n;
    DSU roads = DSU(n);
    for(int i = 0 ; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(roads.find(x) != roads.find(y)) {
            components--;
            roads.uni(x, y);
            maxSize = max(maxSize, roads.size[roads.p[y]]);
            maxSize = max(maxSize, roads.size[roads.p[x]]);

        }
        cout << components << ' ' << maxSize << endl;

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