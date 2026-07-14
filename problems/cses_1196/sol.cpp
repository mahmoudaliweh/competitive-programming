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
const int N = 1e5 + 1;

int n, m, k;
vector<pair<int, ll>> adj[N];
vector<ll> output;
int cnt[N];
void dijkstra() {

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> frontier;
    frontier.push({0, 1});
    while (!frontier.empty()) {

        int v = frontier.top().second;
        ll d = frontier.top().first;
        frontier.pop();

        cnt[v]++;
        if(v == n) {
            output.push_back(d);
        }
        if(output.size() == k) return;
        if(cnt[v] > k) continue;



        for(auto u : adj[v]) {
            if(cnt[u.first] >= k) continue;
            frontier.push({u.second + d, u.first});
        }


    }
}



void solve() {

    cin >> n >> m >> k;
    for(int i = 1; i <= m ; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    dijkstra();
    for(auto it : output) {
        cout << it << ' ';
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
