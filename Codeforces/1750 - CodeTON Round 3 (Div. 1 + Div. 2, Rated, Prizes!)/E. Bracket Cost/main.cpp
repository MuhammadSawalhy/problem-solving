// ﷽
// https://codeforces.com/contest/1750/problem/E

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

int n;

void solve() {
    cin >> n;
    string s;
    cin >> s;

    int a[n + 1], b[n + 1];
    b[0] = a[0] = 0;
    for (int i = 0; i < n; i++) {
        b[i + 1] = a[i + 1] = a[i] + (s[i] == '(' ? +1 : -1);
    }

    int ans = 0;
    sort(b, b + n + 1);
    for (int i = 1; i <= n; i++) {
        ans += b[i] * i;
    }

    vector<int> st, r(n + 1, n + 1), l(n + 1, -1);
    st.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.back()] > a[i]) {
            r[st.back()] = i;
            st.pop_back();
        }
        if (!st.empty()) l[i] = st.back();
        st.push_back(i);
    }

    debug(s);
    debug(ans);
    debug_itr(a, a + n + 1);
    debug(l);
    debug(r);

    for (int i = 1; i <= n; i++) {
        int x = i - l[i];
        int y = r[i] - i;
        ans -= a[i] * (x * y - 1);
        debug(i, x, y);
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
