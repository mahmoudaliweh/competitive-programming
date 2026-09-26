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
const int N = 5 * 1e3 + 1;
const int MOD = 1e9 + 7;

int n;

int freq[N];
ll dp[N];

void solve() {

    cin >> n;
    for(int i = 0 ; i < N; i ++) {
        dp[i] = -1;
    }
    for(int i = 0; i < N; i ++) {
        freq[i] = 0;
    }
    dp[0] = 0;

    ll currentMux = 0;
    for(int i = 0 ; i < n; i ++) {
        ll x;
        cin >> x;
        if(x <= n) {
            freq[x]++;
        }
        while (freq[currentMux]) {
            currentMux++;
        }
    }

    for(int i = 1; i <= currentMux; i++) {
        ll m = LONG_LONG_MAX;
        for(int j = 0; j < i; j++) {
            m = min(m, (freq[j] - 1) * i + j + dp[j]);
        }
        dp[i] = m;
    }

    cout << dp[currentMux] << endl;

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