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
const int N = 2 * 1e4 + 1;

int n, m;
vector<pair<int, ll>> adj[N];
int dist[8][8];

int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

void dijkstra(pair<int, int> src, pair<int, int> dest) {

    for(int i = 0; i < 8; i ++) {
        for(int j = 0 ; j < 8; j ++) {
            dist[i][j] = INT_MAX;
        }
    }
    dist[src.first][src.second] = 0;

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> frontier;
    frontier.push({0, src});

    while (!frontier.empty()) {
        auto v = frontier.top().second;
        int d = frontier.top().first;
        frontier.pop();

        if(v.first == dest.first && v.second == dest.second) return;
        if(d != dist[v.first][v.second]) continue;

        for(int i = 0 ; i < 8 ; i++) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];

            if(nx < 0 || nx > 7 || ny < 0 || ny > 7) continue;
            int w = v.first * nx + v.second * ny;
            if(w + d < dist[nx][ny]) {
                dist[nx][ny] = w + d;
                frontier.push({dist[nx][ny], {nx, ny}});
            }

        }

    }
}



void solve() {

    n = m = 8;
    pair<int, int> src, dest;


    while (cin >> src.first && cin >> src.second && cin >> dest.first && cin >> dest.second) {
        dijkstra(src, dest);
        if(dist[dest.first][dest.second] == INT_MAX) {
            cout << -1;
        } else {
            cout << dist[dest.first][dest.second];
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
