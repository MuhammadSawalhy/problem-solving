// ﷽
// https://codeforces.com/contest/1858/problem/E1

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

template<typename T = long long>
struct Sum {
    T value;
    Sum(T value = 0) : value(value) {}
    Sum &operator+=(const Sum &other) { return value += other.value, *this; }
    Sum operator+(const Sum &other) const { return value + other.value; }
};

template<typename T = long long>
struct Max {
    T value;
    Max(T value = numeric_limits<T>::min() / 2) : value(value) {}
    Max &operator+=(const Max &other) { return value = max(value, other.value), *this; }
    Max operator+(const Max &other) const { return Max(max(value, other.value)); }
};

template<typename T = long long>
struct Min {
    T value;
    Min(T value = numeric_limits<T>::max() / 2) : value(value) {}
    Min &operator+=(const Min &other) { return value = min(value, other.value), *this; }
    Min operator+(const Min &other) const { return Min(min(value, other.value)); }
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

struct Action {
    enum Type { Add,
                Remove } type;

    union {
        int k;
        int y;
    };
};

vector<set<int>> ind(1e6 + 6, set<int>{(int) 1e6 + 1});
vector<int> a(1e6 + 6);
Segtree<Sum<int>> sg(1e6 + 6);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int q;
    cin >> q;
    int r = 0;

    vector<Action> actions;

    while (q--) {
        char t;
        cin >> t;
        if (t == '?') {
            debug("=>", r);
            if (r == 0) {
                cout << 0 << endl;
                continue;
            }
            cout << sg.query(0, r - 1) << endl;
        } else if (t == '-') {
            int k;
            cin >> k;
            actions.push_back({Action::Remove, k});
            r -= k;
        } else if (t == '+') {
            int x;
            cin >> x;
            int y = a[r];
            actions.push_back({Action::Add, y});
            sg.update(*ind[x].begin(), 0);
            sg.update(*ind[y].begin(), 0);
            ind[y].erase(r);
            ind[x].insert(r);
            sg.update(*ind[x].begin(), 1);
            sg.update(*ind[y].begin(), 1);
            a[r++] = x;
        } else if (t == '!') {
            Action ac = actions.back();
            if (ac.type == Action::Add) {
                r--;
                int x = a[r], y = ac.y;
                sg.update(*ind[x].begin(), 0);
                sg.update(*ind[y].begin(), 0);
                ind[x].erase(r);
                ind[y].insert(r);
                sg.update(*ind[x].begin(), 1);
                sg.update(*ind[y].begin(), 1);
                a[r] = y;
            } else if (ac.type == Action::Remove) {
                r += ac.k;
            }
            actions.pop_back();
        } else {
            assert(false);
        }

        debug(t);
    }

    return 0;
}
