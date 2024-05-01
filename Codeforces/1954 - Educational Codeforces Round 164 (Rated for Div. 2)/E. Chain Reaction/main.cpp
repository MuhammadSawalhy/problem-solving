// ﷽
// https://codeforces.com/contest/1954/problem/E

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 100005;
int a[N], n, mx;

template<typename T, typename CMP = const T &(*) (const T &, const T &)>
class SparseTable {
public:
    int n;
    CMP func;
    vector<vector<T>> sp;

    static const T &merge(const T &l, const T &r) {
        return min(l, r);
    }

    void build(const vector<T> &a, const CMP &f = merge) {
        func = f, n = a.size();
        int max_log = 32 - __builtin_clz(n);
        sp.resize(max_log), sp[0] = a;
        for (int j = 1; j < max_log; ++j) {
            sp[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); ++i)
                sp[j][i] = func(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
        }
    }

    T query(int l, int r) const {
        int lg = 32 - __builtin_clz(r - l + 1) - 1;
        return func(sp[lg][l], sp[lg][r - (1 << lg) + 1]);
    }
};

void change_points(int x, vector<int> &v) {
    for (int i = 1; i <= x; i = x / (x / i) + 1)
        v.push_back(i);
    v.push_back(x + 1);
}

ll pre[N];
void add(int l, int r, int x) {
    pre[l] += x;
    pre[r + 1] -= x;
}

SparseTable<pair<int, int>> sp;
void solve(int l, int r, int lst) {
    if (l > r) return;
    auto mn = sp.query(l, r);
    int md = mn.second;
    solve(l, md - 1, a[md]);
    solve(md + 1, r, a[md]);

    vector<int> v;
    change_points(a[md], v);
    for (int i = 0; i + 1 < v.size(); i++) {
        int L = v[i], R = v[i + 1] - 1;
        add(L, R, (a[md] / L));
    }

    v.clear();
    change_points(lst, v);
    for (int i = 0; i + 1 < v.size(); i++) {
        int L = v[i], R = v[i + 1] - 1;

        // floor(a[md], x_i) == floor(a[md], x_j) for and L <= x_i, x_j <= R
        // floor(lst, x_i) == floor(lst, x_j) for and L <= x_i, x_j <= R
        // but we need change points of ceil division,so we can subtract 1 from all item in a

        add(L, R, -(lst / L));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--, vals[i] = {a[i], i};
    sp.build(vals);
    mx = (*max_element(a, a + n)) + 1;
    solve(0, n - 1, 0);
    pre[1] += 1;
    for (int i = 2; i <= mx; i++) pre[i] += pre[i - 1];
    for (int i = 1; i <= mx; i++) cout << pre[i] << " ";

    return 0;
}
