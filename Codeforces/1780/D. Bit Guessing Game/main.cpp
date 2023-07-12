// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int ask(int x) {
    cerr << "asking: " << x << endl;
    int ans;
    cout << "- " << x << endl;
    cin >> ans;
    assert(~ans);
    return ans;
}

void ans(int n) {
    cerr << "answering: " << n << endl;
    cout << "! " << n << endl << endl;
}

void solve() {
    int n = 0, base = 0, a = 1, last = 1;

    cin >> a, last = a;
    base = 0;
    while (last > 0) {
        int x = ((1 << base) - 1) + 1;
        a = ask(x);
        n += x;
        int delta = a - last + base;
        base = delta + 1;
        if (base == a) {
            n += (1 << base) - 1;
            break;
        }
        last = a;
    }

    ans(n);
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
