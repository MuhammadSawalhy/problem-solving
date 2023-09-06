// ﷽
// https://codeforces.com/contest/1864/problem/C
// Codeforces -> Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2) -> C. Divisor Chain

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

    vector<int> facts;
    for (int i = 1; i * i <= x; i++) {
        if (x % i) continue;
        facts.push_back(x / i);
        facts.push_back(i);
    }

    sort(all(facts));
    facts.erase(unique(all(facts)), facts.end());

    debug(facts);
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
