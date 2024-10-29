// ﷽
// https://codeforces.com/contest/2035/problem/C

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int i = 1; i < 11; i++) {
        debug(i);
        vi val(i);
        iota(all(val), 1);
        vvi perms;
        int mx = 0;
        do {
            int k = 0;
            for (int j = 0; j < i; j++) {
                if ((j + 1) & 1) {
                    k &= val[j];
                } else {
                    k |= val[j];
                }
            }

            if (k > mx) perms = {val}, mx = k;
            else if (k == mx) perms.push_back(val);
        } while (next_permutation(all(val)));
        debug(mx);
        for (int i = 0; i < min(sz(perms), 10ll); i++) debug(perms[i]);
    }

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
