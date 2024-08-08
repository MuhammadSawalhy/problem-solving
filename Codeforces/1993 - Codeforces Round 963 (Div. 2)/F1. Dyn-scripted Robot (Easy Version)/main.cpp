// ﷽
// https://codeforces.com/contest/1993/problem/F1

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int getLR(char c) {
    if (c == 'L') return -1;
    if (c == 'R') return +1;
    return 0;
}

int getUD(char c) {
    if (c == 'D') return -1;
    if (c == 'U') return +1;
    return 0;
}

void solve() {
    int n, k, w, h;
    cin >> n >> k >> w >> h;
    string s;
    cin >> s;

    int ans = 0;

    map<pii, int> fr;

    debug(s, w, h);
    h *= 2, w *= 2;
    int LR = 0, UD = 0;
    for (int i = 0; i < n; i++) {
        LR += getLR(s[i]);
        UD += getUD(s[i]);
        fr[{(LR % w + w) % w, (UD % h + h) % h}]++;
    }

    debug(fr);
    int curLR = 0, curUD = 0;
    for (int i = 0; i < k; i++) {
        debug(i, curLR, curUD);
        ans += fr[{(w - curLR) % w, (h - curUD) % h}];
        curLR += LR;
        curUD += UD;
        curLR = (curLR % w + w) % w;
        curUD = (curUD % h + h) % h;
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
