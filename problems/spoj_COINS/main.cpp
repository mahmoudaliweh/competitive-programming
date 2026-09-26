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

unordered_map<int, ll> dp;
int n;

ll calc(int num) {

    ll total = 0;
    for(int i = 2; i <= 4; i ++) {
        int v = num / i;
        if(v) {
            if(!dp[v]) calc(v);
            total += dp[v];
        }
    }

    total = max((ll)(num), total);
    dp[num] = total;
    return dp[num];
}

void solve() {
    while (cin >> n) {
        dp.clear();
        dp[1] = 1;
        cout << calc(n) << endl;

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