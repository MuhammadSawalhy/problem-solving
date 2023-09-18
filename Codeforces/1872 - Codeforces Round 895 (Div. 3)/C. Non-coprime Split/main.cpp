// ﷽
// https://codeforces.com/contest/1872/problem/C
// Codeforces -> Codeforces Round 895 (Div. 3) -> C. Non-coprime Split

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
#define all(v) v.begin(), v.end()

void solve() {
    int l, r;
    cin >> l >> r;

    if (l == r && r & 1) {
        int div = -1;

        for (int i = 2; i * i <= l; i++) {
            if (l % i == 0) {
                div = i;
                break;
            }
        }

        if (div == -1)
            cout << -1 << endl;
        else
            cout << div << ' ' << l - div << endl;
        return;
    }

    while (l & 1 || l == 2) {
        l++;
    }

    if (l > r)
        cout << -1 << endl;
    else
        cout << 2 << ' ' << l - 2 << endl;
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
