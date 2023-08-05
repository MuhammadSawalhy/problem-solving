// ﷽
// https://cses.fi/problemset/task/2416
// CSES -> CSES Problem Set -> Increasing Array Queries

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
            cin >> a[i];
    }

    vector<int> ans(q);
    vector<array<int, 3>> queries;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        queries.emplace_back(a, b, i);
    }

    sort(all(queries));

    int cur = 0;
    for (int i = 0; i < n; i++) {
        
    }

    return 0;
}
