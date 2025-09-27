#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)


void solve() {
    int mask = 0;
    for (int i = 0; i < 30; i += 2) {
        mask |= (1LL << i);
    }

    cout << 0 << endl;
    int a;
    cin >> a;
    int orig = mask;
    cout << mask << endl;
    int b;
    cin >> b;

    assert(b >= a);
    mask = b - a;

    int x = 0, y = 0;

    for (int i = 0; i < 31; i++) {
        if (mask & (1LL << i)) {
            if (i & 1 ^ 1) {
                x ^= 1 << i;
            }
        } else {
            if (i & 1 ) {
                x ^= 1 << (i - 1);
                y ^= 1 << (i - 1);
            }
        }
    }

    mask = a - x - y;

    for (int i = 0; i < 32; i++) {
        if (mask & (1LL << i)) {
            if (i & 1) {
                x ^= 1 << i;
            } else {
                x ^= 1 << (i - 1);
                y ^= 1 << (i - 1);
            }
        }
    }

    assert(x + y == a);
    assert((x | orig) + (y | orig) == b );
    cout << "!" << endl;
    int m;
    cin >> m;
    cout << (m | x) + (y | m) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
