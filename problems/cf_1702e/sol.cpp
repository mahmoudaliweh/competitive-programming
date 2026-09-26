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
        for(int i = 0 ; i < n; i ++) p[i] = i;
        for(int i = 0 ; i < n; i ++) size[i] = 0;
        cmp = n;
    }

    int find(int x) {
        if (p[x] != x) return p[x] = find(p[x]);
        return x;
    }

    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        cmp --;
        if(size[x] < size[y]) swap(x, y);
        p[y] = x;
        size[x] += size[y];
    }
};

#define ll long long
const int N = 2e5 + 2;
const int MOD = 1e9;

vector<int> adj[N];
int color[N];
int n;
bool answer = true;
void dfs(int v, int expected ) {
    if(!answer || color[v] == expected) return;
    if(color[v]) {
        answer = false;
        return;
    }
    color[v] = expected;
    for(auto u : adj[v]) {
        dfs(u, (expected == 1 ? 2 : 1));
    }


}
void solve() {

    map<int, int> freq;
    cin >> n;
    for(int i = 0 ; i < n; i ++) {
        adj[i].clear();
        color[i] = 0;
        answer = true;
    }
    for(int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        freq[a]++;
        freq[b]++;
        if(freq[a] > 2 || freq[b] > 2 || a == b) answer = false;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0 ; i < n; i ++) {
        if(!color[i]) dfs(i, 1);
    }
    if(answer) cout << "YES";
    else cout << "NO";
    cout << endl;

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