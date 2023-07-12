// ﷽
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

const int mod = 1e9 + 7;

using ValueType = int[2][2];

struct CustomValue {
    ValueType value = { { 1, 0 }, { 0, 1 } };

    CustomValue() = default;
    CustomValue(ValueType value) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                this->value[i][j] = value[i][j];
    };

    void relupdate(ll delta, int cnt) { }

    inline CustomValue operator+(const CustomValue &other) const {
        CustomValue ans;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ans.value[i][j] = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ans.value[i][j] = (ans.value[i][j] + 1LL * other.value[i][k] * value[k][j]) % mod;
        return ans;
    }
};

// using Value = ll;
using Value = CustomValue;

struct Node {
    Value value;
    ll relative_update = 0;
    bool pending_update = false;

    Node() = default;
    Node(Value value) : value(value), pending_update(true){};

    static int count_decendents(int node, int tree_size) {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void push(int node, vector<Node> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        if (pending_update) {
            if (left < sz) tree[left] = Node(value);
            if (right < sz) tree[right] = Node(value);
            pending_update = false;
        }

        if (relative_update) {
            value.relupdate(relative_update, count_decendents(node, sz));
            if (left < sz) tree[left].relative_update += relative_update;
            if (right < sz) tree[right].relative_update += relative_update;
            relative_update = 0;
        }
    }
};

struct Segtree {
    int n;
    vector<Node> tree;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node());
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void update(int i, int j, const Value &val) {
        update(1, 0, n - 1, i, j, val);
    }

    void update(int i, const Value &val) {
        update(i, i, val);
    }

    void relative_update(int i, int j, ll val) {
        relative_update(1, 0, n - 1, i, j, val);
    }

    Value query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

private:
    Value query(int i, int l, int r, int L, int R) {
        tree[i].push(i, tree);
        if (R < l || r < L) return Value(); // default
        if (L <= l && r <= R) return tree[i].value;

        int mid = (r + l) >> 1;
        return query(i << 1, l, mid, L, R) + query(i << 1 | 1, mid + 1, r, L, R);
    }

    void update(int i, int l, int r, int L, int R, const Value &val) {
        tree[i].push(i, tree);
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            tree[i] = Node(val);
            tree[i].push(i, tree);
            return;
        }

        int mid = (r + l) >> 1;
        update(i << 1, l, mid, L, R, val);
        update(i << 1 | 1, mid + 1, r, L, R, val);
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void relative_update(int i, int l, int r, int L, int R, ll val) {
        tree[i].push(i, tree);
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            tree[i].relative_update += val;
            tree[i].push(i, tree);
            return;
        }

        int mid = (r + l) >> 1;
        relative_update(i << 1, l, mid, L, R, val);
        relative_update(i << 1 | 1, mid + 1, r, L, R, val);
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }
};

void set_char_value(char c, ValueType val) {
    // H -> happy
    // S -> sad
    // AIOUE (5 vowels) -> toggle
    // Others (19 char) -> nothing
    switch (c) {
        case '?': {
            val[0][0] = 18 + 1;
            val[0][1] = 5 + 1;
            val[1][0] = 5 + 2;
            val[1][1] = 18 + 2;
            break;
        }
        case 'A':
        case 'I':
        case 'O':
        case 'U':
        case 'E': {
            val[0][0] = 0;
            val[0][1] = 1;
            val[1][0] = 1;
            val[1][1] = 0;
            break;
        }
        case 'H': {
            val[0][0] = 1;
            val[0][1] = 1;
            val[1][0] = 0;
            val[1][1] = 0;
            break;
        }
        case 'D':
        case 'S': {
            val[0][0] = 0;
            val[0][1] = 0;
            val[1][0] = 1;
            val[1][1] = 1;
            break;
        }
        default: {
            val[0][0] = 1;
            val[0][1] = 0;
            val[1][0] = 0;
            val[1][1] = 1;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    Segtree sg(n);
    ValueType val;

    for (int i = 0; i < n; i++) {
        set_char_value(s[i], val);
        sg.update(i, val);
    }

    auto get_ans = [&sg, n]() -> int {
        auto ans = sg.query(0, n - 1);
        return ans.value[0][0];
    };

    cout << get_ans() << endl;

    int i;
    char c;
    while (q--) {
        cin >> i >> c, i--;
        set_char_value(c, val);
        sg.update(i, val);
        cout << get_ans() << endl;
    }

    return 0;
}
