// ﷽
// https://codeforces.com/contest/1886/problem/C

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

char t[1000'001];

void solve() {
    string s;
    int pos;
    cin >> s >> pos;

    int n = s.size();
    int total = 0;
    int m = 0;

    while (pos > n - m) {
        pos -= n - m;
        m++;
    }

    vector nxtlt(26, vector<int>(n, -1));

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxtlt[j][i - 1] = nxtlt[j][i];
        }
        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            nxtlt[j][i - 1] = i;
        }
    }

    int j = 0;
    for (int i = 0; i < n;) {
        int nxt = nxtlt[s[i] - 'a'][i];
        int d = nxt - i;
        debug(i, nxt);

        if (nxt == -1 || d > m) {
            t[j++] = s[i++];
            continue;
        }

        i += d;
        m -= d;
    }

    debug_itr(t, t + j);
    cout << t[pos - 1];
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
