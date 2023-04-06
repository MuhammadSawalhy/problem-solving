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

int n;
set<int> primes;
vector<int> ans;

void solve(int mask, int prev) {
    if (mask == ((1 << n) - 1) << 1) {
        if (!primes.count(prev + 1)) return;
        cout << 1;
        for (auto i: ans)
            cout << " " << i;
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if ((mask >> i & 1 ^ 1) && primes.count(i + prev)) {
            ans.push_back(i);
            solve(mask | (1 << i), i);
            ans.pop_back();
        }
    }
}

void solve() {
    ans.clear();
    solve(2, 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 2; i < 40; i++) {
        bool p = true;
        for (int j = 2; j < i; j++)
            p &= i % j != 0;
        if (p)
            primes.insert(i);
    }

    int i = 0;
    while (cin >> n)
        (i && (cout << '\n')), cout << "Case " << ++i << ":\n", solve();

    return 0;
}
