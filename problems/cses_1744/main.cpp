#include <bits/stdc++.h>
#include <cmath>
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
const int N = 1e2 * 5 + 1;
const int MOD = 1e9 + 7;

int dp[N][N];
int a, b;

int minCuts(int w, int h) {

    if(dp[w][h] != -1) return dp[w][h];

    dp[w][h] = INT_MAX;
    for(int i = 1; i < w / 2 + 1; i++) {
        int steps = minCuts(i, h) + minCuts(w - i, h) + 1;
        dp[w][h] = min(dp[w][h], steps);
    }

    for(int i = 1; i < h / 2 + 1; i++) {
        int steps = minCuts(w, i) + minCuts(w, h - i) + 1;
        dp[w][h] = min(dp[w][h], steps);
    }

    return dp[w][h];
}

void solve() {

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            dp[i][j] = -1;
            if(i == j) {
                dp[i][j] = 0;
            }
        }
    }
    cin >> a >> b;
    cout << minCuts(a, b);

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