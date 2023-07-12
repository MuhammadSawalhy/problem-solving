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
    ll b[n];
    set<int> B;
    vector<vector<int>> withb(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        withb[b[i]].push_back(i + 1);
        B.insert(b[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] > i + 1) {
            k = max(i + 1, k);
        }
    }


    cout << k << '\n';

    vector<int> a;
    int next =  B.count(0) ? 0 : n + 1;
    while (a.size() < n) {
        int y;
        for (auto x : withb[next]) {
            if (B.count(x)) {
                y = x;
            } else {
                a.push_back(x);
            }
        }
        if (a.size() < n)
            a.push_back(y);
        next = y;
    }

    for (auto i : a)
        cout << i << ' ';
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
