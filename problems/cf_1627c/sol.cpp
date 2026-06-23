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
vector<pair<int, int>> adj[N];
bool impossible;
int n, a, b;

void dfs(int v, int p, int weight) {

    if(p != -1) {
        for(auto& u : adj[v]) {
            if(u.first == p) {
                u.second = weight;
                break;
            }
        }
        for(auto& u : adj[p]) {
            if(u.first == v) {
                u.second = weight;
                break;
            }
        }
    }

    for(auto u : adj[v]) {
        if(u.first == p) continue;
        dfs(u.first, v,(weight == 2 ? 5 : 2));
        weight = (weight == 2 ? 5 : 2);
    }


}
void reset() {
    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }
    impossible = false;
}
void solve() {

    cin >> n;
    queue<pair<int, int>> output;
    reset();

    for(int i = 1; i < n; i ++) {
        cin >> a >> b;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 0});
        output.push({a, b});
        if(adj[a].size() > 2 || adj[b].size() > 2) impossible = true;
    }
    if(impossible) {
        cout << -1 << endl;
        return;
    }

    dfs(1, -1, 2);

    int v1;
    int v2;
    while (!output.empty()) {
        v1 = output.front().first;
        v2 = output.front().second;
        output.pop();
        for(auto u : adj[v1]) {
            if(u.first == v2) {
                cout << u.second << ' ';
                break;
            }
        }
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
