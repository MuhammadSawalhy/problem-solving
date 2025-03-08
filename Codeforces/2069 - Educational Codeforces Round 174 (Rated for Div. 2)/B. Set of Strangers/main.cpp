#include <bits/stdc++.h>
using namespace std;
#define int long long

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n + 2][m + 2];
    memset(a, 0, sizeof a);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], s.insert(a[i][j]);
    }

    map<int, bool> adj;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int ii = i + di[k];
                int jj = j + dj[k];
                if (a[i][j] == a[ii][jj]) adj[a[i][j]] = 1;
            }
        }
    }

    int ans;
    if (adj.size()) ans = (adj.size() - 1) * 2 + (s.size() - adj.size());
    else ans = s.size() - 1;
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
