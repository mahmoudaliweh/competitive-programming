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
const int N = 1e6 + 1;
const int MOD = 1e9 + 7;
int n, target;
vector<int> v;
int dp[N];

int nWays(int sum) {

    int total = 0;
    for(int i = 0; i < n; i++) {
        if(sum - v[i] >= 0) {
            if(dp[sum - v[i]] == -1) nWays(sum - v[i]);
            total += dp[sum - v[i]];
            total %= MOD;
        }
    }

    dp[sum] = total;
    return dp[sum];
}
void solve() {

    cin >> n >> target;
    v.resize(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    for(int i = 0; i < N; i ++) {
        dp[i] = -1;
    }
    dp[0] = 1;

    cout << nWays(target);
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
