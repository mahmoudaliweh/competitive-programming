#include <bits/stdc++.h>
#include <iomanip>

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
const int N = 1e3 + 1;
const int MOD = 1e9 + 7;

int dp[N][N];
char grid[N][N];
int n;

int calc(int i, int j) {
    if(i < 0 || i == n || j < 0 || j == n || grid[i][j] == '*') return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = calc(i, j + 1) + calc(i + 1, j);
    dp[i][j] %= MOD;
    return dp[i][j];

}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }

    dp[n - 1][n - 1] = 1;

    cout << calc(0, 0);

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