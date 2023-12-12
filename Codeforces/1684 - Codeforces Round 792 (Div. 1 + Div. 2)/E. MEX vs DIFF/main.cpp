// ﷽
// https://codeforces.com/contest/1684/problem/E

#include <bits/stdc++.h>
#include <queue>
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

void solve() {
    int n, k, kk;
    cin >> n >> k, kk = k;

    int a[n];
    map<int, int> fr;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    priority_queue<int> used;
    priority_queue<int, vector<int>, greater<int>> unused;

    auto balance = [&](int extra) {
        while (used.size() && unused.size() && used.top() > unused.top()) {
            // swap
            int u = used.top(), un = unused.top();
            used.pop(), k += u;
            unused.pop(), k -= un;
            unused.push(u);
            used.push(un);
        }

        while (used.size() && k < extra) {
            k += used.top();
            unused.push(used.top());
            used.pop();
        }

        while (unused.size() > 1 && k - extra >= unused.top()) {
            k -= unused.top();
            used.push(unused.top());
            unused.pop();
        }
    };

    for (auto [x, f]: fr) {
        if (x > n)
            unused.push(f);
    }

    debug_itr(a, n);
    int ans = 1e9;

    int missed[n + 1], ps[n + 1];
    missed[0] = fr[0] == 0, ps[0] = fr[0];
    for (int i = 1; i <= n; i++) {
        missed[i] = missed[i - 1] + (fr[i] == 0);
        ps[i] = ps[i - 1] + fr[i];
    }

    for (int m = n; m >= 0; m--) {
        if (fr[m] > kk) goto end;
        if (m > 0 && missed[m - 1] > kk) goto end;
        if (n - (m > 0 ? ps[m - 1] : 0) <= kk) ans = 0;

        balance(fr[m]);

        debug(m, used.size(), unused.size());
        minit(ans, (ll) unused.size());

    end:
        if (fr[m])
            unused.push(fr[m]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
