#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;

            for (int j = i + 1; j < n; ++j) {
                if (row[j] == '1') {
                    adj[i].push_back(j);
                    indegree[j]++;
                } else {
                    adj[j].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                cerr << i << ' ';
                q.push(i);
            }
        }
        cerr << endl;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for (int neighbor: adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        int val[n];

        for (int i = 0; i < n; i++) {
            val[topo[i]] = i;
        }

        for (int x: topo) {
            cout << x + 1 << " ";
        }
        cout << endl;

        // for (int x: val) {
        //     cout << x + 1 << " ";
        // }
        // cout << "\n";

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

