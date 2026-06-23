#include <bits/stdc++.h>

using namespace std;

void setup_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 * 2 + 1;
vector<int> adj[N];
bool houses[N];
bool found;
deque<int> path;
vector<int> houseSequence;

int dest;
int n, k;

void dfs(int v, int p) {
    if(found) return;
    if(v == dest) {
        found = true;
        return;
    }
    if(p != -1) {
        path.push_back(v);
    }
    for(auto u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        if(found) return;
    }
    path.pop_back();
}

void getSequence(int v, int p) {
    if(houses[v]) houseSequence.push_back(v);

    bool contains = false;
    for(auto u : adj[v]) {
        if(!path.empty() && u == path.front()) {
            contains = true;
            continue;
        }
        if(u == p) continue;
        getSequence(u, v);
    }
    if(contains) {
        int x = path.front();
        path.pop_front();
        getSequence(x, v);
    }


}

void reset() {
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        houses[i] = false;
    }
    found = false;
    path.clear();
    houseSequence.clear();
}

void solve() {

    reset();
    cin >> n >> k;
    int vlad, nastya;
    cin >> vlad >> nastya;

    vector<int> things;
    int x;
    for(int i = 1; i <= k ; i++) {
        cin >> x;
        houses[x] = true;
    }


    int a, b;
    for(int i = 1; i < n;  i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dest = nastya;
    dfs(vlad, -1);
    path.push_back(dest);

    getSequence(vlad, -1);

    int result = 0;
    for(auto it : houseSequence) {
        path.clear();
        dest = it;
        found  = false;
        dfs(vlad, -1);
        result += path.size();
        if(vlad != dest) result += 1;
        vlad = dest;
    }
    path.clear();
    dest = nastya;
    found = false;
    dfs(vlad, -1);
    result += path.size();
    if(vlad != dest) result += 1;
    cout << result << endl;


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
