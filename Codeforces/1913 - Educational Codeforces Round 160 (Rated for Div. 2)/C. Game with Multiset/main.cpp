// ﷽
// https://codeforces.com/contest/1913/problem/C

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

void solve() {
    int n;
    cin >> n;
    vector<int> fr(30);
    for (int i = 0; i < n; i++) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            fr[v]++;
        } else {
            bool ok = true;
            vector<int> a = fr;
            for (int i = 0; i < 30; i++) {
                if (v >> i & 1)
                    ok &= a[i] > 0, a[i]--;
                a[i + 1] += a[i] / 2;
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
