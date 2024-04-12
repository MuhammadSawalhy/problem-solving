// ﷽
// https://codeforces.com/contest/1400/problem/F

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1001, M = 15000;
int dp[N][M];
vector<string> dict;
string s;
int x;

void dfs(int rem, string &s) {
    if (rem == 0) {
        bool ok = true;
        for (int i = 0; i < sz(s); i++) {
            int val = 0;
            for (int j = i; j < sz(s); j++) {
                val += s[j] - '0';
                if (x % val == 0 && val < x) {
                    ok = false;
                }
            }
        }
        if (ok) dict.push_back(s);
        return;
    }
    for (int i = 1; i <= min(rem, 9ll); i++) {
        s += '0' + i;
        dfs(rem - i, s);
        s.pop_back();
    }
}

struct AhoCorasick {
    static constexpr int K = 10;
    vector<vector<int>> child, id;
    vector<int> fail;

    AhoCorasick() { add_node(); }

    int add_node() {
        id.push_back({}), fail.push_back(0);
        child.push_back(vector<int>(K));
        return child.size() - 1;
    }

    int insert(const string &s, int ind) {
        int cur = 0; // root
        for (auto c: s) {
            if (child[cur][c - '0'] == 0)
                child[cur][c - '0'] = add_node();
            cur = child[cur][c - '0'];
        }
        id[cur].push_back(ind);
        return cur;
    }

    int go(int cur, int nxt) {
        while (cur && !child[cur][nxt]) cur = fail[cur];
        return child[cur][nxt];
    }

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
    cin >> s >> x;
    int n = sz(s);

    string temp;
    dfs(x, temp);

    AhoCorasick ac;
    for (int i = 0; i < sz(dict); i++) ac.insert(dict[i], i);
    ac.build();

    memset(dp, '?', sizeof dp);

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(ac.child); j++) {
            bool invalid = false;
            int k = ac.go(j, s[i] - '0');
            int temp = k;
            while (temp) {
                invalid |= ac.id[temp].size();
                temp = ac.fail[temp];
            }

            if (!invalid) {
                // take the current char
                minit(dp[i + 1][k], dp[i][j]);
            }

            minit(dp[i + 1][j], dp[i][j] + 1);
        }
    }

    int ans = 1e9;
    for (int j = 0; j < 15000; j++) minit(ans, dp[n][j]);
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
