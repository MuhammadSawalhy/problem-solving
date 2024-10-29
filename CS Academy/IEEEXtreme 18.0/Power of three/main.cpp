// ﷽
// https://csacademy.com/ieeextreme18/task/power-of-three/

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

constexpr int H = 3;
typedef array<long long, H> val;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        998244353,
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

void solve() {
    string n;
    cin >> n;

    if (n == "1") {
        cout << 0 << endl;
        return;
    }

    val x = getval(1);
    val y = getval(1);
    val h = getval(0);

    reverse(all(n));
    for (int i = 0; i < sz(n); i++) {
        h = h + (y * getval(n[i] - '0'));
        y = y * getval(10);
    }

    debug(h);

    for (int i = 1; i < 3e7; i++) {
        x = x * getval(3);
        if (x == h) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
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
