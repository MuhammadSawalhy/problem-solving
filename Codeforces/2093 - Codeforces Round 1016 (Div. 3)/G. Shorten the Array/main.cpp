#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void brute() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int ans = 1; ans <= n; ans++) {
        bool ok = false;
        for (int i = 0; i + ans - 1 < n; i++) {
            int j = i + ans - 1;
            ok |= (a[i] ^ a[j]) >= k;
        }
        if (ok)
            return void(cout << ans << endl);
    }
    cout << -1 << endl;
}

struct Trie {
    vector<vector<int>> child;
    vector<int> maxind;

    Trie() {
        add_node();
    }

    int add_node() {
        maxind.push_back(-1);
        child.push_back(vector<int>(2));
        return maxind.size() - 1;
    }

    void insert(int x, int ind) {
        int cur = 0; // root
        maxind[cur] = max(maxind[cur], ind);
        for (int b = 31; ~b; b--) {
            int c = (x >> b) & 1;
            if (child[cur][c] == 0)
                child[cur][c] = add_node();
            cur = child[cur][c];
            maxind[cur] = max(maxind[cur], ind);
        }
    }

    int get_val(int x, int k) {
        int ans = -1;
        int cur = 0;
        debug(x, k);
        for (int b = 31; ~b; b--) {
            int xi = (x >> b) & 1;
            int ki = (k >> b) & 1;
            if (ki == 0 && child[cur][xi ^ 1]) {
                ans = max(ans, maxind[child[cur][xi ^ ki ^ 1]]);
            }
            debug(b, xi, ki, ans);
            cur = child[cur][xi ^ ki];
            if (cur == 0) break;
        }
        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    Trie t;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == 0) {
        cout << 1 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        t.insert(a[i], i);
        int j = t.get_val(a[i], k - 1);
        debug(i, j);
        if (~j) ans = min(ans, i - j + 1);
    }

    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
