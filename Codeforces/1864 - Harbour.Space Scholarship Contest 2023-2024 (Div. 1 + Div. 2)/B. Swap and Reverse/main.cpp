// ﷽
// https://codeforces.com/contest/1864/problem/B
// Codeforces -> Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2) -> B. Swap and Reverse

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (k & 1) {
        string a, b;
        for (int i = 0; i < n; i++)
            if (i & 1) a += s[i];
            else b += s[i];

        sort(all(a));
        sort(all(b));

        reverse(all(a));
        reverse(all(b));

        s = "";
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                s += a.back();
                a.pop_back();
            } else {
                s += b.back();
                b.pop_back();
            }
        }
    } else {
        sort(all(s));
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
