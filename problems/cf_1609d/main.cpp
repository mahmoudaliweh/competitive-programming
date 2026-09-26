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
const int N = 2e5 + 2;
const int MOD = 1e9;


void solve() {

    int n, m;
    cin >> n >> m;

    DSU dsu = DSU(n);
    int extra = 0;
    for(int i = 0 ; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dsu.find(a) != dsu.find(b)) dsu.uni(a, b);
        else extra++;

        priority_queue<int> max_size_cmps;
        for(int j = 0 ; j < n; j ++) {
            if(dsu.p[j] == j) max_size_cmps.push(dsu.size[j]);
        }

        int total = 0;
        for(int k = 0 ; k < extra + 1; k++) {
            total += max_size_cmps.top();
            max_size_cmps.pop();
        }
        cout << total - 1 << endl;


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