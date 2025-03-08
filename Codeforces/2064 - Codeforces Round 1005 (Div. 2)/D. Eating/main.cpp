#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


const int N = 2e5 + 5, M = 31;
int ans[N];
int n, q;

struct Trie {
    vector<vector<int>> child, ind;
    vector<int> suf;

    Trie() { add_node(); }

    int add_node() {
        suf.push_back(-1);
        ind.push_back({});
        child.push_back(vector<int>(2));
        return child.size() - 1;
    }

    void insert(const bitset<M> &s, int id) {
        int cur = 0; // root
        for (int i = M - 1; i >= 0; i--) {
            int c = s[i];
            if (child[cur][c] == 0)
                child[cur][c] = add_node();
            cur = child[cur][c];
            ind[cur].push_back(id);
        }
    }

    void doprune(int cur, int id) {
        if (cur == 0) return;
        if (suf[cur] != -1) return;
        suf[cur] = id;
    }

    bool isvalid(int cur) {
        return cur > 0 && suf[cur] == -1;
    }

    void prune(bitset<M> s, bitset<M> a, int id) {
        int cur = 0;
        debug(id, s.to_ullong());
        for (int i = M - 1; i >= 0; i--) {
            debug(i, cur, s[i], a[i]);
            if (s[i] == 0) {
                if (a[i] == 0) {
                    cur = child[cur][0];
                    if (!isvalid(cur)) break;
                } else {
                    doprune(child[cur][0], id);
                    cur = child[cur][1];
                    if (!isvalid(cur)) break;
                }
            } else {
                if (a[i] == 0) {
                    cur = child[cur][1];
                    if (!isvalid(cur)) break;
                } else {
                    doprune(child[cur][1], id);
                    cur = child[cur][0];
                    if (!isvalid(cur)) break;
                }
            }
        }
    }

    void compute_ans(int cur, int mx) {
        mx = max(mx, suf[cur]);
        for (auto id: ind[cur]) {
            ans[id] = n - mx - 1;
        }
        for (auto c: child[cur]) {
            if (c == 0) continue;
            compute_ans(c, mx);
        }
    }
};


void solve() {
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Trie t;
    for (int i = 0, x; i < q; i++) {
        cin >> x;
        debug(x);
        t.insert(x, i);
    }

    for (int i = n - 1, s = 0; i >= 0; i--) {
        t.prune(s, a[i], i);
        s ^= a[i];
    }

    t.compute_ans(0, -1);

    for (int i = 0; i < q; i++) cout << ans[i] << " \n"[i == q - 1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("---------------", t);
        solve();
    }

    return 0;
}
