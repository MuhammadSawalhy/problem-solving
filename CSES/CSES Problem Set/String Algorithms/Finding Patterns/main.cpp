// ﷽
// https://cses.fi/problemset/task/2102

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct AhoCorasick {
    static constexpr int K = 100;
    vector<vector<int>> child, id;
    vector<int> fail;

    AhoCorasick() { add_node(); }

    int add_node() {
        id.push_back({}), fail.push_back(0);
        child.push_back(vector<int>(K));
        return child.size() - 1;
    }

    int insert(const string &s, int s_id) {
        int cur = 0; // root
        for (auto c: s) {
            if (child[cur][c - 'A'] == 0)
                child[cur][c - 'A'] = add_node();
            cur = child[cur][c - 'A'];
        }
        id[cur].push_back(s_id);
        return cur;
    }

    int go(int cur, int nxt) {
        while (cur && !child[cur][nxt]) cur = fail[cur];
        return child[cur][nxt];
    }

    // calculate fail links
    void build() {
        queue<int> q;
        for (int i = 0; i < K; i++)
            if (child[0][i]) q.push(child[0][i]);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt = 0; nxt < K; nxt++) {
                if (!child[cur][nxt]) continue;
                fail[child[cur][nxt]] = go(fail[cur], nxt);
                q.push(child[cur][nxt]);
            }
        }
    }
};

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    string p[n];
    AhoCorasick ac;
    for (int i = 0; i < n; i++) cin >> p[i], ac.insert(p[i], i);
    ac.build();

    vector<bool> found(n, false);
    vector<bool> vis(ac.child.size(), false);
    int cur = 0;
    for (int i = 0; i < sz(s); i++) {
        cur = ac.go(cur, s[i] - 'A');
        int f = cur;
        while (f) {
            if (vis[f]) break;
            vis[f] = true;
            for (int j: ac.id[f]) found[j] = true;
            ac.id[f].clear();
            f = ac.fail[f];
        }
    }

    for (auto x: found) cout << (x ? "YES\n" : "NO\n");
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
