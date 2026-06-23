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
const long long MOD = 1e9 + 7;
vector<int> adj[N];
bool visited[N];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int dfs(int v, int p) {
    if(adj[v].empty()) return 1;
    visited[v] = true;
    int total = 1;
    for(auto u : adj[v]) {
        if(u == p) continue;
        total += dfs(u, v);
    }
    return total;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a, b, c;
    for(int i = 1; i < n; i ++) {
        cin >> a >> b >> c;
        if(c == 1) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long allPossible = long(power(n, k)) % MOD;
    long long nodes;
    for(int i = 1; i <= n; i ++) {
        if(!visited[i]) {
            nodes = dfs(i, -1);
            long long badSequences = power(nodes, k);
            allPossible = (allPossible - badSequences + MOD) % MOD;
            // calculate bad sequences and minus it from all the possible sequences
        }
    }
    cout << allPossible;


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
