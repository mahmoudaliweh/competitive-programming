#include <bits/stdc++.h>

using namespace std;

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif
}

#define ll long long
const int N = 1e5 + 1;

int n, m;
ll minT;

vector<pair<int, pair<ll, int>>> adj[N];
ll dist[N];

void dijkstra(int s) {

    for(int i = 1; i <= n; i ++) {
        dist[i] = LONG_LONG_MAX;
    }
    dist[1] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({0, 1});

    while (!frontier.empty()) {
        int v = frontier.top().second;
        ll d = frontier.top().first;
        frontier.pop();

        if(d != dist[v]) continue;
        if(v == n) {
            return;
        }

        for(auto u : adj[v]) {
            if(u.second.second > s || u.second.first + d > minT) continue;
            if(u.second.first + d < dist[u.first]) {
                dist[u.first] = d + u.second.first;
                frontier.push({dist[u.first], u.first});
            }
        }
    }


}



void solve() {

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int a, b, s;
        ll t;
        cin >> a >> b >> t >> s;
        adj[a].push_back({b, {t, s}});
        adj[b].push_back({a,{t, s}});
    }

    cin >> minT;

    int start = 1, end = 1e6;
    int minS = 0;
    ll t = LONG_LONG_MAX;
    while (start <= end) {

        int mid = (start + end) / 2;
        dijkstra(mid);

        if(dist[n] != LONG_LONG_MAX) {
            minS = mid;
            t = dist[n];
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if(t == LONG_LONG_MAX) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        cout << minS << ' ' << t << endl;
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
