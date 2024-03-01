// ﷽
// https://codeforces.com/contest/1921/problem/E

#include <bits/stdc++.h>
#include <ios>
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
    int h, w, ax, ay, bx, by;
    cin >> h >> w >> ax >> ay >> bx >> by;
    int dh = bx - ax;
    int dw = abs(ay - by);
    if (dh <= 0 || dw > dh) {
        cout << "Draw\n";
        return;
    }

    if (dh & 1) {
        bool win = dw <= 1;
        // minize dw
        // if dw <= 1, it will be that forever
        // how to get it to 1?
        if (by > ay) {
            dh -= (w - by) * 2;
        } else {
            dh -= (by - 1) * 2;
        }
        win |= dh + 1 >= dw * 2;
        cout << (win ? "Alice" : "Draw") << endl;
    } else {
        bool win = dw <= 0;
        if (ay > by) {
            dh -= (w - ay) * 2;
        } else {
            dh -= (ay - 1) * 2;
        }
        win |= dh >= dw * 2;
        cout << (win ? "Bob" : "Draw") << endl;
    }
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
