// ﷽
// https://codeforces.com/contest/1868/problem/B2
// Codeforces -> Codeforces Round 896 (Div. 1) -> B2. Candy Party (Hard Version)

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
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n) {
        cout << "No\n";
        return;
    }

    int mean = sum / n;
    vector<int> netdeg(32); // (out deg) - (in deg)
    vector<int> neg(32), pos(32); // for powers of 2
    for (int i = 0; i < n; i++) {
        int diff = a[i] - mean;
        if (diff == 0) continue;

        for (int x = 0; x < 31; x++) {
            for (int y = 0; y < 31; y++) {
                if (diff - (1 << x) + (1 << y) == 0) {
                    netdeg[x]++;
                    netdeg[y]--;
                }
            }
        }

        if (__popcount(abs(diff)) == 1) {
            if (diff < 0) {
                neg[__builtin_ctz(-diff)]++;
            } else {
                pos[__builtin_ctz(diff)]++;
            }
        }
    }

    // out[0] is either a starting point (out[0]) or in between (in[0]+out[1])
    // fix 0 and continue
    for (int i = 0; i < 31; i++) {
        if (neg[i] > 0) {
            cout << "No\n";
            return;
        }

    }
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
