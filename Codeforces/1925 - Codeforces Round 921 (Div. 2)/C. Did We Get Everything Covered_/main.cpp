// ﷽
// https://codeforces.com/contest/1925/problem/C

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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    set<char> ch;
    int cnt = 0;
    string t;
    for (int i = 0; i < m; i++) {
        if (s[i] - 'a' < k)
            ch.insert(s[i]);
        if (ch.size() == k) {
            t += s[i];
            ch.clear();
            cnt++;
        }
    }

    if (cnt >= n) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    for (int i = 0; i < k; i++) {
        if (!ch.count('a' + i)) {
            t += 'a' + i;
            break;
        }
    }
    while (t.size() < n) t += 'a';

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
