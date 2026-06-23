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

const int N = 2 * 1e5 + 1;
vector<int> adj[N];
int numberOfLeaves[N];


int calculateLeaves(int v, int p) {

    if(adj[v].size() == 1 && adj[v].front() == p) {
        numberOfLeaves[v] = 1;
        return 1;
    }
    int total = 0;
    for(auto u : adj[v]) {
        if(u == p) continue;
        total += calculateLeaves(u, v);
    }
    numberOfLeaves[v] = total;
    return total;

}
void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }

    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calculateLeaves(1, -1);

    int q;
    cin >> q;
    int x, y;

    while (q--) {
        cin >> x >> y;
        cout << (long long)(numberOfLeaves[x]) * numberOfLeaves[y] << endl;

    }


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
