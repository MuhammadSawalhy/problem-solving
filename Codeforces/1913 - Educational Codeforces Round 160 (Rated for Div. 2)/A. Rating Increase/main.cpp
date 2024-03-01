// ﷽
// https://codeforces.com/contest/1913/problem/A

#include <bits/stdc++.h>
#include <cstddef>
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
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') continue;
        int a = stoi(s.substr(0, i));
        int b = stoi(s.substr(i, n));
        if (a < b) {
            cout << a << ' ' << b << endl;
            return;
        }
    }
    cout << -1 << endl;
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
