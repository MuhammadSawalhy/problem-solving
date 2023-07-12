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
    int start = false, end = false, one = false;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        start |= l == k;
        end |= r == k;
    }

    cout << (start && end ? "YES" : "NO") << endl;
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
