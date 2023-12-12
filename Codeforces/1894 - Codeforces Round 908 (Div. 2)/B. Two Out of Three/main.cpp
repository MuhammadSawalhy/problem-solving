// ﷽
// https://codeforces.com/contest/1894/problem/B

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> fr;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        fr[a[i]]++;
    }

    vector<int> target;
    for (auto [x, f]: fr) {
        if (f > 1) target.push_back(x);
    }

    if (target.size() <= 1) {
        cout << -1 << endl;
        return;
    }

    int b[n];

    map<int, bool> seen;
    for (int i = 0; i < n; i++) {
        if (a[i] == target[0]) {
            if (seen[a[i]]) {
                b[i] = 2;
            } else {
                b[i] = 1;
                seen[a[i]] = true;
            }
        } else if (a[i] == target[1]) {
            if (seen[a[i]]) {
                b[i] = 3;
            } else {
                b[i] = 1;
                seen[a[i]] = true;
            }
        } else {
            b[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
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
