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
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int invalid = 0;
    for (int i = 0; i < n - 1; i++)
        invalid += a[i] == a[i + 1];
    for (int i = 0; i < m - 1; i++)
        invalid += b[i] == b[i + 1];
    
    debug(invalid);

    cout << (invalid == 0 || invalid == 1 && a.back() != b.back() ? "YES" : "NO") << endl;
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
