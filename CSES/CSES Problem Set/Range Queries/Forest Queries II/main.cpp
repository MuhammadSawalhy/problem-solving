// ﷽
// https://cses.fi/problemset/task/1739
// CSES -> CSES Problem Set -> Forest Queries II

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

template<class T, int... Ns>
struct BIT {
    T val = 0;
    void upd(T v) { val += v; }
    T query() { return val; }
};

template<class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
    BIT<T, Ns...> bit[N + 1];
    template<typename... Args>
    void upd(int pos, Args... args) {
        for (pos++; pos <= N; pos += (pos & -pos)) bit[pos].upd(args...);
    }
    template<typename... Args>
    T sum(int r, Args... args) {
        T res = 0;
        for (r++; r; r -= (r & -r)) res += bit[r].query(args...);
        return res;
    }
    template<typename... Args>
    T query(int l, int r, Args... args) {
        return sum(r, args...) - sum(l - 1, args...);
    }
}; // BIT<int,10,10> gives a 2D BIT

void solve() {
    int n, q;
    cin >> n >> q;

    BIT<int, 1000, 1000> bit;

    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') {
                bit.upd(i, j, 1);
            }
        }
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j, i--, j--;
            if (s[i][j] == '*')
                bit.upd(i, j, -1), s[i][j] = '.';
            else
                bit.upd(i, j, +1), s[i][j] = '*';
        } else {
            int i, j, k, l;
            cin >> i >> j, i--, j--;
            cin >> k >> l, k--, l--;
            cout << bit.query(i, k, j, l) << '\n';
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
