// ﷽
// https://codeforces.com/contest/1915/problem/D

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

bool isv(char c) {
    return c == 'a' || c == 'e';
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;

    int i;
    for (i = 0; i + 4 < n;) {
        assert(!isv(s[i]));
        assert(isv(s[i + 1]));
        if (!isv(s[i + 2]) && !isv(s[i + 3])) {
            t += s[i];
            t += s[i + 1];
            t += s[i + 2];
            t += '.';
            i = i + 3;
        } else {
            t += s[i];
            t += s[i + 1];
            t += '.';
            i = i + 2;
        }
    }

    assert(!isv(s[i]));
    if (n - i == 4) {
        assert(!isv(s[i + 2]));
        t += s[i];
        t += s[i + 1];
        t += '.';
        t += s[i + 2];
        t += s[i + 3];
    } else
        while (i < n) t += s[i++];

    cout << t << endl;
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
