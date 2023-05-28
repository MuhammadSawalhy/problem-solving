// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

vector<int> mults;
map<int, bool> done[11];

void calc(int i, int mul) {
    if (done[i][mul]) return;
    done[i][mul] = true;
    if (i == 10) {
        mults.push_back(mul);
        return;
    }
    for (int d = 1; d <= 9; d++) {
        if (mul * d <= 1e9)
            calc(i + 1, mul * d);
    }
}

int m(int x) {
    int r = 1;
    while (x) {
        r *= x % 10;
        x /= 10;
    }
    return r;
}

void solve() {
    int a;
    cin >> a;
    long long ans = 1e18;

    for (auto mul: mults) {
        int x1 = (-mul + sqrtl(mul * mul + 4 * a)) / 2;
        int x2 = (-mul - sqrtl(mul * mul + 4 * a)) / 2;
        int x = x1;
        if (x > 0 && m(x) == mul && x * x + mul * x - a == 0) {
            ans = min(ans, x);
        }
        x = x2;
        if (x > 0 && m(x) == mul && x * x + mul * x - a == 0) {
            ans = min(ans, x);
        }
    }

    if (ans == 1e18)
        ans = -1;
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    mults.push_back(0);
    calc(0, 1);
    debug(mults.size());

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
