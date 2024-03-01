// ﷽
// https://codeforces.com/contest/1932/problem/C

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

// a * x + b * y = gcd(a, b)
pair<ll, ll> exgcd(ll a, ll b) {
    if (!b) return {1, 0};
    pair<int, int> p = exgcd(b, a % b);
    return {p.second, p.first - (a / b) * p.second};
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;
    int l = 1, r = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            l++;
        } else {
            r--;
        }
    }

    assert(l == r + 1);
    int ans[n + 1];
    ans[n] = 1;
    for (int i = n - 1; ~i; i--) {
        int x = 0;
        if (s[i] == 'L') {
            x = a[--l];
        } else {
            x = a[++r];
        }
        debug(x);
        ans[i] = (ans[i + 1] * x) % m;
    }
    debug_itr(ans, n);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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
