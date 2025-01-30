#include <bits/stdc++.h>
using namespace std;

char input[501][501];
int dp[501][501], vis[501][501];
queue<pair<int, int>> qu;
int n;

bool safe(int i, int j) {
    return (i >= 1) && (i <= n) && (j >= 0) && (j < n) && (input[i][j] != '#') && (vis[i][j] == 0);
}

void bfs(int a, int b) {
    qu.push(make_pair(a, b));
    vis[a][b] = 1;

    while (!qu.empty()) {
        auto [i, j] = qu.front();
        qu.pop();

        if (input[i][j] == '*') dp[i][j]++;
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);

        if (safe(i + 1, j)) {
            vis[i + 1][j] = 1;
            qu.push(make_pair(i + 1, j));
        }
        if (safe(i, j + 1)) {
            vis[i][j + 1] = 1;
            qu.push(make_pair(i, j + 1));
        }
    }
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        cin >> n;
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);

        for (int i = 1; i <= n; i++) cin >> input[i];
        bfs(1, 0);

        if (vis[n][n - 1]) cout << dp[n][n - 1] << endl;
        else cout << "-1\n";
    }
}
