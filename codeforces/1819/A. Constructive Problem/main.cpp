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

void solve() {
    int n;
    cin >> n;
    ll a[n];
    set<int> s;
    for (int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]);
    int mex = -1;
    for (int i = 0; i <= n; i++) {
        if (!s.count(i)) {
            mex = i;
            break;
        }
    }
    assert(~mex);
    debug(mex);

    if (s.count(mex + 1)) {
        int j = n, k = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == mex + 1) {
                j = min(j, i);
                k = max(k, i);
            }
        }

        s.clear();
        for (int i = 0; i < n; i++) {
            if (i >= j && i <= k) {
                a[i] = mex;
            }
            s.insert(a[i]);
        }

        int newmex = -1;
        for (int i = 0; i <= n; i++) {
            if (!s.count(i)) {
                newmex = i;
                break;
            }
        }

        debug(newmex);

        if (newmex == mex + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        sort(a, a + n);
        int j = upper_bound(a, a + n, mex) - a;
        if (j == n && n == mex) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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
