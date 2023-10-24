// ﷽
// https://codeforces.com/contest/1886/problem/B

#include <bits/stdc++.h>
#include <iomanip>
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
int p[2], a[2], b[2];

int dist(int x, int y, int z, int r) {
    return (x - z) * (x - z) + (y - r) * (y - r);
}

void solve() {
    cin >> p[0] >> p[1] >> a[0] >> a[1] >> b[0] >> b[1];

    double s = 0, e = 1e9;

    for (int iter = 100; iter; iter--) {
        double mid = (s + e) / 2;
        bool a0 = dist(0, 0, a[0], a[1]) <= mid * mid;
        bool b0 = dist(0, 0, b[0], b[1]) <= mid * mid;
        bool ap = dist(p[0], p[1], a[0], a[1]) <= mid * mid;
        bool bp = dist(p[0], p[1], b[0], b[1]) <= mid * mid;
        bool intersect = dist(a[0], a[1], b[0], b[1]) <= 4 * mid * mid;
        if (a0 && bp && intersect || b0 && ap && intersect || a0 && ap || b0 && bp)
            e = mid;
        else
            s = mid;
    }

    cout << s << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(10);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
