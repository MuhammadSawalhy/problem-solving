// ﷽
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
    string s, t;
    cin >> s >> t;

    string T, S;
    int l = lcm(s.size(), t.size());
    while (T.size() != l)
        T += t;
    while (S.size() != l)
        S += s;

    if (T != S) {
        cout << "-1\n";
    } else {
        cout << T << '\n';
    }
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
