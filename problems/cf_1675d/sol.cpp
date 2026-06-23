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

const int N = 1e5 * 2 + 1;
vector<int> adj[N];
vector<int> path[N];
int nPaths = 0;


void dfs(int v, int id) {

    if(id == -1) {
        id = v;
        path[v].push_back(v);
        nPaths++;
    } else {
        path[id].push_back(v);
    }

    bool took = false;
    for(auto u : adj[v]) {
        if(!took) {
            dfs(u, id);
            took = true;
            continue;
        }
        dfs(u, -1);
    }

}

void solve() {

    int n, p;
    cin >> n;
    int root;

    // reset
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        path[i].clear();
    }
    nPaths = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> p;
        if(p == i) {
            root = p;
            continue;
        }
        adj[p].push_back(i);
    }

    dfs(root, -1);
    cout << nPaths << endl;
    for(int i = 1; i <= n; i ++) {
        if(path[i].empty()) continue;
        cout << path[i].size() << endl;
        for(auto v : path[i]) {
            cout << v << ' ';
        }
        cout << endl;
    }
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
