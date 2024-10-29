#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define N 100001

int a[N];
vector<int> adj[N];

// Function to compute LIS for a given array using binary search
int lis(const vector<int> &seq) {
    vector<int> dp(seq.size() + 1, LLONG_MAX);
    dp[0] = LLONG_MIN;

    for (const auto &value: seq) {
        int pos = upper_bound(dp.begin(), dp.end(), value) - dp.begin();
        if (dp[pos - 1] < value && value < dp[pos]) {
            dp[pos] = value;
        }
    }

    // Find the maximum length of increasing subsequence
    int maxLength = 0;
    for (int i = 0; i <= seq.size(); ++i) {
        if (dp[i] < LLONG_MAX) {
            maxLength = i;
        }
    }
    return maxLength;
}

// DFS function to gather LIS along paths
void dfs(int node, int parent, vector<int> &path, int &result) {
    path.push_back(a[node]);
    result = max(result, lis(path));

    for (int neighbor: adj[node]) {
        if (neighbor == parent) continue; // Prevent going back to parent
        dfs(neighbor, node, path, result);
    }

    path.pop_back(); // Backtrack
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        vector<int> path;
        if (adj[i].size() == 1)
            dfs(i, -1, path, ans);
    }

    cout << ans << endl;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
