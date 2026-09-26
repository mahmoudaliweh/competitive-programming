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
const int N = 1e3 + 1;
const int MOD = 1e9 + 7;

int n, k;
int b[N], c[N];
int dp[N][N * 12];
int dist[N];

int maxCoins(int i, int cur) {

    if(i == n) return 0;
    if(dp[i][cur] != -1) return dp[i][cur];

    dp[i][cur] = maxCoins(i + 1, cur);
    int w = dist[b[i]];
    if(cur >= w) {
        dp[i][cur] = max(dp[i][cur], maxCoins(i + 1, cur - w) + c[i]);
    }
    return dp[i][cur];
}

void solve() {

    cin >> n >> k;
    for(int i = 0 ; i < n; i ++) cin >> b[i];
    for(int i = 0 ; i < n; i ++) cin >> c[i];
    for(int i = 0 ; i < n; i ++) {
        for(int j = 0; j <= min(k, N * 12 - 1); j ++) {
            dp[i][j] = -1;
        }
    }
    cout << maxCoins(0, min(N * 12 - 1, k)) << endl;
}

int main() {
    setup_io();

    for(int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;

    for(int i = 1; i < N; i ++) {
        for(int j = 1; j <= i; j++) {
            if(i + i / j < N) {
                dist[i + i / j] = min(dist[i + i / j], dist[i] + 1);
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}