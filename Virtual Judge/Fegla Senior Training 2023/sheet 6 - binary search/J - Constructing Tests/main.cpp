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

void solve() {
    int x;
    cin >> x;

    if (x == 0)
        return cout << "1 1\n", void();

    for (ll n = sqrt(x); n * n <= 3LL * x; n++) {
        ll zeros = n * n - x;
        if (zeros <= 0) continue;
        ll sq = sqrt(zeros);
        // to handle any precision error
        while (sq * sq > zeros) sq--;
        while (sq * sq < zeros) sq++;
        if (sq * sq != zeros || n * n - (n / (n / sq)) * (n / (n / sq)) != x) continue;
        cout << n << ' ' << n / sq << '\n';
        return;
    }

    cout << "-1\n";
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
