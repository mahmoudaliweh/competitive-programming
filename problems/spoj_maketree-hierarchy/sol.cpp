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

const int N = 1e5 + 1;
vector<int> adj[N];
stack<int> order;
bool visited[N];

void dfs(int v) {

    visited[v] = true;
    for(auto u : adj[v]) {
        if(!visited[u]) dfs(u);
    }
    order.push(v);
}
void solve() {

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k; i++) {
        int w;
        cin >> w;
        while (w--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(!visited[i]) dfs(i);
    }

    vector<int> parent(n + 1);
    int currentParent = 0;
    while (!order.empty()) {
        parent[order.top()] = currentParent;
        currentParent = order.top();
        order.pop();
    }

    for(int i = 1; i <= n; i ++) {
        cout << parent[i] << endl;
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
