// ﷽
// https://cses.fi/problemset/task/1737
// CSES -> CSES Problem Set -> Range Queries and Copies

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

    // PersistentSegtree() = default;
    // PersistentSegtree(Node *root) : root(root){};

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
        if (x <= mid) {
            return new Node(update(x, value, left, l, mid), right);
        } else {
            return new Node(left, update(x, value, right, mid + 1, r));
        }
    }

    long long query(int L, int R, Node *node, int l, int r) {
        if (!node || L > r || R < l) return DEFAULT;
        if (L <= l && r <= R) return node->value;
        int mid = l + (r - l) / 2;
        return query(L, R, node->l, l, mid) + query(L, R, node->r, mid + 1, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<PersistentSegtree> sg(1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sg[0].update(i, x);
    }

    for (int i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k, k--;
        if (t == 1) {
            int a, x;
            cin >> a >> x, a--;
            sg[k].update(a, x);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r, l--, r--;
            cout << sg[k].query(l, r) << '\n';
        } else {
            sg.push_back(sg[k]);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
