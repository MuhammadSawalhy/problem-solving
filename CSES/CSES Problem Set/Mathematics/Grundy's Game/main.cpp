// ﷽
// https://cses.fi/problemset/task/2207

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

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int N = 101 * 101;
vi g(N);

void solve() {
    int n;
    cin >> n;
    if (n  < N) {
        if (g[n] == 0) {
            cout << "second\n";
            return;
        }
    }

    cout << "first\n";
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


    g[0] = 0;
    g[1] = 0;
    g[2] = 0;

    for (int i = 3; i < N; i++) {
        vi vals;
        for (int j = 1; j < (i + 1) / 2; j++) {
            vals.push_back(g[j] ^ g[i - j]);
        }
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        while (g[i] < vals.size() && vals[g[i]] == g[i]) g[i]++;
        if (g[i] == 0) debug(i);
    }

    debug(g);
    int mx = *max_element(all(g));
    int j;
    for (j = sz(g) - 1; j >= 0; j--) if (g[j] == mx) break;
    debug(j, g[j]);
    debug(find(all(g), 50) - g.begin());

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
