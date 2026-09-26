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

int m;
ll grid[2][N];
ll pre[2][N];
ll suff[2][N];

void solve() {

    cin >> m;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0 ; j < m; j ++) {
            cin >> grid[i][j];
            grid[i][j]++;
        }
    }
    grid[0][0] = 0;

    for(int i = 0 ; i < 2; i ++) {
        for(int j = 0 ; j < m ; j++) {
            pre[i][j] = 0;
            suff[i][j] = 0;
        }
    }

    for(int j = 0; j < m; j ++) {
        if(j & 1) {
            pre[1][j] = max<ll>(pre[1][j - 1] + 1, grid[1][j]);
            pre[0][j] = max<ll>(pre[1][j] + 1, grid[0][j]);
        } else {
            if(j) {
                pre[0][j] = max<ll>(pre[0][j - 1] + 1, grid[0][j]);
            }
            pre[1][j] = max<ll>(pre[0][j] + 1, grid[1][j]);
        }
    }

    suff[0][m] = 0;
    suff[1][m] = 0;
    for(int j = m - 1; j >= 0; j--) {
        suff[0][j] = max<ll>({grid[1][j], grid[0][j] + (m - j) * 2 - 1, suff[0][j + 1] + 1});
        suff[1][j] = max<ll>({grid[0][j], grid[1][j] + (m - j) * 2 - 1, suff[1][j + 1] + 1});
    }

    ll ans = suff[0][0];
    for(int j = 0 ; j < m ; j ++) {
        ll snake;
        ll u;
        if(j & 1) {
            snake = pre[0][j] + (m - j) * 2 - 2;
            u = suff[0][j + 1];
        } else {
            snake = pre[1][j] + (m - j) * 2 - 2;
            u = suff[1][j + 1];
        }

        ans = min(ans, max(snake ,u));
    }

    cout << ans << endl;
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