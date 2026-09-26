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
const int N = 5e2 + 1;
const int MOD = 1e9 + 7;

const int N2 = 62625 + 1;
int n;
int dp[N][N2];

int twoSets(int i, int cur) {
    if(cur > (n * (n + 1) / 2 / 2)) return 0;
    if(i == n + 1) return cur == (n * (n + 1) / 2 / 2);
    if(dp[i][cur] != -1) return dp[i][cur];

    dp[i][cur] = twoSets(i + 1, cur + i) + twoSets(i + 1, cur);
    dp[i][cur] %= MOD;
    return dp[i][cur];
}

void solve() {

    cin >> n;

    long long total_sum = 1LL * n * (n + 1) / 2;

    if(total_sum % 2 != 0) {
        cout << 0 << "\n";
        return;
    }
    int target = total_sum / 2;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            dp[i][j] = -1;
        }
    }
    cout << twoSets(2, 1);
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