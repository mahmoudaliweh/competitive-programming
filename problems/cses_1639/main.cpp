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
const int N = 1e3 * 5 + 1;
const int MOD = 1e9 + 7;

int dp[N][N];
string s, t;


int editDist(int i, int j) {

    if (i == s.length()) {
        return t.length() - j;
    }

    if (j == t.length()) {
        return s.length() - i;
    }

    if(dp[i][j] != -1) return dp[i][j];



    int total = INT_MAX;
    if(s[i] != t[j]) {
        int replace = 1 + editDist(i + 1, j + 1);
        int add = 1 + editDist(i, j + 1);
        int remove = 1 + editDist(i + 1, j);
        total = min(replace, add);
        total = min(remove, total);
    } else {
        total = editDist(i + 1, j + 1);
    }
    dp[i][j] = total;
    return total;

}

void solve() {

    cin >> s >> t;
    for(int i = 0 ; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            dp[i][j] = -1;
        }
    }
    cout << editDist(0, 0);
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