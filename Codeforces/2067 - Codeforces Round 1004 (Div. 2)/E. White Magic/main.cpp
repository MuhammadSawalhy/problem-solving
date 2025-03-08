#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    multiset<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            s.insert(a[i]);
            cnt++;
        }
    }

    bool f = false;

    if (cnt < n) {
        int mex = 1;
        auto it = s.begin();
        while (it != s.end() && *it <= mex) mex = *it + 1, it++;
        debug(mex);

        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            debug(i, a[i]);
            if (mn < mex) break;

            if (a[i] == 0) {
                f = true;
                break;
            } else {
                mn = min(mn, a[i]);

                s.erase(s.find(a[i]));
                if (s.find(a[i]) == s.end()) {
                    mex = min(mex, a[i]);
                }
            }
        }
    }

    cout << cnt + f << endl;
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
