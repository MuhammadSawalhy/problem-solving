// ﷽
// https://codeforces.com/contest/1775/problem/E

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

int sgn(int x) {
    return x < 0 ? -1 : x > 0 ? 1
                              : 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            if (b.size() && sgn(b.back()) == sgn(a[i]))
                b.back() += a[i];
            else
                b.push_back(a[i]);

            while (b.size() > 2 && abs(b.end()[-3]) > abs(b.end()[-2]) && abs(b.end()[-1]) >= abs(b.end()[-2])) {
                int x, y, z;
                x = b.end()[-3];
                y = b.end()[-2];
                z = b.end()[-1];
                b.pop_back(), b.pop_back(), b.pop_back();
                b.push_back(x + y + z);
            }
        }

        int ans = 0;
        for (int i = 0; i < (int) b.size(); i++) {
            maxit(ans, abs(b[i]));
        }

        cout << ans << endl;
    }

    return 0;
}
