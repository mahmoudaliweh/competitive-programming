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
const int N = 2e2 + 1;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
int dp[N][513];

int minOR(int i, int curr = 0) {
    if(i == n) {
        return curr;
    }
    if(dp[i][curr] != -1) return dp[i][curr];

    int ans = INT_MAX;
    for(int j = 0 ; j < m; j++) {
        ans = min(ans, minOR(i + 1, (a[i] & b[j]) | curr));
    }

    dp[i][curr] = ans;
    return dp[i][curr];
}
void solve() {

    cin >> n >> m;
    for(int i = 0 ; i < n; i ++) cin >> a[i];
    for(int j = 0 ; j < m ; j++) cin >> b[j];

    for(int i = 0 ; i < n; i++) {
        for(int k = 0; k < 513; k++) {
            dp[i][k] = -1;
        }
    }

    cout << minOR(0) << endl;

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