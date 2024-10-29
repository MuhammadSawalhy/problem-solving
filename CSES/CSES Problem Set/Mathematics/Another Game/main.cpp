// ﷽
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    cin >> n;
    int sm = 0;

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        sm |= a;
    }

    if (sm & 1) cout << "first\n";
    else cout << "second\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // const int N = 10;
    // int nim[N][N][N];
    // nim[0][0][0] = 0;
    //
    // for (int t = 0; t < N; t++) {
    //     for (int s = 0; s < N; s++) {
    //         for (int f = 0; f < N; f++) {
    //             if (t + s + f == 0) continue;
    //             vi g;
    //             for (int tt = t; tt >= max(0ll, t - 1); tt--) {
    //                 for (int ss = s; ss >= max(0ll, s - 1); ss--) {
    //                     for (int ff = f; ff >= max(0ll, f - 1); ff--) {
    //                         if (ff + tt + ss == f + t + s) continue;
    //                         g.emplace_back(nim[ff][ss][tt]);
    //                     }
    //                 }
    //             }
    //
    //             sort(all(g));
    //             g.erase(unique(all(g)), g.end());
    //             int mex = 0;
    //             while (mex < (int) g.size() && g[mex] == mex) {
    //                 mex++;
    //             }
    //             nim[f][s][t] = mex;
    //         }
    //     }
    // }

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
