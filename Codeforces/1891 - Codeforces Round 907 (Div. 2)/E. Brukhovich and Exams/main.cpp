// ﷽
// https://codeforces.com/contest/1891/problem/E

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
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (k && i > 1 && a[i] != 1 && a[i - 1] == 1 && a[i - 2] != 1) {
            a[i - 1] = 0;
            k--;
        }
    }

    debug("=======");
    debug(k);

    int s = 0, e = n;
    vector<int> b[2], ones;

    while (s < n && a[s] == 1) s++;
    while (e > 0 && a[e - 1] == 1) e--;
    if (s == n) e = n;
    debug(s, e);

    for (int i = s, j; i < e;) {
        j = i + 1;

        if (a[i] == 1) {
            while (j < n && a[j] == 1)
                j++;
            ones.push_back(j - i);
            i = j;
            continue;
        }

        while (j < n && gcd(a[j], a[j - 1]) == 1 && a[j] != 1) {
            j++;
        }

        if (j - i > 1)
            b[(j - i) & 1].push_back(j - i);

        i = j;
    }

    debug(ones);
    debug(b[0]);
    debug(b[1]);

    int ans = 0;

    for (int i = 0; k && i < b[1].size(); i++) {
        int todo = min(k, b[1][i] / 2);
        ans -= todo * 2;
        k -= todo;
    }

    for (int i = 0; k && i < b[0].size(); i++) {
        int todo = min(k, b[0][i] / 2 - 1);
        ans -= todo * 2;
        k -= todo;
    }

    debug(k);
    sort(all(ones));
    for (int i = 0; k && i < ones.size(); i++) {
        if (k >= ones[i]) {
            ans -= ones[i] + 1;
            k -= ones[i];
        } else {
            ans -= k;
            k = 0;
        }
    }

    int todo = min((int) b[0].size(), k);
    k -= todo;
    ans -= todo;

    ans -= min(s + n - e, k - (s == n));

    for (int i = 1; i < n; i++) {
        ans += gcd(a[i], a[i - 1]) == 1;
    }

    cout << ans << endl;
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
