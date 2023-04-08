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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

void print(int r, int c) {
    cout << "! " << r << " " << c << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int r, c;
    
    auto x = ask(1, 1);

    if (x == 0) {
        return print(1, 1);
    }

    if (1 + x > n) {
        assert(1 + x <= m);
        auto y = ask(n, 1 + x);
        return print(n - y, 1 + x);
    }

    if (1 + x > m) {
        assert(1 + x <= n);
        auto y = ask(1 + x, m);
        return print(1 + x, m - y);
    }

    int y = ask(x + 1, x + 1);
    if (ask(x + 1, x + 1 - y) == 0) {
        return print(x + 1, x + 1 - y);
    }

    return print(x + 1 - y, x + 1);
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
