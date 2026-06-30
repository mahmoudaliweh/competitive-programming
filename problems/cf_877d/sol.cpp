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
int n, m, k;

int srcX, srcY, destX, destY;

int dist[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int bfs() {

    queue<pair<int, int>> frontier;
    frontier.push({srcX, srcY});

    int level = 0;
    while (!frontier.empty()) {

        int size = frontier.size();

        while (size--) {
            int x = frontier.front().first;
            int y = frontier.front().second;
            dist[x][y] = level;
            if(x == destX && y == destY) return level;
            frontier.pop();

            for(int i = 0 ; i < 4; i ++) {

                int nx = x;
                int ny = y;
                for(int j = 0; j < k; j ++) {
                    nx += dx[i];
                    ny += dy[i];

                    if(nx < 1 || ny < 1 || nx > n || ny > m || grid[nx][ny] != '.') {
                       break;
                    }
                    if(dist[nx][ny] < dist[x][y] + 1) {
                        break;
                    }
                    if(dist[nx][ny] == dist[x][y] + 1) continue;
                    dist[nx][ny] = level + 1;
                    frontier.push({nx, ny});
                }

            }
        }
       level++;

    }

    return -1;

}


void solve() {
   cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dist[i][j] = INF;
            cin >> grid[i][j];
        }
    }
    cin >> srcX >> srcY >> destX >> destY;
    cout << bfs() << endl;
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
