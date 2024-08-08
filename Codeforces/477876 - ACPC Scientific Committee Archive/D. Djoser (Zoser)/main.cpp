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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

int a, b, c, d;

inline int f(int x) {
    return a * x * x * x + b * x * x + c * x + d;
}

void solve() {
    cin >> a >> b >> c >> d;

    assert(abs(a) <= 3e4);
    assert(abs(b) <= 3e4);
    assert(abs(c) <= 3e4);
    assert(abs(d) <= 3e4);

    for (int x = -3e4; x <= 3e4; x++) {
        if (f(x) == 0) {
            cout << "Yes\n";
            cout << x << '\n';
            return;
        }
    }

    cout << "No\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
