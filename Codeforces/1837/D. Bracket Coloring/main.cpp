// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int n;
string s;

void reverseit() {
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') s[i] = ')';
        else s[i] = '(';
    }
}

void solve() {
    cin >> n;
    cin >> s;

    int value = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            value++;
        } else {
            value--;
        }
    }

    if (value != 0 || n & 1) {
        cout << -1 << '\n';
        return;
    }

    if (s[0] == ')') reverseit();

    int cnt = 1;
    int cur = 1;
    vector<int> colors(n);
    value = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (value == 0) {
                cur = 1;
            }
            value++;
        } else {
            if (value == 0) {
                cnt = 2;
                cur = 2;
            }
            value--;
        }
        colors[i] = cur;
    }


    cout << cnt << '\n';
    for (auto c: colors)
        cout << c << ' ';
    cout << '\n';
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
