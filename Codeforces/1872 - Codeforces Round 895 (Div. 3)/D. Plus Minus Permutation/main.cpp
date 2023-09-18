// ﷽
// https://codeforces.com/contest/1872/problem/D
// Codeforces -> Codeforces Round 895 (Div. 3) -> D. Plus Minus Permutation

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
    int n, x, y;
    cin >> n >> x >> y;

    int X = n / x - n / (lcm(x, y)), Y = n / y - n / (lcm(x, y));
    debug(X, Y);

    int xsum = 0, ysum = 0;
    xsum += n * (n + 1) / 2 - (n - X + 1) * (n - X) / 2;
    ysum += Y * (Y + 1) / 2;
    cout << xsum - ysum << endl;

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
