#include <bits/stdc++.h>
// #define CLION

using namespace std;

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 1;
int n, m;
bool visited[N];
bool took[N];

vector<int> adj[N];
int x, y;
vector<int> output;
bool noSol = false;


void dfs(int v) {
    if(took[v] || noSol) return;
    if(visited[v]){
        noSol = true;
    }
    visited[v] = true;
    for(auto prequiste : adj[v]){
        dfs(prequiste);
    }
    took[v] = true;
    output.push_back(v);
}

void solve() {

   cin >> n >> m;
   for(int i = 1; i <= m; i ++){

    cin >> x >> y;
    adj[y].push_back(x);

   }

   for(int i = 1; i <= n; i ++){
    if(noSol) break;
    if(!visited[i]) dfs(i);
   }

   if(noSol){
    cout << "IMPOSSIBLE\n";
   } else {
    for(auto it : output){
        cout << it << ' ';
    }
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
