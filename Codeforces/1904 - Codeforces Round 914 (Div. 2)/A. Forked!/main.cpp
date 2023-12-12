// ﷽
// https://codeforces.com/contest/1904/problem/0

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
    int a, b;
    int qx, qy;
    int kx, ky;
    cin >> a >> b;
    cin >> qx >> qy;
    cin >> kx >> ky;
    set<pair<int, int>> k, q;
    for (int A: {a, -a}) {
        for (int B: {b, -b}) {
            k.insert({kx + A, ky + B});
            q.insert({qx + A, qy + B});
        }
    }
    for (int A: {a, -a}) {
        for (int B: {b, -b}) {
            k.insert({kx + B, ky + A});
            q.insert({qx + B, qy + A});
        }
    }

    int ans = 0;
    for (auto x: k) {
        ans += q.count(x);
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
