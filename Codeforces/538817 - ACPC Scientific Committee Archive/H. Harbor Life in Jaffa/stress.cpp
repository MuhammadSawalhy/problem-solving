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
#define all(v) v.begin(), v.end()

const int bits = 20;

template<int bits = bits>
struct XORBasis {
    array<int, bits> basis{};

    void reset() { basis = array<int, bits>(); }

    void insert(const vector<int> &v) {
        for (auto x: v) insert(x);
    }

    bool insert(int x) {
        for (int b = bits - 1; x && b >= 0; b--) {
            if (x >> b & 1 ^ 1) continue;
            if (!basis[b]) return basis[b] = x, true;
            x ^= basis[b];
        }
        return false;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x, l--, r--;
            for (int i = l; i <= r; i++) {
                a[i] &= x;
            }
        } else if (t == 2) {
            int i, x;
            cin >> i >> x, i--;
            a[i] = x;
        } else {
            int l, r;
            cin >> l >> r, l--, r--;
            XORBasis<20> xb;

            for (int i = l; i <= r; i++)
                xb.insert(a[i]);

            auto basis = xb.basis;

            int mx = 0;
            for (int i = 20 - 1; i >= 0; i--) {
                if (basis[i] && (mx >> i & 1) == 0) {
                    mx ^= basis[i];
                }
            }

            cout << mx << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
