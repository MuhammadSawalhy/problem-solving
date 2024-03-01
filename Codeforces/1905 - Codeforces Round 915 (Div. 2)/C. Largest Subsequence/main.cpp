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
    Segtree<Max> sg(n);

    for (int i = 0; i < n; i++) {
        sg.update(i, Max({s[i] - 'a', i}));
    }

    vector<bool> taken(n);

    int cnt = 0;
    int i = 0;
    while (i < n) {
        auto x = sg.query(i, n - 1);
        cnt++;
        taken[x.second] = true;
        i = x.second + 1;
    }

    string not_taken, ta, na;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) not_taken.push_back(s[i]);
        else ta.push_back(s[i]);
    }

    na = ta;
    sort(all(ta));
    string t;
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (!taken[i]) t += not_taken[j++];
        else t += ta[k++];
    }

    if (is_sorted(all(t))) {
        int i = 1;
        while (i < cnt && na[i - 1] == na[i]) i++;
        cout << cnt - i << endl;
    } else {
        cout << "-1\n";
    }
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
