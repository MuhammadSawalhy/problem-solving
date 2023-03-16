// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>

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
    int n;
    string s;
    cin >> n >> s;

    set<int> st[n];

    int ans = 1;
    for (int i = 2; i < n; i++) {
        ans += s[i] != s[i - 2];
    }

    cout << ans << endl;
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
