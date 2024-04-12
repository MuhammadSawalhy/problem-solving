// ﷽
// https://codeforces.com/contest/1942/problem/C1

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a;
    for (int i = 0; i < x; i++) {
        int x;
        cin >> x, x--;
        a.push_back(x);
    }

    sort(all(a));
    int ans = x - 2;
    vector<int> diffs;

    debug(a);
    for (int i = 1; i < x; i++) {
        diffs.push_back(a[i] - a[i - 1] - 1);
    }

    diffs.push_back(a[0] + n - a[x - 1] - 1);

    sort(all(diffs));

    for (int i = 1; i < n;i ++) {
        int j = i;
    }

    ans += y * 2;

    debug(ans);

    for (auto &d: diffs) {
        // odd
        if (~d & 1) continue;
        if (d == 0) continue;
        if ((d - 1) / 2 > y) break;
        debug(d);
        y -= (d - 1) / 2;
        ans++;
        debug(ans);
    }

    cout << min(ans, n - 2) << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
