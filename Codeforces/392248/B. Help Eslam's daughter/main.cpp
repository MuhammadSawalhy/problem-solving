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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> ms;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < i + n && (ms.empty() || a[j % n] <= *ms.begin() * 2 && a[j % n] >= (*prev(ms.end()) + 1) / 2)) {
            ms.insert(a[(j++) % n]);
        }
        cout << ms.size() << ' ';
        ms.erase(ms.find(a[i]));
    }
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
