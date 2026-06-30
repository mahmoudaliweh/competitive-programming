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

const int N = 1001;
char grid[N][N];

int n, m;
int visitedM[N][N];
int visiedA[N][N];


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<pair<int, int>, char>> getNeighbors(pair<pair<int, int>, char> entity) {
    vector<pair<pair<int, int>, char>> validMoves;

    int x = entity.first.first;
    int y = entity.first.second;
    char type = entity.second;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(type == 'M' && visitedM[nx][ny] || type == 'A' && visiedA[nx][ny]) continue;
        if(type == 'A' && (grid[nx][ny] != '.' || grid[nx][ny] == 'A')) continue;
        if(type == 'M' && (grid[nx][ny] == '#' || grid[nx][ny] == 'M')) continue;
        validMoves.push_back({{nx, ny}, type});
    }

    return validMoves;
}

void updateGrid(pair<pair<int, int>, char> entity) {

    int x = entity.first.first;
    int y = entity.first.second;

    if(entity.second == 'M') {
        if(grid[x][y] != '#') {
            grid[x][y] = 'M';
        }

    } else if(entity.second == 'A') {
        if(grid[x][y] != '#' && grid[x][y] != 'M') {
            grid[x][y] = 'A';
        }
    }
}

pair<int, int> lastMove;
pair<int, int> parent[N][N];
int bfs(queue<pair<pair<int, int>, char>> frontier) {

    int level = 0;
    while (!frontier.empty()) {

        int size = frontier.size();
        while (size--) {
            auto current = frontier.front();
            frontier.pop();
            updateGrid(current);

            if(current.second == 'M') {
                visitedM[current.first.first][current.first.second] = true;
            } else {
                visiedA[current.first.first][current.first.second] = true;
                int x = current.first.first;
                int y = current.first.second;
                if(x == 1 || x == n || y == 1 || y == m) {
                    lastMove = current.first;
                    return level;
                }
            }

            for(auto& u : getNeighbors(current)) {

                updateGrid(u);
                if(u.second == 'M') {
                    visitedM[u.first.first][u.first.second] = true;
                } else {
                    visiedA[u.first.first][u.first.second] = true;
                    parent[u.first.first][u.first.second] = current.first;
                }

                frontier.push(u);
            }
        }
        level++;
    }
    return -1;
}


void solve() {
    cin >> n >> m;

    queue<pair<pair<int, int>, char> > frontier;
    pair<int, int> player_start;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                frontier.push({{i, j}, 'M'});
            }
            if (grid[i][j] == 'A') {
                player_start = {i, j};
                parent[i][j] = {-1, -1};
            }
        }
    }

    frontier.push({player_start, 'A'});

    int nMoves = bfs(frontier);
    if (nMoves != -1) {
        cout << "YES" << endl;
        cout << nMoves << endl;
        int currentX = lastMove.first;
        int currentY = lastMove.second;
        pair<int, int> stop = {-1, -1};
        vector<pair<int, int>> path;
        path.push_back({currentX, currentY});
        while (parent[currentX][currentY] != stop) {
            pair<int, int> p = parent[currentX][currentY];
            path.push_back({p.first, p.second});

            currentX = p.first;
            currentY = p.second;
        }

        std::reverse(path.begin(), path.end());
        for(int i = 1; i < path.size(); i ++) {
            int x1 = path[i -1].first;
            int y1 = path[i -1].second;
            int x2 = path[i].first;
            int y2 = path[i].second;
            if(x1 == x2) {
                if(y2 == y1 + 1) {
                    cout << 'R';
                } else {
                    cout << 'L';
                }
            }
            if(y1 == y2) {
                if(x2 == x1 + 1) {
                    cout << 'D';
                } else {
                    cout << 'U';
                }
            }
        }

    } else {
        cout << "NO" << endl;
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
