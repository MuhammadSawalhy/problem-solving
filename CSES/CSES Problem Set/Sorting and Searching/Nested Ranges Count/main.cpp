// ﷽
// 13 جُمادى الآخرة 1444
// Jan 05, 2023
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

template<typename T>
struct segtree {
    int n;
    vector<T> tree;

    segtree(int n) : n(n) {
        tree.assign(n * 2, 0);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    T query(int l, int r) {
        T res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    scanf("%lld", &n);

    // we need to compress these ranges

    array<int, 4> edges[n * 2];
    int e[n * 2];

    int a, b;
    for (int i = 0; i < n * 2; i += 2) {
        scanf("%lld%lld", &a, &b);
        edges[i] = {a, -1, -b, i / 2};
        edges[i + 1] = {b, +1, -a, i / 2};
        e[i] = a;
        e[i + 1] = b;
    }

    sort(e, e + n * 2);
    map<int, int> mp;
    for (int i = 0; i < n * 2; i++) {
        mp[e[i]] = i;
    }

    segtree<ll> rsg(n * 2);
    segtree<ll> lsg(n * 2);

    for (auto &[lr, type, rl, i]: edges) {
        lr = mp[lr];
        rl = -mp[-rl];
        if (type == 1)
            rsg.tree[rsg.n + lr]++;
        else
            lsg.tree[rsg.n + lr]++;
    }

    rsg.build(), lsg.build();

    sort(edges, edges + n * 2);

    // let's start the real work

    int contains[n];
    int contained[n];
    memset(contains, 0, sizeof contains);
    memset(contained, 0, sizeof contained);

    for (auto [lr, type, rl, i]: edges) {
        rl *= -1;
        if (type == -1) {
            rsg.relative_update(rl, -1);
            contains[i] = rsg.query(lr, rl);
        } else {
            lsg.relative_update(rl, -1);
            contained[i] = lsg.query(0, rl);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld ", contains[i]);
    puts("");
    for (int i = 0; i < n; i++)
        printf("%lld ", contained[i]);
    puts("");

    return 0;
}
