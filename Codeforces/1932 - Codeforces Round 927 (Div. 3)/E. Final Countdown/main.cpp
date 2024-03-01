// ﷽
// https://codeforces.com/contest/1932/problem/E

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += s[i] - '0';

    string t(n * 2, '0');

    reverse(all(s));
    int toadd = 0;
    for (int i = 0; i < n; i++) {
        toadd += sum;

        t[i] = toadd % 10 + '0';
        toadd /= 10;

        sum -= s[i] - '0';
    }

    int i = n;
    while (toadd) {
        t[i++] = toadd % 10 + '0';
        toadd /= 10;
    }

    while (t.back() == '0') t.pop_back();
    reverse(all(t));
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
