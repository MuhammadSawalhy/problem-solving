// ﷽
// https://cses.fi/problemset/task/2186

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

constexpr int MOD = 1e9 + 7, MOD2 = 998244353;
const int base = rand() % 100 + 31, base2 = rand() % 100 + 31;
int vals[26], val[26];
constexpr int N = 2e5 + 1;


void solve() {
    static char s[N];
    int n = fread(s, sizeof(char), N, stdin) - 1;

    vi v;
    int cnt = 0;
    vi vals(26, -1);

    for (int i = 0; i < n; i++) {
        if (vals[s[i] - 'a'] == -1) {
            vals[s[i] - 'a'] = cnt++;
        }
        v.push_back(vals[s[i] - 'a']);
    }

    int ans = 0;
    unordered_map<int, int> fr;
    fr[0] = 1;

    for (auto x: v) {
        val[x]++;
        int hash = 0, hash2 = 0;
        for (int j = 0; j < cnt; j++) {
            hash = (hash * base + val[0] - val[j] + MOD) % MOD;
            hash2 = (hash2 * base2 + val[0] - val[j] + MOD2) % MOD2;
        }
        hash = (ll) hash << 32 | hash2;
        ans += fr[hash];
        fr[hash]++;
    }

    printf("%lld\n", ans);
}

int32_t main(int32_t argc, char **argv) {
    solve();
    return 0;
}
