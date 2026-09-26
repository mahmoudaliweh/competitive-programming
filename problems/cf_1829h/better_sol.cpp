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

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;

int n;
ll dp[64][64];
ll freq[64];
ll p2[200005];
int k;

ll kBitsANDS(int i, int AND_RESULT) {

    if(i == 64) {
        return (__builtin_popcount(AND_RESULT) == k ? 1 : 0);
    }
    if(dp[i][AND_RESULT] != -1) return dp[i][AND_RESULT];

    ll ans = kBitsANDS(i + 1, AND_RESULT);

    if(freq[i] > 0) {
        ll subset_ways = (p2[freq[i]] - 1 + MOD) % MOD;
        ll take_ways = (kBitsANDS(i + 1, AND_RESULT & i) * subset_ways) % MOD;
        ans = (ans + take_ways) % MOD;
    }
    dp[i][AND_RESULT] = ans;
    return dp[i][AND_RESULT];
}

void solve() {

    cin >> n >> k;
    memset(freq, 0, sizeof(freq));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    cout << kBitsANDS(0, 63) - (k == 6 ? 1 : 0) << endl;



}

int main() {
    setup_io();

    p2[0] = 1;
    for (int i = 1; i <= 200000; i++) p2[i] = (p2[i - 1] * 2) % MOD;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}