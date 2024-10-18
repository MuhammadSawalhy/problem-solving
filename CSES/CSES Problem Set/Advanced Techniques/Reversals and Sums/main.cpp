// ﷽
// https://cses.fi/problemset/task/2072

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

struct Node {
    int prior, value, cnt, sum;
    bool rev;
    Node *l = nullptr, *r = nullptr;

    Node(int val) {
        prior = rand(), rev = false, cnt = 1, value = sum = val;
    }
};

inline int cnt(Node *it) { return it ? it->cnt : 0; }
inline int sum(Node *it) { return it ? it->sum : 0; }

void pull(Node *it) {
    if (it) it->cnt = cnt(it->l) + cnt(it->r) + 1,
            it->sum = sum(it->l) + sum(it->r) + it->value;
}

void push(Node *it) {
    if (it && it->rev) {
        it->rev = false;
        swap(it->l, it->r);
        if (it->l) it->l->rev ^= true;
        if (it->r) it->r->rev ^= true;
    }
}

void merge(Node *&t, Node *l, Node *r) {
    push(l), push(r);
    if (!l || !r) t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    pull(t);
}

void split(Node *t, Node *&l, Node *&r, int key, int add = 0) {
    if (!t) return void(l = r = nullptr);
    push(t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split(t->l, l, t->l, key, add), r = t;
    else
        split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    pull(t);
}

void rev(Node *t, int l, int r) {
    Node *t1, *t2, *t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    merge(t, t1, t2);
    merge(t, t, t3);
}

Node *get_index(Node *t, int i) {
    if (!t) return nullptr;
    push(t);
    if (cnt(t->l) == i) return t;
    if (cnt(t->l) > i) return get_index(t->l, i);
    return get_index(t->r, i - cnt(t->l) - 1);
}

void solve() {
    int n, q;
    cin >> n >> q;

    Node *t = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        merge(t, t, new Node{x});
    }

    while (q--) {
        int tt, l, r;
        cin >> tt >> l >> r, l--, r--;
        if (tt == 1) {
            rev(t, l, r);
        } else {
            Node *t1, *t2, *t3;
            split(t, t1, t2, l);
            split(t2, t2, t3, r - l + 1);
            cout << sum(t2) << '\n';
            merge(t, t1, t2);
            merge(t, t, t3);
        }
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}

