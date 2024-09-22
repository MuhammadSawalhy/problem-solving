// ﷽
// https://codeforces.com/contest/2001/problem/D

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
#define pii pair<int, int>
#define vvi vector<vector<int>>
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
    long long sum = 0, mn = 1e18, mx = -1e18;
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
    int value;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(int value, State state) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            value += other.value; // NOTE: merge updates
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        // if (state == forced) other = value;
        // else other += value;
        // other.sum += value.sum * (cnt - 1);
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

    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

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


std::vector<int> findNextSmaller(const std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> result(n, -1); // Initialize result with -1
    std::stack<int> s;              // Stack to store indices

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

std::vector<int> findNextGreater(const std::vector<int> &arr) {
    int n = arr.size();
    std::vector<int> result(n, -1); // Initialize result with -1
    std::stack<int> s;              // Stack to store indices

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;

    auto sm = findNextSmaller(a);
    auto gt = findNextGreater(a);

    map<int, int> last;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }

    vector<bool> taken(n + 1, false);

    for (int i = 0, state = 0; i < n; i++) {
        if (taken[a[i]]) continue;

        while (ans.size()) {
            int x = ans.back();
            if (last[x] < i) break;

            state = ans.size() & 1;
            if (state == 1) {
                // maximize
                if (x < a[i]) {
                    taken[x] = false;
                    ans.pop_back();
                } else if (ans.size() >= 2) {
                    // minimize
                    int y = ans.end()[-2];
                    if (last[y] >= i && last[x] >= i && y > a[i]) {
                        taken[x] = taken[y] = false;
                        ans.pop_back(), ans.pop_back();
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            } else {
                // minimize
                if (x > a[i]) {
                    taken[x] = false;
                    ans.pop_back();
                } else if (ans.size() >= 2) {
                    // maximize
                    int y = ans.end()[-2];
                    if (last[y] >= i && last[x] >= i && y < a[i]) {
                        taken[x] = taken[y] = false;
                        ans.pop_back(), ans.pop_back();
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }

        ans.push_back(a[i]);
        taken[a[i]] = true;
    }

    cout << sz(ans) << endl;
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     set<int> as;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         as.insert(a[i]);
//     }
//
//     cout << as.size() << endl;
//
//     vector<int> f, s;
//     set<int> ss;
//     int lastf = -1, lasts = -1;
//     for (int i = n - 1; i >= 0; i--) {
//         // a[i] not included -> must include
//         if (!ss.count(a[i])) {
//             f.push_back(a[i]);
//             s.push_back(a[i]);
//             lasts = lastf = a[i];
//             ss.insert(a[i]);
//             continue;
//         }
//
//
//         // a[i] included -> is it better to use here?
//         // a[i] included -> is included in both f and s
//         {
//             if (a[i] < lastf) {
//                 f.push_back(a[i]);
//                 lastf = a[i];
//             } else if (a[i] > lastf) {
//                 f.push_back(-1);
//             } else {
//
//             }
//         }
//         {
//             if (a[i] > lasts) {
//                 s.push_back(a[i]);
//                 lasts = a[i];
//             } else if (a[i] < lasts) {
//                 s.push_back(-1);
//             } else {
//
//             }
//         }
//     }
//
//     reverse(all(s));
//     reverse(all(f));
//     assert(sz(s) == sz(f));
//
//     debug(n);
//     debug(a);
//     debug(f);
//     debug(s);
//
//     set<int> anss;
//     for (int i = 0; i < sz(s); i++) {
//         if (s[i] == -1) continue;
//         int x = s[i];
//         swap(f, s);
//         if (anss.count(x)) continue;
//         anss.insert(x);
//         cout << x << ' ';
//     }
//     cout << endl;
// }

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
