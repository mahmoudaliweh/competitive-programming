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

const int INF = INT_MAX;

const int N = 1e5 + 1;
int n;
vector<int> adj[N];
int parent[N];
bool isProblem[N];
bool visited[N];
int nProblems = 0;
priority_queue<pair<int, int> > pq;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void bfs(int v) {
    parent[v] = -1;

    queue<int> frontier;
    frontier.push(v);

    int level = 0;
    int size;
    while (!frontier.empty()) {
        size = frontier.size();
        while (size--) {
            int curr = frontier.front();
            frontier.pop();
            if (isProblem[curr]) {
                pq.push({level, curr});
                nProblems++;
            }

            for (auto u: adj[curr]) {
                if (parent[u]) continue;
                parent[u] = curr;
                frontier.push(u);
            }
        }
        level++;
    }
}


void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        isProblem[a] = (c == 2) || isProblem[a];
        isProblem[b] = (c == 2) || isProblem[b];
    }

    bfs(1);

    vector<int> ans;
    while (nProblems) {
        auto it  = pq.top();
        pq.pop();

        int current = it.second;
        if(isProblem[current]) {
            ans.push_back(current);
            while (current != -1) {
                if(visited[current]) break;
                visited[current] = true;
                if(isProblem[current]) nProblems--;
                if(!nProblems) break;
                isProblem[current] = false;
                current = parent[current];
            }
        }
    }

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
