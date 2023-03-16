// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
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

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (((n & 1) || (k & 1)) && k != n) {
        return cout << "YES" << endl, void();
    }

    vector<int> tofix;
    ll sum = 0;

    for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
        if (a[i] == a[j]) continue;
        if (k == n) return cout << "NO" << endl, void();
        tofix.push_back(abs(a[i] - a[j]));
        sum += tofix.back();
    }

    if (sum & 1) {
        return cout << "NO" << endl, void();
    }

    cout << "YES" << endl;
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
