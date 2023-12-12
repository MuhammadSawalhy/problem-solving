// ﷽
// https://codeforces.com/contest/1902/problem/E

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
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

struct Trie {
    vector<vector<int>> child;
    vector<int> count;

    Trie() {
        add_node();
    }

    void add_node() {
        count.push_back(0);
        child.push_back(vector<int>(26));
    }

    void insert(const string &s) {
        int cur = 0; // root
        for (auto c: s) {
            if (child[cur][c - 'a'] == 0) {
                child[cur][c - 'a'] = child.size();
                add_node();
            }
            cur = child[cur][c - 'a'];
            count[cur]++;
        }
    }

    int compute(const string &s) {
        int cur = 0;
        int ans = 0;
        for (auto c: s) {
            cur = child[cur][c - 'a'];
            if (cur == 0) break;
            ans -= 2 * count[cur];
        }
        return ans;
    }
};

Trie root;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    string s[n];
    int lensum = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        lensum += s[i].size();
        root.insert(s[i]);
    }

    ll ans = 1LL * lensum * 2 * n;

    for (int i = 0; i < n; i++) {
        reverse(all(s[i]));
        ans += root.compute(s[i]);
    }

    cout << ans << endl;

    return 0;
}

