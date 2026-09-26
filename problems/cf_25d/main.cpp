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

    int n;
    cin >> n;
    DSU dsu = DSU(n);

    vector<pair<int, int>> close;
    for(int i = 0 ; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dsu.find(a) == dsu.find(b)) close.push_back({a, b});
        else dsu.uni(a, b);
    }

    vector<int> cmps;
    for(int i = 0 ; i < n; i ++) {
        if(dsu.p[i] == i) cmps.push_back(i);
    }

    cout << cmps.size() - 1 << endl;
    while (cmps.size() != 1) {
        cout << close.back().first + 1 << ' ' << close.back().second + 1 << ' ';
        close.pop_back();
        int a = cmps.back();
        cmps.pop_back();
        int b = cmps.back();
        cout << a + 1 << ' ' << b + 1<< ' ';
        cmps.pop_back();
        dsu.uni(a, b);
        cmps.push_back(dsu.find(a));
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