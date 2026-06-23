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
int value[N];
int result;
bool white[N];


int dfs(int v) {
    if(white[v]) {
        value[v] = 1;
    } else {
        value[v] = -1;
    }
    for(auto u : adj[v]) {
        value[v] += dfs(u);
    }
    if(value[v] == 0) result++;
    return value[v];

}

void solve() {

    int n, p;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
    }
    result = 0;

    for(int i = 2; i <= n; i ++) {
        cin >> p;
        adj[p].push_back(i);
    }
    char c;
    for(int i = 1; i <= n; i ++) {
        cin >> c;
        if(c == 'W') {
            white[i] = true;
        } else white[i] = false;
    }
    dfs(1);
    cout << result << endl;
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
