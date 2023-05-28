// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

map<int, pair<int, int>> pos;
vector<vector<int>> vecs;
int MAX = 2023 * (2023 - 1) / 2;

void go(int i, int j, int arr, int ind) {
    if (i > MAX) return;
    assert(pos.count(i) == 0);
    pos[i] = {arr, ind};
    vecs[arr].push_back(i * i);
    go(i + j, j + 1, arr, ind + 1);
}

int get_row(int n) {
    int s = 0, e = 2023 + 1;
    while (e - s > 1) {
        int mid = (s + e) / 2;
        if (mid * (mid + 1) / 2 < n) {
            s = mid;
        } else {
            e = mid;
        }
    }
    return s + 1;
}

ll ans(int n) {
    debug(n);
    auto [i, j] = pos[n];
    int r = get_row(n);
    debug(n, r);
    return vecs[i][j] + (n != (r) * (r + 1) / 2 ? ans(n - get_row(n) + 1) : 0);
}

void solve() {
    int n;
    cin >> n;
    cout << ans(n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1, j = 1; i <= MAX; i += j++) {
        vecs.push_back({});
        go(i, j + 1, vecs.size() - 1, 0);
    }

    for (int i = 0; i < vecs.size(); i++) {
        for (int j = 1; j < vecs[i].size(); j++) {
            vecs[i][j] += vecs[i][j - 1];
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
