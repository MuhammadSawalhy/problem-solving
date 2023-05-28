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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> fr;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    vector<pair<int, int>> v;

    for (auto [x, f]: fr)
        v.push_back({f, x});

    sort(all(v));

    debug(v);

    int s = 0;
    int i = 0;
    while (i < v.size() && s + v[i].first <= k) {
        s += v[i++].first;
    }

    debug(i);
    cout << v.size() - i;

    return 0;
}
