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
int nRooms;
int n, m;
char grid[N][N];
bool visited[N][N];
int x, y;

vector<pair<int, int> > getCells(int i, int j) {
    vector<pair<int, int> > cells;

    //sides
    if (i + 1 <= n) cells.push_back({ i + 1, j });
    if (i - 1 >= 1) cells.push_back({ i - 1, j });
    if (j + 1 <= m) cells.push_back({ i, j + 1 });
    if (j - 1 >= 1) cells.push_back({ i, j - 1 });
    // diagonls
    // if (i + 1 <= n && j + 1 <= m) cells.push_back({ i + 1, j + 1});
    // if (i + 1 <= n && j - 1 >= 1) cells.push_back({ i + 1, j - 1 });
    // if (i - 1 >= 1 && j - 1 >= 1) cells.push_back({ i - 1, j - 1});
    // if (i - 1 >= 1 && j + 1 <= m) cells.push_back({ i - 1, j + 1 });

    return cells;
}

void dfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;

    for (auto child : getCells(i, j)) {
        x = child.first;
        y = child.second;

        if (grid[x][y] != '#') {
            dfs(x, y);
        }
    }
}

void solve() {
    cin >> n >> m;
    nRooms = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] != '#' && !visited[i][j]) {
                nRooms++;
                dfs(i, j);
            }
        }
    }

    cout << nRooms << endl;
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
