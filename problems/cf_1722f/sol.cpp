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
int n, m;
char grid[N][N];
bool visited[N][N];
int total = 0;

vector<pair<int, int> > getCells(int i, int j) {
    vector<pair<int, int> > cells;

    //sides
    if (i + 1 <= n) cells.push_back({ i + 1, j });
    if (i - 1 >= 1) cells.push_back({ i - 1, j });
    if (j + 1 <= m) cells.push_back({ i, j + 1 });
    if (j - 1 >= 1) cells.push_back({ i, j - 1 });
    // diagonls
    if (i + 1 <= n && j + 1 <= m) cells.push_back({ i + 1, j + 1 });
    if (i + 1 <= n && j - 1 >= 1) cells.push_back({ i + 1, j - 1 });
    if (i - 1 >= 1 && j - 1 >= 1) cells.push_back({ i - 1, j - 1 });
    if (i - 1 >= 1 && j + 1 <= m) cells.push_back({ i - 1, j + 1 });

    return cells;
}

bool right(int i, int j) {
    if (j + 1 <= m) {
        return grid[i][j + 1] == '*';
    }
    return false;
}
bool left(int i, int j) {
    if (j - 1 >= 0) {
        return grid[i][j - 1] == '*';
    }
    return false;
}
bool up(int i, int j) {
    if (i - 1 >= 0) {
        return grid[i - 1][j] == '*';
    }
    return false;
}
bool down(int i, int j) {
    if (i + 1 <= n) {
        return grid[i + 1][j] == '*';
    }
    return false;
}

bool test(int i, int j) {
    if ((right(i, j) || left(i, j)) && (down(i, j) || up(i, j))) {
        return true;
    }

    if (right(i, j)) {
        if (up(i, j + 1) || down(i, j + 1)) return true;
    }
    if (left(i, j)) {
        if (up(i, j - 1) || down(i, j - 1)) return true;
    }
    if (up(i, j)) {
        if (right(i - 1, j) || left(i - 1, j)) return true;
    }
    if (down(i, j)) {
        if (right(i + 1, j) || left(i + 1, j)) return true;
    }
    return false;
}


void dfs(int i, int j) {
    if (visited[i][j] || grid[i][j] == '.') return;
    visited[i][j] = true;
    total++;
    for (auto cell : getCells(i, j)) {
        dfs(cell.first, cell.second);
    }

}

void solve() {

    cin >> n >> m;
    total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && grid[i][j] == '*') {
                dfs(i, j);
                if (total != 3) {
                    return void(cout << "NO\n");
                }
                total = 0;
                if (!test(i, j)) return void(cout << "NO\n");
            }
        }
    }

    return void(cout << "YES\n");
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
