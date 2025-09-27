#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


// returns (x,y) such that:
// a * x + b * y = gcd(a, b)
// b * x + (a%b) * y       = gcd(a,b)
// b * x + (a-(a/b)*b) * y = gcd(a,b)
// a * y + b * (x-(a/b)*y) = gcd(a,b)
// x2 = y1, y2 = x1 - (a/b)*y1
pair<long long, long long> exgcd(long long a, long long b) {
    if (!b) return {1, 0};
    pair<long long, long long> p = exgcd(b, a % b);
    return {p.second, p.first - (a / b) * p.second};
}

void solve() {
    int a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    int g = gcd(a, b);

    if (a == 0 && b == 0) {
        if (c == 0) {
            cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
            return;
        } else {
            cout << 0 << endl;
            return;
        }
    }

    if (c % g) {
        cout << 0 << endl;
        return;
    }


    auto [x, y] = exgcd(a, b);
    debug(g, a * x + b * y);
    if (a * x + b * y != g) {
        x *= -1, y *= -1;
    }

    assert(a * x + b * y == g);

    x *= -c / g;
    y *= -c / g;
    assert(a * x + b * y + c == 0);

    debug(x, y);

    // delta_x * a = - delta_y * b
    // delta_x / delta_y = - b / a

    int delta_x = b / g;
    int delta_y = -a / g;
    debug(delta_x, delta_y);

    if (delta_x < 0) {
        int shift = (x2 - x);
        delta_x *= -1;
        x = shift + x1;
    }

    if (delta_y < 0) {
        int shift = (y2 - y);
        delta_y *= -1;
        y = shift + y1;
    }

    debug(delta_x, delta_y, x, y);

    if (x < x1 && delta_x) {
        int k = (x1 - x + delta_x - 1) / delta_x;
        x += k * delta_x;
        y += k * delta_y;
    }

    if (x > x1 && delta_x) {
        int k = (x - x1) / delta_x;
        x -= k * delta_x;
        y -= k * delta_y;
    }

    debug(x, y);

    if (y < y1 && delta_y) {
        int k = (y1 - y + delta_y - 1) / delta_y;
        x += k * delta_x;
        y += k * delta_y;
    }

    if ((x < x1 || x > x2) && a || (y < y1 || y > y2) && b) {
        cout << 0 << endl;
        return;
    }

    debug(x, y);

    if (delta_x == 0) {
        cout << (y2 - y1 + 1) << endl;
    } else if (delta_y == 0) {
        cout << (x2 - x1 + 1) << endl;
    } else {
        int ans1 = (x2 - x) / delta_x;
        int ans2 = (y2 - y) / delta_y;
        cout << min(ans1, ans2) + 1 << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
