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

int dp[N];
int n;

int calc(int num) {

    int steps = INT_MAX;
    int cpy = num;

    while (cpy != 0) {
        int remove = cpy % 10;
        if(remove != 0) {
            if(dp[num - remove] == -1) calc(num - remove);
            steps = min(steps, dp[num - remove] + 1);
        }
        cpy /= 10;
    }

    dp[num] = steps;
    return dp[num];
}

void solve() {

    cin >> n;

    for(int i = 1; i <= n; i ++) {
        dp[i] = -1;
    }
    dp[0] = 0;

    calc(n);
    cout << dp[n];

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
