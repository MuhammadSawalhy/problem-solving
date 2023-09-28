// بسم الله الرحمن الرحيم
// https://codeforces.com/contest/1878/problem/D
// Codeforces -> Codeforces Round 900 (Div. 3) -> D. Reverse Madness

#include <algorithm>
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
    string s;
    cin >> s;
    int l[k], r[k];
    for (int i = 0; i < k; i++) {
        cin >> l[i], l[i]--;
    }
    for (int i = 0; i < k; i++) {
        cin >> r[i], r[i]--;
    }

    vector<bool> rev(n + 1);

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x, x--;
        int i = lower_bound(r, r + k, x) - r;
        int a = min(x, l[i] + r[i] - x);
        int b = max(x, l[i] + r[i] - x);
        assert(a <= b);
        assert(a >= l[i]);
        assert(b <= r[i]);

        rev[a] = rev[a] ^ 1;
        rev[b + 1] = rev[b + 1] ^ 1;
    }

    for (int i = 1; i <= n; i++) {
        rev[i] = rev[i] ^ rev[i - 1];
    }

    for (int i = 0; i < k; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            int k = r[i] + l[i] - j;
            assert(rev[j] == rev[k]);
            if (rev[j] && j < k) {
                swap(s[j], s[k]);
            }
        }
    }

    cout << s << endl;
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
