// ﷽
// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    set<int> s;
    ll sum = 0;
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n - 1; i++) cin >> a[i], s.insert(a[i]), sum += a[i];

    for (int i = 1; i <= n; i++) {
        if (!s.count(i)) {
            cout << abs((sum - i * (n - 1)) / (n - 1)) << endl;
            break;
        }
    }

    return 0;
}
