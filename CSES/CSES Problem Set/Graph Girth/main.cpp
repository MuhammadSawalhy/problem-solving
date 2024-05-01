// ﷽
// https://cses.fi/problemset/task/1707

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

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    long long sum = 0, mn = 1e18, mx = 0;
    Value() = default;
    Value(ll value) { sum = mn = mx = value; }

    Value &operator+=(const Value &other) {
        sum += other.sum;
        mn = min(mn, other.mn);
        mx = max(mx, other.mx);
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    Value value;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(Value value, State state = forced) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            value += other.value;
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        if (state == forced) other = value;
        else other += value;
        other.sum += value.sum * (cnt - 1);
    }

    Update get(const Node &node) const { return *this; }
};

struct Node {
    int l = -1, r = -1; // [l, r]
    Update up;
    Value value;

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r), value(value){};

    void update(const Update &up) { this->up += up; }

    void apply_update() {
        up.apply_on(value, r - l + 1);
        up.state = Update::idle;
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
        for (int i = n; i < n << 1; i++)
            tree[i].l = tree[i].r = i - n;
        for (int i = n - 1; i > 0; i--)
            tree[i].l = tree[i << 1].l, tree[i].r = tree[i << 1 | 1].r;
    }

    Segtree(const vector<Value> &values) : Segtree(values.size()) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[i + n].value = values[i];
        build();
    }

    void build() {
        for (int i = n - 1; i > 0; --i) pull(i);
    }

    inline Value query(int i) { return query(1, i, i); }
    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, const Update &val) { update(1, i, i, val); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

private:
    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        if (tree[i].up.state != Update::idle) {
            if (i < n) {
                int l = i << 1, r = i << 1 | 1;
                tree[l].update(tree[i].up.get(tree[l]));
                tree[r].update(tree[i].up.get(tree[r]));
            }
            tree[i].apply_update();
        }
    }

    Value query(int i, int l, int r) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value(); // default
        if (l <= tree[i].l && tree[i].r <= r) return tree[i].value;
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Update &up) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].update(up);
            push(i); // to apply the update
            return;
        }
        update(i << 1, l, r, up.get(tree[i << 1]));
        update(i << 1 | 1, l, r, up.get(tree[i << 1 | 1]));
        pull(i);
    }
};

const int N = 2505;
Segtree sg(N);
int D[N], ans = 1e9;
vector<int> adj[N];
vector<int> newadj[N];
bool vis[N];

void dfs(int i, int p) {
    vector<pair<int, int>> sg_updates;
    vector<int> back_nodes;
    multiset<int> back_depths;

    // calc back_nodes
    for (auto j: adj[i]) {
        if (j == p) continue;
        if (D[j] && D[j] < D[i]) {
            // back edge here
            back_nodes.push_back(j);
            back_depths.insert(D[j]);
            newadj[j].push_back(i);
            newadj[i].push_back(j);
        }
    }

    // calc ans
    for (auto j: back_nodes) {
        // get contribution from back_depths and sg
        auto Q = sg.query(D[j], D[i]);
        back_depths.erase(back_depths.find(D[j]));
        // min depth >= D[j]
        auto Q2 = back_depths.lower_bound(D[j]);
        debug(i, j);
        if (Q2 != back_depths.end())
            minit(ans, D[i] - D[j] + 1 - max(Q.mx, D[i] - *Q2 - 1)), debug(*Q2);
        debug(Q.mx);
        minit(ans, D[i] - D[j] + 1 - Q.mx);
        back_depths.insert(D[j]);
    }

    // apply back_nodes
    for (auto j: back_nodes) {
        auto q = sg.query(D[j], D[j]);
        sg_updates.push_back({D[j], q.mx});
        sg.update(D[j], Update(D[i] - D[j] - 1, Update::relative));
    }

    // dfs to children
    for (auto j: adj[i]) {
        if (j == p) continue;
        if (D[j] == 0) {
            D[j] = D[i] + 1;
            dfs(j, i);
        }
    }

    // revert updates
    reverse(all(sg_updates));
    for (auto [d, v]: sg_updates) {
        sg.update(d, Update(v, Update::forced));
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        if (u == v) {
            cout << 1 << endl;
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int iters = 5; iters; iters--) {
        for (int i = 1; i <= n; i++) {
            if (D[i] == 0) {
                D[i] = 1;
                dfs(i, i);
            }
        }

        if (iters == 1) break;

        int j = 0;
        for (int i = 1; i <= n; i++) {
            D[i] = 0;
            adj[i] = newadj[i];
            newadj[i].clear();
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;

    return 0;
}
