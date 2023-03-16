// ﷽
#include <map>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

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
    int a, b, c;
    cin >> a >> b >> c;
    if ((a ^ b) & 1 || (a ^ c) & 1) return cout << -1 << endl, void();
    vector<int> v{a,b,c};
    sort(all(v));
    cout << (v[1] - v[0]) + ((v[2] - v[1]) / 2) << endl;
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
