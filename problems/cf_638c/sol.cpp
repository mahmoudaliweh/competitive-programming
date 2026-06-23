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
vector<pair<int, int>> adj[N];
vector<int> dayBukcets[N];
int maxDay = 0;

void dfs(int v, int p, int taken) {
    maxDay = max(maxDay, taken);
    int current = 1;
    for(auto u : adj[v]) {
        if(u.first == p) continue;
        if(current == taken) current++;
        dayBukcets[current].push_back(u.second);
        dfs(u.first, v, current);
        current++;
    }
}

void solve() {

    int n;
    cin >> n;
    int a, b;
    for(int i = 1; i < n; i ++) {
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    // for(int i = 1; i < n; i ++) {
    //     cout << edges[i].first << ' ' << edges[i].second << endl;
    // }

    dfs(1, -1, 0);

    cout << maxDay << endl;
    for(int i = 1; i <= maxDay; i ++) {
        cout << dayBukcets[i].size() << ' ';
        for(auto e : dayBukcets[i]) {
            cout << e << ' ';
        }
        cout << endl;
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
