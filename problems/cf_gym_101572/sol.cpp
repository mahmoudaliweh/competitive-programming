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
const int N = 1048576 + 1;
int dist[N];
int n, k;

int maxMask = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Utility By Gemini
int stringToBitmaskMSB(const std::string& s) {
    int mask = 0;
    for (char c : s) {
        mask <<= 1; // Shift left to make room for the next bit
        if (c == '1') {
            mask |= 1;
        }
    }
    return mask;
}

string maskToString(int mask, int k) {
    string s = "";
    for (int i = k - 1; i >= 0; i--) {
        if ((mask >> i) & 1) {
            s += '1';
        } else {
            s += '0';
        }
    }
    return s;
}

void bfs(deque<int> frontier) {

    for(int i = 0 ; i <= maxMask; i++) {
        dist[i] = INF;
    }

    for(auto it : frontier) {
        dist[it] = 0;
    }

    int size;
    int level = 0;

    while (!frontier.empty()) {

        size = frontier.size();
        while (size--) {
            int current = frontier.front();
            frontier.pop_front();
            dist[current] = level;

            for(int i = 0; i < k ; i++) {

                int child = current ^ (1 << i);
                if(dist[child] != INF) continue;

                dist[child] = level + 1;
                frontier.push_back(child);
            }
        }
        level++;

    }

}

void solve() {

    cin >> n >> k;
    string s;

    deque<int> frontier;
    for(int i = 0 ; i < n; i ++) {
        cin >> s;
        int mask = stringToBitmaskMSB(s);
        frontier.push_front(mask);
    }

    maxMask = pow(2, k) - 1;

    bfs(frontier);

    int chosenCharacter = 0;
    int maximumMinDistance = 0;
    for(int i = 0; i <= maxMask; i++) {
        if(dist[i] > maximumMinDistance) {
            maximumMinDistance = dist[i];
            chosenCharacter = i;
        }
    }
    cout << maskToString(chosenCharacter, k) << endl;

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
