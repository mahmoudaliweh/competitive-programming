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

const int INF = INT_MAX;
const int N = 1000 + 1;

char grid[N][N];
int dist[4][N][N];

int n, m;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

pair<int, int> escape1, escape2;
void bfs(pair<int, int> source, int label) {

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m ; j++) {
            dist[label][i][j] = INF;
        }
    }
    dist[label][source.first][source.second] = 0;

    deque<pair<int, int>> frontier;
    frontier.push_front(source);

    while (!frontier.empty()) {

        int x = frontier.front().first;
        int y = frontier.front().second;
        frontier.pop_front();

        for(int i = 0 ; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m || dist[label][nx][ny] != INF || grid[nx][ny] == '#') continue;

            if(grid[nx][ny] != '.') {
                dist[label][nx][ny] = dist[label][x][y];
                frontier.push_front({nx, ny});

            } else {
                dist[label][nx][ny] = dist[label][x][y] + 1;
                frontier.push_back({nx, ny});
            }
        }
    }
}


void solve() {

    cin >> n >> m;

    pair<int, int> start1, start2, start3;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1 ; j <=m ; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '1') start1 = {i, j};
            if(grid[i][j] == '2') start2 = {i, j};
            if(grid[i][j] == '3') start3 = {i, j};
        }
    }

    bfs(start1, 1);
    bfs(start2, 2);
    bfs(start3, 3);

    int ans = INF;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j++) {

            if(dist[1][i][j] == INF || dist[2][i][j] == INF || dist[3][i][j] == INF) continue;
            int totDist = dist[1][i][j] + dist[2][i][j] + dist[3][i][j];
            if(grid[i][j] == '.') totDist -= 2;
            ans = min(ans, totDist);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;

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
