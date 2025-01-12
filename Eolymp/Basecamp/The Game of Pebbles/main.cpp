#include <bits/stdc++.h>
using namespace std;

int n, m;
bool dp[1001];
bool vis[1001];

bool solve(int n) {
    if (vis[n]) return dp[n];
    vis[n] = true;
    if (n == 0) return dp[n] = false;

    for (int i = 1; i <= min(n, m); i++) {
        if (!solve(n - i)) return dp[n] = true;
    }

    return dp[n] = false;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= min(n, m); i++) {
        if (!solve(n - i)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}

