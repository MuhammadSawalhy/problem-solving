// ﷽
// https://atcoder.jp/contests/abc371/tasks/abc371_d

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int MIN = -(1 << 30), MAX = (1 << 30) - 1;
const int DEFAULT = 0;

struct Node {
    long long value = DEFAULT;
    Node *l = nullptr, *r = nullptr;
    Node() = default;
    Node(Node *l, Node *r) : l(l), r(r) {
        if (l) value += l->value;
        if (r) value += r->value;
    }
};

struct PersistentSegtree {
    Node *root = nullptr;

    Node *update(int x, long long value) {
        return root = update(x, value, root, MIN, MAX);
    }

    long long query(int L, int R) {
        return query(L, R, root, MIN, MAX);
    }

private:
    Node *update(int x, long long value, Node *node, int l, int r) {
        if (l == r) {
            assert(l == x);
            Node *ret = new Node();
            ret->value = value;
            return ret;
        }

        int mid = l + (r - l) / 2;
        Node *left = node ? node->l : nullptr;
        Node *right = node ? node->r : nullptr;
        if (x <= mid) return new Node(update(x, value, left, l, mid), right);
        else return new Node(left, update(x, value, right, mid + 1, r));
    }

    long long query(int L, int R, Node *node, int l, int r) {
        if (!node || L > r || R < l) return DEFAULT;
        if (L <= l && r <= R) return node->value;
        int mid = l + (r - l) / 2;
        return query(L, R, node->l, l, mid) + query(L, R, node->r, mid + 1, r);
    }
};

void solve() {
    int n;
    cin >> n;
    int x[n], p[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    PersistentSegtree seg;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        seg.update(x[i], p[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        debug(l, r);

        cout << seg.query(l, r) << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
