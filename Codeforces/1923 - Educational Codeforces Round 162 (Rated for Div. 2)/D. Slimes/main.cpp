// ﷽
// https://codeforces.com/contest/1923/problem/D

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

vector<int> solveit(int n, const vector<int> &a) {
    vector<int> ans(n, 1e9);
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];

    int last = -1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            ans[i] = 1;
        } else if (last != -1) {
            int sum = ps[i] - ps[last];
            if (sum > a[i]) {
                ans[i] = i - last;
            } else {
                // binary search
                int l = -1, r = i;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (ps[i] - ps[mid] > a[i]) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }

                if (l > -1) ans[i] = i - l;
            }
        }

        if (a[i] != a[i - 1]) {
            last = i - 1;
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto l = solveit(n, a);
    reverse(all(a));
    auto r = solveit(n, a);
    reverse(all(r));
    debug(l);
    debug(r);

    for (int i = 0; i < n; i++) {
        int x = min(l[i], r[i]);
        if (x == 1e9) x = -1;
        cout << x << ' ';
    }
    cout << endl;
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
