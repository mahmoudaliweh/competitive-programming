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
int dp[N][64];
int arr[N];
int k;

int kBitsANDS(int i, int AND_RESULT) {

    if(i == n) {
        return (__builtin_popcount(AND_RESULT) == k ? 1 : 0);
    }
    if(dp[i][AND_RESULT] != -1) return dp[i][AND_RESULT];

    dp[i][AND_RESULT] = (kBitsANDS(i + 1, AND_RESULT) + kBitsANDS(i + 1, AND_RESULT & arr[i])) % MOD;
    return dp[i][AND_RESULT];
}

void solve() {

    cin >> n >> k;
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
        for(int j = 0 ; j < 64; j ++) {
            dp[i][j] = -1;
        }
    }

    cout << kBitsANDS(0, 63) - (k == 6 ? 1 : 0) << endl;



}

int main() {
    setup_io();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}