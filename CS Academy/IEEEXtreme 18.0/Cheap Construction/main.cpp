// ﷽
// https://csacademy.com/ieeextreme18/task/cheap-construction/

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

constexpr int H = 2;
typedef array<long long, H> val;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 998244353,
        // 1000000009,
};

val tmp;

val operator*(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = a[i] * b[i] % M[i];
    return tmp;
}

val operator-(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] - b[i] + M[i]) % M[i];
    return tmp;
}

val operator+(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] + b[i]) % M[i];
    return tmp;
}

val getval(int x) {
    for (int i = 0; i < H; i++) tmp[i] = x % M[i];
    return tmp;
}

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, getval(1));
        for (int i = 0; i < H; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1]);
}

struct Hash {
    vector<val> h;

    Hash(const string &s) : Hash(vector<int>(s.begin(), s.end())) {}

    Hash(const vector<int> &s) {
        vector<val> v;
        for (auto x: s) v.push_back(getval(x));
        *this = Hash(v);
    }

    Hash(const vector<val> &s) : h(s.size() + 1) {
        setB(s.size());
        for (int i = 0; i < (int) s.size(); i++)
            h[i + 1] = h[i] * B[1] + s[i];
    }

    val get(int l, int r) { return h[r + 1] - h[l] * B[r - l + 1]; }
};

void solve() {
    string s;
    cin >> s;

    Hash h(s);

    int n = sz(s);

    vi ans(n + 1, 1e9);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int val = 0;
            int l = j - i + 1;
            auto hh = h.get(i, j);
            int last = -n;
            int mx = -1;
            for (int k = 0; k < n; k++) {
                if (k + l - 1 < n && h.get(k, k + l - 1) == hh) {
                    if (k - last >= l) {
                        val++;
                    }
                    last = k;
                    maxit(mx, k + l - 1);
                } else {
                    val += k > mx;
                }
            }

            debug(i, j, val);
            minit(ans[val], l);
        }
    }

    for (int i = 1; i <= n; i++) cout << (ans[i] == 1e9 ? 0 : ans[i]) << ' ';
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
