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
const int N = 5 * 1e5 + 1;
bool visited[N];
int n, m, q;

vector<pair<int, int>> adj[N];
int cnt = 0;

ll dijkstra(int src) {
    cnt = 0;
    for(int i = 0 ; i < n; i++) {
        visited[i] = false;
    }
    deque<int> queues[10];
    queues[0].push_front(src);
    int level = 0;
    int current = 0;
    ll mx = 0;
    while (true) {

        int size = queues[current].size();
        while (size--) {
            int v = queues[current].front();
            queues[current].pop_front();

            if(visited[v]) continue;
            visited[v] = true;

            ll d = (current) + (ll)(level) * 10;
            if(d == mx) {
                cnt++;
            } else if(d > mx) {
                cnt = 1;
                mx = d;
            }
            for(auto u : adj[v]) {
                if(u.second == 0) {
                    size++;
                    queues[current].push_front(u.first);
                } else {
                    queues[(u.second + current) % 10].push_back(u.first);
                }
            }
        }

        bool increaseLevel = false;
        current = (current + 1) % 10;
        if(current == 0) increaseLevel = true;
        int k = 0;
        while (queues[current].empty() && k != 10) {
            k++;
            current = (current + 1) % 10;
            if(current == 0) increaseLevel = true;
        }
        if(k == 10) return mx;
        if(increaseLevel) level++;
    }



}



void solve() {

    cin >> n >> m >> q;
    for(int i = 1 ; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    while (q--) {
        int src;
        cin >> src;
        cout << dijkstra(src) << ' ' << cnt << endl;
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
