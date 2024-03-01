// ﷽
// https://codeforces.com/contest/1905/problem/C

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


typedef pair<int, int> T;
struct Max {
    T value;
    Max(T value = {-1e9, 1e9}) : value(value) {}
    Max &operator+=(const Max &other) {
        if (other.value.first > value.first) {
            value = other.value;
        } else if (other.value.first == value.first && other.value.second < value.second) {
            value = other.value;
        }
        return *this;
    }
    Max operator+(const Max &other) const { return Max(max(value, other.value)); }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct Segtree {
    int n;
    vector<T> tree;

    Segtree() = default;
    Segtree(int n) : n(n) {
        tree.resize(n * 2);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    auto query(int l, int r) {
        T res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res.value;
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ops = 0;
    while (ops < 100) {
        if (is_sorted(all(s))) break;

        Segtree<Max> sg(n);

        for (int i = 0; i < n; i++) {
            sg.update(i, Max({s[i] - 'a', i}));
        }

        int cnt = 0;
        int i = 0;
        ops++;

        vector<bool> taken(n);
        string a;
        while (i < n) {
            auto x = sg.query(i, n - 1);
            cnt++;
            taken[x.second] = true;
            i = x.second + 1;
            a += s[i - 1];
        }

        string b;
        b += a.back();
        for (int i = 0; i < n - 1; i++) b += a[i];
        a = b;

        string t;
        for (int i = 0, j = 0; i < n; i++) {
            if (!taken[i]) t += s[i];
            else t += a[j++];
        }

        s = t;
    }
    if (ops == 100) cout << -1 << endl;
    else cout << ops << endl;
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
