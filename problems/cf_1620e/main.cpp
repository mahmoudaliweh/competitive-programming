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
const int N = 5e5 + 2;
const int MOD = 1e9;

int val[N];

void solve() {

    int n;
    cin >> n;
    stack<pair<int, pair<int, int>>> qs;
    for(int i = 0 ; i < n; i ++) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            val[x] = x;
            qs.push({1,{x, 0}});
        } else {
            int x, y;
            cin >> x >> y;
            val[x] = x;
            val[y] = y;
            qs.push({2, {x, y}});
        }
    }

    stack<int> output;
    while (!qs.empty()) {
        int t = qs.top().first;
        int x = qs.top().second.first;
        int y = qs.top().second.second;
        qs.pop();
        if(t == 1) {
            output.push(val[x]);
        } else {
            val[x] = val[y];
        }
    }

    while (!output.empty()) {
        cout << output.top() << ' ';
        output.pop();
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