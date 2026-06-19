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

const int N = 200;
int n, m;
bool visited[N][N];
vector<int> adj[N];
vector<int> colors[N][N];
int x, y;
int result = 0;
int found[N];


void dfs(int v, int dest, int color) {
    if(found[color]) return;
    if(v == dest){
        result++;
        found[color] = true;
        return;
    }
    if(visited[v][color]) return;
    visited[v][color] = true;

  
    for(auto u : adj[v]){
        for(auto c : colors[u][v]){
            if(color == 0){ 
                dfs(u, dest, c);
            } else {
                if(c == color) dfs(u, dest, color);
            }
        }
    }
}

void solve() {

   cin >> n >> m;
   int c;
   for(int i = 0 ; i < m ; i++){
        cin >> x >> y >> c;
        adj[x].push_back(y);
        adj[y].push_back(x);
        colors[x][y].push_back(c);
        colors[y][x].push_back(c);
   }

   int q;
   cin >> q;
   while (q--)
   {
    cin >> x >> y;
    dfs(x, y, 0);

    cout << result << endl;
    result = 0;
    for(int i = 0 ; i < N; i ++){
        found[i] = false;
        for(int j = 0 ; j < N; j ++){
        visited[i][j] = false;
     }
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
