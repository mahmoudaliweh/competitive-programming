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

const int N = 52;
char grid[N][N];
bool visited[N][N];
int n, m;
int nGood;
int canEscape;


vector<pair<int, int> > getCells(int i, int j) {
    vector<pair<int, int> > cells;

    if (i + 1 <= n) cells.push_back({ i + 1, j });
    if (i - 1 >= 1) cells.push_back({ i - 1, j });
    if (j + 1 <= m) cells.push_back({ i, j + 1 });
    if (j - 1 >= 1) cells.push_back({ i, j - 1 });

    return cells;
}

void dfs(int i, int j) {
    if (visited[i][j] || grid[i][j] == '#') return;
    visited[i][j] = true;
    if (grid[i][j] == 'G') canEscape++;
    if (grid[i][j] == 'B') {
        nGood = -1;
        return;
    }

    for (auto cell : getCells(i, j)) {
        dfs(cell.first, cell.second);
    }
}


void block(int i, int j) {
    int x, y;
    for (auto cell : getCells(i, j)) {
        x = cell.first;
        y = cell.second;

        if (grid[x][y] == '.') grid[x][y] = '#';
    }
}

void solve() {
    cin >> n >> m;
    nGood = 0;
    canEscape = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            (grid[i][j] == 'G' ? ++nGood : 0);
            visited[i][j] = false;
        }
    }

    if (nGood == 0) return void(cout << "Yes\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'B') {
                block(i, j);
            }
        }
    }
    dfs(n, m);
    if (canEscape == nGood) {
        cout << "Yes\n";
    }
    else cout << "No\n";
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
