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

#define ll long long
const int N = 1e4 + 1;

int n, m, k;

vector<pair<int, pair<ll, ll>>> adj[N];
ll dist[N][101];

// Gemini Utility
long long getNewCost(long long c) {
    // If c is less than 2, it has no prime factors to divide it evenly
    if (c < 2) return -1;

    long long min_cost = LLONG_MAX;
    long long temp_c = c;

    // Trial division up to sqrt(c) to find all prime factors efficiently
    for (long long p = 2; p * p <= temp_c; ++p) {
        if (temp_c % p == 0) {
            // p is a prime factor, evaluate f(p)
            long long current_cost = (c / p) + 2 * p;
            min_cost = std::min(min_cost, current_cost);

            // Divide out all occurrences of this prime factor
            while (temp_c % p == 0) {
                temp_c /= p;
            }
        }
    }

    // If temp_c > 1, the remaining part is also a prime factor
    if (temp_c > 1) {
        long long current_cost = (c / temp_c) + 2 * temp_c;
        min_cost = std::min(min_cost, current_cost);
    }

    return min_cost;
}

void dijkstra(int src) {

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= 100; j ++) {
            dist[i][j] = LONG_LONG_MAX;
        }
    }
    for(int i = 0; i <= 100; i++) {
        dist[src][i] = 0;
    }

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> frontier;
    frontier.push({0, {src, 0}});

    while (!frontier.empty()) {
        ll d = frontier.top().first;
        int v = frontier.top().second.first;
        int stonesUsed = frontier.top().second.second;
        frontier.pop();

        if(dist[v][stonesUsed] != d) continue;
        // check if not expanding nodes with distance greater than the current minimum distance of the destination

        for(auto u : adj[v]) {
            ll cost = u.second.first, newCost = u.second.second;
            if(cost + d < dist[u.first][stonesUsed]) {
                dist[u.first][stonesUsed] = cost + d;
                frontier.push({dist[u.first][stonesUsed], {u.first, stonesUsed}});
            }
            if(stonesUsed < k) {
                if(newCost != -1 && dist[u.first][stonesUsed + 1] > newCost + d) {
                    dist[u.first][stonesUsed + 1] = newCost + d;
                    frontier.push({dist[u.first][stonesUsed + 1], {u.first, stonesUsed + 1}});
                }
            }
        }
    }



}



void solve() {

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        ll newCost = getNewCost(w);
        adj[a].push_back({b, {w, newCost }});
        adj[b].push_back({a, {w, newCost}});
    }

    int src, dest;
    cin >> src >> dest;

    dijkstra(src);

    ll minCost = LONG_LONG_MAX;
    for(int i = 0; i <= k ; i++) {
        minCost = min(minCost, dist[dest][i]);
    }
    if(minCost == LONG_LONG_MAX) {
        cout << -1;
    } else cout << minCost;
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
