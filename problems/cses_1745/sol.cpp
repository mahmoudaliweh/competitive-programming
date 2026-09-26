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
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

int n;
int arr[101];
bool dp[101][N];
set<int> ans;
void moneySum(int i, int cur) {
    if(i == n) return;
    if(dp[i][cur]) return;
    dp[i][cur] = true;

    ans.insert(cur + arr[i]);
    moneySum(i + 1, cur);
    moneySum(i + 1, cur + arr[i]);
}
void solve() {

    cin >> n;
    for(int i = 0 ; i < n; i ++) {
        cin >> arr[i];
    }

    moneySum(0, 0);
    cout << ans.size() << endl;
    for(auto it : ans) {
        cout << it << ' ';
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