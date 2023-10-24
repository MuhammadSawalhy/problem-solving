// ﷽
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A2?source=codeforces

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 3003;
string go[N];
bool vis[N][N];
int r, c;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < r && j < c && !vis[i][j];
}

pair<bool, int> dfs(int i, int j, int oi, int oj) {
    vis[i][j] = true;
    bool good = true;
    int cnt = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (!valid(ni, nj)) continue;
        // debug(i, j, ni, nj, oi, oj);
        if (go[ni][nj] == 'W') {
            auto res = dfs(ni, nj, oi, oj);
            good &= res.first;
            cnt += res.second;
        } else if (go[ni][nj] == '.' && (ni != oi || nj != oj)) {
            good = false;
        }
    }
    return {good, cnt};
}

int get_ans(int i, int j) {
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (valid(ni, nj) && go[ni][nj] == 'W') {
            auto res = dfs(ni, nj, i, j);
            if (res.first)
                ans += res.second;
        }
    }
    return ans;
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> go[i];
        for (int j = 0; j < c; j++) {
            vis[i][j] = false;
        }
    }

    debug(r, c);

    int mx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (go[i][j] == '.') {
                mx = max(mx, get_ans(i, j));
            }
        }
    }

    debug(mx);
    cout << (mx > 0 ? "YES" : "NO") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
        cout << "Case #" << tc << ": ", solve();

    return 0;
}
