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
int longestPath;
int n, m;
char grid[N][N];
bool visited[N][N];
vector<pair<int, int> > roots;

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

void dfs(int i, int j, char parent = 'A' - 1) {
    if (visited[i][j]) return;
    if (grid[i][j] != parent + 1) return;
    visited[i][j] = true;
    if (grid[i][j] - 'A' + 1 > longestPath) longestPath = grid[i][j] - 'A' + 1;
    for (auto child : getCells(i, j)) {
        dfs(child.first, child.second, grid[i][j]);
    }
}

void solve() {
    int caseNumber = 1;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        longestPath = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A') roots.push_back({ i, j });
                visited[i][j] = false;
            }
        }

        for (auto root : roots) {
            dfs(root.first, root.second);
        }

        cout << "Case " << caseNumber << ": " << longestPath << endl;
        caseNumber++;
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
