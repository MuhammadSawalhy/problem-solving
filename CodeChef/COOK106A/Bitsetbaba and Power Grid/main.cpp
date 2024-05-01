// ﷽
// https://www.codechef.com/COOK106A/problems/XORCMPNT

#include <algorithm>
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

template<int bits>
struct XORBasisHIGH {
    array<int, bits> basis{};

    void insert(const vector<int> &v) {
        for (auto x: v) insert(x);
    }

    void insert(int x) {
        for (int b = bits - 1; x && b >= 0; b--) {
            if (x >> b & 1 ^ 1) continue;
            if (!basis[b]) basis[b] = x;
            x ^= basis[b];
        }
    }

    int size() {
        int sz = 0;
        for (auto b: basis) sz += !!b;
        return sz;
    }

};

template<int bits>
struct XORBasis {
    array<int, bits> basis{};

    void insert(const vector<int> &v) {
        for (auto x: v) insert(x);
    }

    void insert(int x) {
        for (int b = 0; x && b < bits; b++) {
            if (x >> b & 1 ^ 1) continue;
            if (!basis[b]) basis[b] = x;
            x ^= basis[b];
        }
    }

    int size() {
        int sz = 0;
        for (auto b: basis) sz += !!b;
        return sz;
    }

    int mask(int x) {
        int m = 0;
        for (int b = 0; b < bits; b++) {
            if (x >> b & 1 ^ 1) continue;
            assert(basis[b]);
            x ^= basis[b], m |= 1 << b;
        }
        return m;
    }
};

void solve() {
    int k, m;
    cin >> k >> m;
    XORBasis<31> xb;
    int x[m];
    for (int i = 0; i < m; i++) {
        cin >> x[i], x[i]++;
        xb.insert(x[i]);
    }

    int ans = 1 << k;

    debug(xb.basis);

    for (int i = 0, prev = 0; i < m; i++) {
        auto mask = xb.mask(x[i]);

        ans -= (1 << __popcount(mask)) - (1 << __popcount(mask & prev));
        if ((mask & prev) == 0) {
            ans++;
        }

        mask |= prev;
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
