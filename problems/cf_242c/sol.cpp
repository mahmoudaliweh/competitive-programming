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

unordered_map<int, vector<pair<int, int>>> segments;
std::map<std::pair<int, int>, bool> visited;
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int i, int j) {
    if(i < 1 || i > 1e9 || j < 1 || j > 1e9) return false;
    bool valid = false;
    for(auto seg : segments[i]) {
        if(j >= seg.first && j <= seg.second) {
            valid = true;
            break;
        }
    }
    if(!valid) return false;
    if(visited[{i, j}]) return false;
    return true;
}
vector<pair<int, int>> getNeighbors(pair<int, int> cell) {
    int x, y;
    vector<pair<int, int>> validMoves;
    for(int i = 0 ; i < 8; i ++) {
        x = cell.first + dx[i];
        y = cell.second + dy[i];
        if(valid(x, y)) validMoves.push_back({x, y});
    }
    return validMoves;
}

queue<pair<int, int>> q;
int bfs(pair<int, int> source, pair<int, int> destination) {
    q.push(source);
    int size;
    int level = 0;
    pair<int, int> current;

    while (!q.empty()) {

        size = q.size();

        while (size--) {
            current = q.front();
            q.pop();
            if(visited[current]) continue;
            visited[current] = true;

            if(current.first == destination.first && current.second == destination.second) return level;


            // this will get all the unvisited neighbors of current cell and add them to the fronteir
            for(auto cell : getNeighbors(current)) {
                q.push(cell);
            }
        }
        level++;
    }

    return - 1;

}


void solve() {

    pair<int, int> source, destination;
    cin >> source.first >> source.second >> destination.first >> destination.second;
    int n;
    cin >> n;
    while (n--) {
        int c1, c2, r;
        cin >> r >> c1 >> c2;
        bool overlap = false;
        for(auto& seg : segments[r]) {
            if(c2 < seg.first || c1 > seg.second) continue;
            overlap = true;
            seg.first = min(seg.first, c1);
            seg.second = max(seg.second, c2);
            break;
        }
        if(!overlap) {
            segments[r].push_back({c1, c2});
        }
    }

    // for(int i = 1; i <= 11; i++) {
    //     cout << "Row: " << i << " Min: " << minC[i] << " Max: " << maxC[i] << endl;
    // }

    cout << bfs(source, destination);

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
