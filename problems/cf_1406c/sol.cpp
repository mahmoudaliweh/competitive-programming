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

const int N = 1e5 + 1;
int n, m;
vector<int> adj[N];
int nOfNodes[N];
int maxSubtreeNodes[N];

struct CompareSecondAscending {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecondAscending> pq;


int numberOfNodesInSubtree(int v, int p) {
    int total = 1;
    for (auto child : adj[v]) {
        if (child == p) continue;
        total += numberOfNodesInSubtree(child, v);
    }
    nOfNodes[v] = total;
    return total;
}

void dfsThatGetsCentroids(int v, int p) {
    int maxSubtreeNodes = 0;
    if (p != -1) {
        maxSubtreeNodes = n - nOfNodes[v];
    }

    for (auto child : adj[v]) {
        if (child == p) continue;
        maxSubtreeNodes = max(maxSubtreeNodes, nOfNodes[child]);
        dfsThatGetsCentroids(child, v);
    }

    pq.push({ v, maxSubtreeNodes });
}

pair<int, int> getLeafEdge(int v, int p) {
    if (adj[v].size() == 1) {
        return { v, p };
    }
    for (auto child : adj[v]) {
        if (child == p) continue;
        return getLeafEdge(child, v);
    }
}

void solve() {
    cin >> n;
    m = n - 1;
    int x, y;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    numberOfNodesInSubtree(1, -1);
    dfsThatGetsCentroids(1, -1);

    pair<int, int> first, second;
    first = pq.top();
    pq.pop();
    second = pq.top();
    while (!pq.empty()) {
        pq.pop();
    }

    if (first.second == second.second) {
        auto edg = getLeafEdge(first.first, second.first);
        cout << edg.first << ' ' << edg.second << endl;
        cout << edg.first << ' ' << second.first << endl;
    }
    else {
        cout << first.first << ' ' << second.first << endl;
        cout << first.first << ' ' << second.first << endl;
    }

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
