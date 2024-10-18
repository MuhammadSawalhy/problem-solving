// ﷽
// https://cses.fi/problemset/task/2136

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

char in[1 << 24];
struct Scanner {
    char const *o;
    Scanner() : o(in) { load(); }
    void load() { in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; }
    unsigned readInt() {
        unsigned u = 0;
        while (*o && *o <= 32) ++o;
        while (*o >= '0' && *o <= '9')
            u = u * 10 + (*o++ - '0');
        return u;
    }
    unsigned readDigit() {
        while (*o && *o <= 32) ++o;
        if (*o >= '0' && *o <= '9')
            return *o++ - '0';
        assert(false);
    }
} sc;

void solve() {
    int n = sc.readInt(), k = sc.readInt();
    static constexpr int N = 2e5 + 5;
    static int a[N];

    int ans = k;

    vector<int> vals[k + 1];

    for (int i = 0; i < n; i++) {
        a[i] = 0;
        for (int j = 0; j < k; j++) a[i] |= sc.readDigit() << j;
        vals[__builtin_popcount(a[i])].push_back(a[i]);
    }

    for (int l = 0; l <= k; l++) {
        for (int i = 1; i < sz(vals[l]); i++) {
            for (int j = 0; j < i; j++) {
                ans = min(ans, __builtin_popcount(vals[l][i] ^ vals[l][j]));
            }
        }
        for (int r = 0; r < l; r = max(l - ans + 1, r + 1)) {
            for (int i = 0; i < sz(vals[l]); i++) {
                for (int j = 0; j < sz(vals[r]) && l - ans + 1 <= r; j++) {
                    ans = min(ans, __builtin_popcount(vals[l][i] ^ vals[r][j]));
                }
            }
        }
    }

    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
