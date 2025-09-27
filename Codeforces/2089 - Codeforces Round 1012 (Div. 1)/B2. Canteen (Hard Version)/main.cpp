#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (sum <= k) {
        cout << "0\n";
        return;
    }
    int l = 0, r = n;
    int aa[n], bb[n];
    debug_itr(a, n);
    debug_itr(b, n);
    while (r - l > 1) {
        int m = (l + r) >> 1;
        stack<int> st;
        memcpy(aa, a, n * sizeof(a[0]));
        memcpy(bb, b, n * sizeof(b[0]));

        for (int i = 0; i < n; i++) {
            st.push(i);
            while (!st.empty() && bb[i] && i - st.top() + 1 <= m) {
                int d = min(aa[st.top()], bb[i]);
                aa[st.top()] -= d;
                bb[i] -= d;
                if (aa[st.top()] == 0) st.pop();
            }
        }

        for (int i = 0; i < m; i++) {
            while (!st.empty() && bb[i] && i + n - st.top() + 1 <= m) {
                int d = min(aa[st.top()], bb[i]);
                aa[st.top()] -= d;
                bb[i] -= d;
                if (aa[st.top()] == 0) st.pop();
            }
        }

        debug(m);
        debug_itr(aa, n);
        debug_itr(bb, n);

        int sum = 0;
        for (int i = 0; i < n; i++) sum += aa[i];
        if (sum > k) l = m;
        else r = m, debug(r);
    }

    cout << r << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
