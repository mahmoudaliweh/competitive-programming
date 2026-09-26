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
const int N = 2e3 + 1;
const int MOD = 1e9 + 7;

int n, h, l, r;
int a[N];
int dp[N][N];

int goodSleeps(int i, int time) {

    if(i == n) return 0;
    if(dp[i][time] != - 1) return dp[i][time];

    int t1 = (a[i] + time) % h;
    int t2 = (a[i] - 1 + time) % h;

    dp[i][time] = max(goodSleeps(i + 1, t1) + (t1 >= l && t1 <= r ? 1 : 0), goodSleeps(i + 1, t2) + (t2 >= l && t2 <= r ? 1 : 0));
    return dp[i][time];
}

void solve() {

    cin >> n >> h >> l >> r;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < n; i ++) {
        for(int j = 0; j < h; j ++) {
            dp[i][j] = -1;
        }
    }
    cout << goodSleeps(0, 0) << endl;

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