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

int n, target;
vector<int> v;
int dp[N];

int minimizeCoins(int sum) {
    if(sum == 0) return 0;

    dp[sum] = INT_MAX;
    for(int i = 0; i < n; i ++) {
        if(sum - v[i] >= 0) {
            if(dp[sum - v[i]] == -1) minimizeCoins(sum - v[i]);
            if(dp[sum - v[i]] == INT_MAX) continue;
            dp[sum] = min(dp[sum], dp[sum - v[i]] + 1);
        }

    }

    return dp[sum];
}
void solve() {

    cin >> n >> target;
    v.resize(n);

    for(int i = 0 ; i < n; i ++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i = 1; i < N; i ++) {
        dp[i] = -1;
    }
    minimizeCoins(target);
    if(dp[target] == INT_MAX) {
        cout << -1;
    } else cout << dp[target];
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
