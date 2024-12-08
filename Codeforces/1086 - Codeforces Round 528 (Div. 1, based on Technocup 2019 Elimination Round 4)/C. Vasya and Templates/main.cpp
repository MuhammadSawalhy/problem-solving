// ﷽
// https://codeforces.com/problemset/problem/1086/C

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
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

int k, n;
string s, a, b;
char ans[27];
bool used[27];

bool dfs(int i, bool isa, bool isb) {
    debug(i, isa, isb);
    debug(s[i], ans[s[i]-'a'], a[i], b[i]);
    if (!isa && !isb) return true;
    if (i == n) return true;

    if (ans[s[i] - 'a'] == '*') {
        debug(a[i] - 'a', b[i] - 'a');
        for (int c = (isa ? a[i] - 'a' : 0); c <= ( isb ? b[i] - 'a' : k - 1); c++) {
            debug(c);
            if (used[c]) continue;
            debug(c);
            ans[s[i] - 'a'] = 'a' + c;
            used[c] = true;
            if (dfs(i + 1, isa && c == a[i] - 'a', isb && c == b[i] - 'a')) return true;
            used[c] = false;
            ans[s[i] - 'a'] = '*';
        }
    }

    debug(ans[s[i] - 'a']);
    if (ans[s[i] - 'a'] == '*' || ans[s[i] - 'a'] < a[i] && isa || ans[s[i] - 'a'] > b[i] && isb) return false;
    return dfs(i + 1, isa && ans[s[i] - 'a'] == a[i], isb && ans[s[i] - 'a'] == b[i]);
}

void solve() {
    cin >> k;
    cin >> s >> a >> b;
    n = s.size();

    memset(ans, '*', sizeof ans);
    memset(used, 0, sizeof used);
    ans[k] = '\0';

    if (!dfs(0, true, true)) {
        cout << "NO\n";
        return;
    }

    for (int i = 0, j = 0; i < k; i++) {
        while (j < k && used[j]) debug(j, used[j]), j++;
        if (ans[i] == '*') {
            ans[i] = 'a' + j;
            used[j] = true;
        }
    }

    cout << "YES\n";
    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
