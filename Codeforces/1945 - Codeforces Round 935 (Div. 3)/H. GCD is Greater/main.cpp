// ﷽
// https://codeforces.com/contest/1945/problem/H

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

template<class T = pair<int, int>>
struct Segtree {
    const int updef = -1;
    const T def = {(1 << 30) - 1, -1};
    int n;
    vector<T> tree;
    vector<int> ups;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, def);
        ups.assign(n << 1, updef);
    }

    inline T merge(const T &a, const T &b) { return min(a, b); }

    inline void push(int i, int L, int R) {
        if (ups[i] != updef) {
            if (i < n) {
                ups[i << 1] &= ups[i];
                ups[i << 1 | 1] &= ups[i];
            }
            tree[i].first &= ups[i];
            ups[i] = updef;
        }
    }

    T query(int l, int r, int i, int L, int R) {
        push(i, L, R);
        if (R < l || r < L) return def;
        if (l <= L && R <= r) return tree[i];
        int mid = (L + R) / 2;
        return merge(
                query(l, r, i << 1, L, mid),
                query(l, r, i << 1 | 1, mid + 1, R));
    }

    void set(int l, int r, const T &up, int i, int L, int R) {
        push(i, L, R);
        if (R < l || r < L) return;
        if (l <= L && R <= r) {
            tree[i] = up;
            return;
        }
        int mid = (L + R) / 2;
        set(l, r, up, i << 1, L, mid);
        set(l, r, up, i << 1 | 1, mid + 1, R);
        tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int l, int r, const int &up, int i, int L, int R) {
        push(i, L, R);
        if (R < l || r < L) return;
        if (l <= L && R <= r) {
            ups[i] += up, push(i, L, R);
            return;
        }
        int mid = (L + R) / 2;
        update(l, r, up, i << 1, L, mid);
        update(l, r, up, i << 1 | 1, mid + 1, R);
        tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
};

const int N = 4e5 + 5, M = 6e6;
vector<int> facts[N];

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];

    int m = 0, mx = -1e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m += facts[a[i]].size();
        maxit(mx, a[i]);
    }

    vector<int> start(mx + 1), end(mx + 1), cur(mx + 1), fr(mx + 1);

    for (int i = 0; i < n; i++) {
        for (auto f: facts[a[i]]) {
            fr[f]++;
        }
    }

    for (int i = 1, sum = 0; i <= mx; i++) {
        cur[i] = start[i] = sum;
        sum += fr[i];
        end[i] = sum - 1;
    }

    Segtree sg(m);
    int g = -1, h = -1, maxval = -1e18;

    for (int i = 0, theand = -1; i < n; i++) {
        // calc ans

        for (auto f: facts[a[i]]) {
            if (f <= maxval) continue;
            auto q = sg.query(start[f], end[f], 1, 0, sg.n - 1);
            bool can = q.second != -1 && q.first + x < f;

            if (can) {
                maxval = f;
                g = a[i];
                h = q.second;
            }
        }

        sg.update(0, sg.n - 1, a[i], 1, 0, sg.n - 1);

        // update sg
        for (auto f: facts[a[i]]) {
            sg.set(cur[f], cur[f], {theand, a[i]}, 1, 0, sg.n - 1);
            cur[f]++;
        }

        theand &= a[i];
    }

    if (g == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << 2 << ' ' << g << ' ' << h << '\n';
    cout << n - 2 << ' ';
    for (int i = 0; i < n; i++) {
        if (a[i] == g) {
            g = -1;
            continue;
        }
        if (a[i] == h) {
            h = -1;
            continue;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            facts[j].push_back(i);
        }
        cnt += facts[i].size();
    }
    debug(cnt);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
