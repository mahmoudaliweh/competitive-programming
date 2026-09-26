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

int mix(int l, int r) {

    if(dp[l][r] != -1) return dp[l][r];

    int minSmoke = INT_MAX;
    for(int i = l; i <= r - 1; i ++) {

        int smoke = ((pre[i] - pre[l - 1]) % 100) * ((pre[r] - pre[i]) % 100) + mix(l, i) + mix(i + 1, r);
        minSmoke = min(minSmoke, smoke);
    }

    dp[l][r] = minSmoke;
    return dp[l][r];

}

void solve() {

    while (cin >> n) {
        for(int i = 1; i <= n; i ++) {
            cin >> pre[i];
            pre[i] += pre[i - 1];
            for(int j = 1; j <= n; j ++) {
                if(i != j) dp[i][j] = -1;
            }
        }

        cout << mix(1, n) << endl;
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