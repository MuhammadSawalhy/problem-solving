// ﷽
// https://codeforces.com/contest/1647/problem/D

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

int prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return i;
    }
    return -1;
}

map<int, int> prime_facts(int x) {
    map<int, int> res;
    for (int i = 2; i * i <= x; i++) {
        int r = 0;
        while (x % i == 0) {
            r++;
            x /= i;
        }
        if (r) res[i] = r;
    }
    return res;
}

void solve() {
    int x, d;
    cin >> x >> d;
    int cnt = 0;
    while (x % d == 0) {
        ++cnt;
        x /= d;
    }
    if (cnt == 1) {
        cout << "NO\n";
        return;
    }
    if (prime(x) != -1) {
        cout << "YES\n";
        return;
    }
    auto f = prime_facts(d);
    if (prime(d) != -1)
        if (cnt > 3 || cnt == 3 && (f.size() > 1 || 1LL * x * f.begin()->first % d != 0)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
}
