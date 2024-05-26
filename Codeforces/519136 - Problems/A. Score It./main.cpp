// ﷽
// https://codeforces.com/group/diAwUqxD2g/contest/519136/problem/A

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 101, M = 505;
pair<int, int> parent[N][N * M];
bool sum[N][N * M];

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(parent, -1, sizeof parent);
    sum[0][x] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n * M; j++) {
            if (sum[i][j] && j + a[i] >= 0 && j + a[i] < n * M) {
                sum[i + 1][j + a[i]] = true;
                parent[i + 1][j + a[i]] = {i, j};
            }
            if (sum[i][j]) {
                sum[i + 1][j] = true;
                parent[i + 1][j] = parent[i][j];
            }
        }
    }

    if (!sum[n][0]) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    auto p = parent[n][0];
    while (~p.first) {
        ans.push_back(p.first);
        p = parent[p.first][p.second];
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
    for (auto x : ans) cout << x + 1 << ' ';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
