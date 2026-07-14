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
const int N = 100 + 1;
int n, m;
char grid[N][N];
bool visited[2][N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int bfs(pair<int, pair<int, int>> hen) {
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m ; j++) {
            visited[0][i][j] = false;
            visited[1][i][j] = false;
        }
    }

    visited[hen.first][hen.second.first][hen.second.second] = true;
    queue<pair<int, pair<int, int>>> frontier;
    frontier.push(hen);

    int size;
    int level = 0;
    while (!frontier.empty()) {
        size = frontier.size();
        while (size--) {
            int state = frontier.front().first;
            int x = frontier.front().second.first;
            int y = frontier.front().second.second;
            frontier.pop();

            if(x == 1 || y == 1 || x == n || y == m) return level + 1;

            for(int i = 0 ; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int newState = state;

                if(nx < 1 || ny < 1 || nx > n || ny > m || grid[nx][ny] == 'W') continue;

                if(grid[nx][ny] == 'O') {
                    newState = 1;
                } else if(grid[nx][ny] == 'C') {
                    newState = 0;
                } else if(grid[nx][ny] == 'D' && newState == 0) continue;


                if(visited[newState][nx][ny]) continue;
                visited[newState][nx][ny] = true;
                frontier.push({newState, {nx, ny}});
            }

        }
        level++;
    }

    return -1;
}

void solve() {

    cin >> n >> m;
    while (n != -1 && m != -1) {

        pair<int, pair<int, int>> hen;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'H') hen = {0,{i, j}};

            }
        }

        cout << bfs(hen) << endl;
        cin >> n >> m;
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
