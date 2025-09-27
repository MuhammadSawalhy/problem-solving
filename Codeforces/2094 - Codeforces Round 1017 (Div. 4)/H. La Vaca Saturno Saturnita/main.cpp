#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

const int Q = 5e4 + 4, M = 1e5 + 5, N = 1e5 + 5;

// Q * log(M) * (M)^(1/3)
// N * log(Q * (M)^(1/3))

vector<int> divs[M], inds[M];

void solve() {
    int n, q;
    cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int r[q];
    vector<long long> ans(q), val(q);
    vector<int> queries[n];

    for (int i = 0; i < q; i++) {
        int k, l;
        cin >> k >> l >> r[i], l--, r[i]--;
        val[i] = k;
        queries[l].push_back(i);
    }

    for (int i = n - 1; ~i; i--) inds[a[i]].push_back(i);
    for (int i = 0; i < n; i++) {
        while (queries[i].size()) {
            int j = queries[i].back();
            queries[i].pop_back();
            while (val[j] % a[i] == 0) {
                val[j] /= a[i];
            }
            int nxt = n;
            for (auto d: divs[val[j]]) {
                if (inds[d].size())
                    nxt = min(nxt, inds[d].back());
            }
            if (nxt > r[j]) {
                ans[j] += (r[j] - i + 1) * val[j];
            } else {
                ans[j] += (nxt - i) * val[j];
                queries[nxt].push_back(j);
            }
        }
        inds[a[i]].pop_back();
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) divs[j].push_back(i);
    }

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
