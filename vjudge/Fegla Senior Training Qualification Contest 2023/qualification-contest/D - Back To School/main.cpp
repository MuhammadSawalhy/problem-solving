// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>

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

const int N = 1e9;
const int sq = sqrtl(N);

ll divs(ll x) {
    ll ans = 0;

    for (ll i = 1, r; i <= x; i++) {
        r = x / (x / i);
        ans += (x / i) * ((i + r) * (r - i + 1) / 2);
        i = r;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int l, r;
    cin >> l >> r;

    debug(divs(0));
    debug(divs(1));
    debug(divs(2));
    debug(divs(3));

    cout << divs(r) - divs(l - 1) << endl;

    return 0;
}
