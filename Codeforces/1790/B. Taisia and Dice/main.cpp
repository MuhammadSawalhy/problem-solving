// ﷽
#include <bits/stdc++.h>

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

void solve() {
    int n, s, r;
    cin >> n >> s >> r;

    int m = s - r;
    vector<int> d{m};

    debug(n);
    while (r - m > n - d.size() - 1 && r - m > 0) {
        debug(r);
        r -= m;
        d.push_back(m);
    }

    while (d.size() < n - 1) {
        r -= 1;
        d.push_back(1);
    }

    d.push_back(r);

    for (int j = 0; j < d.size(); j++)
        cout << d[j] << " ";
    cout << endl;
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
