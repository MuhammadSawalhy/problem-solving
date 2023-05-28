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
    vector<int> ind(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }

    int x;
    if (ind[n] == 0) {
        x = n - 1;
    } else {
        x = n;
    }

    int j = ind[x];
    int i = ind[x] - (ind[x] < n - 1);
    while (i > 0 && a[i - 1] > a[0]) {
        i--;
    }

    vector<int> b, c, d;
    b = vector<int>(a.begin(), a.begin() + i);
    c = vector<int>(a.begin() + i, a.begin() + j);
    reverse(all(c));
    d = vector<int>(a.begin() + j, a.end());

    a.clear();
    for (auto i: d)
        a.push_back(i);
    for (auto i: c)
        a.push_back(i);
    for (auto i: b)
        a.push_back(i);
    for (auto i: a)
        cout << i << ' ';
    cout << '\n';
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
