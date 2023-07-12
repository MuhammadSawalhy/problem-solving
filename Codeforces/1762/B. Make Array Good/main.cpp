// Date: 15-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

ll next_power(int x) {
    return 1LL << (64 - __builtin_clzll(x));
}

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << n << endl;
    vector<pair<int, ll>> ans;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << next_power(a[i]) - a[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
