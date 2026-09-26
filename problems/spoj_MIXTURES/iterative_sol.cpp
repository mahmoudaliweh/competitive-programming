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
const int N = 1e2 + 1;
const int MOD = 1e9 + 7;

int n;
int pre[N];
int dp[N][N];

void solve() {

    while (cin >> n) {
        for(int i = 1; i <= n; i ++) {
            cin >> pre[i];
            pre[i] += pre[i - 1];
            for(int j = 1; j <= n; j ++) {
                if(i != j) dp[i][j] = INT_MAX;
            }
        }

        for(int len = 1; len <= n; len++) {

            for(int i = 1; i + len - 1 <= n; i++) {
                int l = i;
                int r = i + len - 1;

                for(int k = l; k < r; k ++) {
                    int smoke = ((pre[k] - pre[l - 1]) % 100) * ((pre[r] - pre[k]) % 100) + dp[l][k] + dp[k + 1][r];
                    dp[l][r] = min(dp[l][r], smoke);
                }
            }
        }

        cout << dp[1][n] << endl;
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