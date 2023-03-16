// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <utility>
#include <vector>

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

bool can(ll n, ll b) {
    if (n == 0) return true;
    if (n % b == 0 || (n - 1) % b == 0)
        return can(n / b, b);
    return false;
}

__int128 calc(__int128 b, ll mask) {
    __int128 res = 0;
    __int128 p = 1;
    while (mask) {
        if (mask & 1)
            res += p;
        mask >>= 1;
        p *= b;
        if (res > 1e18)
            return res;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    set<ll> bases;

    for (int i = 0; i < 1 << 9; i++) {
        ll s = 2, e = 1e18;
        while (e - s > 1) {
            ll mid = (s + e) / 2;
            if (calc(mid, i) >= n) {
                e = mid;
            } else {
                s = mid;
            }
        }

        if (can(n, e)) {
            bases.insert(e);
        }
    }

    for (int i = 2; i <= 1000; i++) {
        if (can(n, i)) bases.insert(i);
    }

    cout << bases.size() << '\n';
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
