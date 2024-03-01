// ﷽
// https://codeforces.com/contest/1922/problem/D

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

const int N = 3e5 + 1;
BIT<int, N> bit;

int n;
int getRealPos(int pos) {
    if (pos < 0 || pos >= n) return -1;
    int realpos = -1;
    for (int i = 20; i >= 0; i--) {
        if (realpos + (1 << i) < N && bit.sum(realpos + (1 << i)) < pos + 1)
            realpos += 1 << i;
    }
    return realpos + 1;
}

void solve() {
    cin >> n;
    vector<int> a(n), d(n);
    vector<bool> done(n);
    vector<int> cur, nxt;

    for (int i = 0; i < n; i++) {
        bit.update(i, 1);
        cin >> a[i];
    }

    auto is_removable = [&](int i) -> bool {
        auto x = getRealPos(i + 1);
        auto y = getRealPos(i - 1);
        long long around = 0;
        if (x > i && x < n) {
            around += a[x];
        }
        if (y >= 0 && y < i) {
            around += a[y];
        }
        return around > d[i];
    };

    cur.reserve(n);
    nxt.reserve(n);

    // valid to insert
    auto valid = [&](int i) -> bool {
        if (i < 0 || i >= n) return false;
        return !done[i];
    };

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (i > 0 && is_removable(i - 1))
            cur.push_back(i - 1), done[i - 1] = true;
    }

    if (is_removable(n - 1))
        cur.push_back(n - 1), done[n - 1] = true;

    for (int i = 0; i < n; i++) {
        cout << cur.size() << ' ';
        while (cur.size()) {
            auto ind = cur.back();
            auto x = getRealPos(ind + 1), p = getRealPos(ind - 1);
            if (valid(x))
                nxt.push_back(x);
            if (valid(p))
                nxt.push_back(p);
            bit.update(ind, -1);
            cur.pop_back();
        }

        while (nxt.size()) {
            if (done[nxt.back()]) continue;
            if (is_removable(nxt.back()))
                cur.push_back(nxt.back()), done[nxt.back()] = true;
            nxt.pop_back();
        }
    }

    for (int i = 0; i <= n; i++) {
        bit.bit[i].val = 0;
    }

    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
