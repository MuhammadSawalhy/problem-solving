// ﷽
// https://codeforces.com/contest/1872/problem/G
// Codeforces -> Codeforces Round 895 (Div. 3) -> G. Replace With Product

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    int a[n];

    vector<int> ps(n + 1);
    vector<pair<int, int>> prods{{1, 0}};
    bool large = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
        if (a[i] != 1) {
            large |= (1LL << 60) / prods.back().first < a[i];
            if (!large) prods.push_back({prods.back().first * a[i], i + 1});
        }
    }

    if (!large) {
        int mx = ps[n], l = 1, r = 1;

        int m = prods.size();
        for (int i = 1; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int cur = ps[n] - (ps[prods[j].second] - ps[prods[i].second - 1]) + prods[j].first / prods[i - 1].first;
                if (cur > mx) {
                    mx = cur;
                    l = prods[i].second;
                    r = prods[j].second;
                }
            }
        }

        cout << l << ' ' << r << endl;
        return;
    }

    int i = 0, j = n - 1;
    while (a[i] == 1) i++;
    while (a[j] == 1) j--;
    cout << i + 1 << ' ' << j + 1 << endl;
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
