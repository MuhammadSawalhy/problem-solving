// ﷽
// https://cses.fi/problemset/task/2214

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
    void update(T v) { val += v; }
    T query() { return val; }
};

template<class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
    BIT<T, Ns...> bit[N + 1];
    template<typename... Args>
    void update(int pos, Args... args) {
        for (pos++; pos <= N; pos += (pos & -pos)) bit[pos].update(args...);
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

const int N = 1e6 + 1;
BIT<int, N> bit;

int getRealPos(int pos) {
    int realpos = -1;
    for (int i = 20; i >= 0; i--) {
        if (realpos + (1 << i) < N && bit.sum(realpos + (1 << i)) < pos + 1)
            realpos += 1 << i;
    }
    return realpos + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int ans[n];

    for (int i = 0; i < n; i++) {
        bit.update(i, 1);
    }

    for (int i = 0; i < n; i++) {
        int cnt = n - i;
        int pos = min(cnt - 1, k);
        k -= pos;
        int realpos = getRealPos(pos);
        bit.update(realpos, -1);
        ans[realpos] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
