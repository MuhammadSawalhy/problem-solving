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

string s;
set<char> ch;

int solve(char c) {
    if (!ch.count(c)) { return 1e9; }
    int n = s.size();
    int mx = 0;

    int i = 0, j = 0;
    while (i < n) {
        while (j < n && s[j] != c) j++;
        mx = max(mx, j - i);
        j++;
        i = j;
    }

    int op = 0;
    
    while (mx > 0) {
        mx -= (mx + 1) / 2;
        op++;
    }

    return op;
}

void solve() {
    cin >> s;
    ch.clear();
    for (auto c: s)
        ch.insert(c);

    int ans = 1e9;
    for (char c = 'a'; c <= 'z'; c++)
        ans = min(ans, solve(c));

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
