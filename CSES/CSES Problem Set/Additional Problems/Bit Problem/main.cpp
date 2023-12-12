// ﷽
// https://cses.fi/problemset/task/1654

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

const int M = 20;
int sub[1 << M], sup[1 << M];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sub[a[i]]++;
        sup[a[i]]++;
    }

    for (int i = 0; i < M; i++) {
        for (int mask = 0; mask < 1 << M; mask++) {
            if (mask >> i & 1) {
                sup[mask ^ (1 << i)] += sup[mask];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int mask = (1 << M) - 1; mask >= 0; mask--) {
            if (mask >> i & 1 ^ 1) {
                sub[mask ^ (1 << i)] += sub[mask];
            }
        }
    }

    debug(a);

    for (int mask = 0; mask < 1 << 4; mask++) {
        debug_bits(mask, 4, 4);
        debug(sup[mask], sub[mask]);
    }

    for (int i = 0; i < n; i++) {
        cout << sub[a[i]] << " " << sup[a[i]] << " " << (n - sub[(1 << M) - 1 - a[i]]) << endl;
    }

    return 0;
}
