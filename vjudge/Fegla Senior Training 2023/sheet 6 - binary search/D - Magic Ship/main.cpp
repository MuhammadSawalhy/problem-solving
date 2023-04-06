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

struct WindEffect {
    int x = 0, y = 0;

    WindEffect operator+(const WindEffect &x) {
        WindEffect w = *this;
        w.x += x.x;
        w.y += x.y;
        return w;
    }

    WindEffect operator*(int m) {
        WindEffect w = *this;
        w.x *= m;
        w.y *= m;
        return w;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, x1, y1, x2, y2;
    string wind;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n >> wind;
    WindEffect wef[n + 1];

    for (int i = 0; i < n; i++) {
        WindEffect ef;
        if (wind[i] == 'U')
            ef.y = 1;
        if (wind[i] == 'D')
            ef.y = -1;
        if (wind[i] == 'R')
            ef.x = 1;
        if (wind[i] == 'L')
            ef.x = -1;
        wef[i + 1] = wef[i] + ef;
    }

    auto valid = [&](ll days) -> bool {
        WindEffect ef = wef[n] * (days / n) + wef[days % n];
        return abs(x1 + ef.x - x2) + abs(y1 + ef.y - y2) <= days;
    };

    ll s = -1, e = 1e18, ans = -1;

    while (e - s > 1) {
        int m = (e + s) / 2;
        if (valid(m)) {
            ans = e = m;
        } else {
            s = m;
        }
    }

    cout << ans;

    return 0;
}
