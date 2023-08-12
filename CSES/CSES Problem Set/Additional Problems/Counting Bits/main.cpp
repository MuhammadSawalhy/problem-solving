// ﷽
// https://cses.fi/problemset/task/1146
// CSES -> CSES Problem Set -> Counting Bits

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

ll count(ll n) {
    if (n == 0) return 0;
    ll ans = 1;
    ll pow = 2;
    while (pow * 2 - 1 <= n) {
        ans += ans + pow;
        pow *= 2;
        debug(pow, ans);
    }

    return ans + n - pow + 1 + (n >= pow ? count(n - pow) : 0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    cin >> n;
    cout << count(n) << endl;

    return 0;
}
